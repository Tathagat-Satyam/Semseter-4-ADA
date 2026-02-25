#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class MatrixMultiplier {
private:
    // Helper function to find next power of 2
    int nextPowerOfTwo(int n) {
        int power = 1;
        while (power < n) {
            power <<= 1;
        }
        return power;
    }
    
    // Pad matrix to specified size
    vector<vector<int>> padMatrix(const vector<vector<int>>& matrix, int newSize) {
        int oldSize = matrix.size();
        vector<vector<int>> padded(newSize, vector<int>(newSize, 0));
        
        for (int i = 0; i < oldSize; i++) {
            for (int j = 0; j < oldSize; j++) {
                padded[i][j] = matrix[i][j];
            }
        }
        
        return padded;
    }
    
    // Unpad matrix back to original size
    vector<vector<int>> unpadMatrix(const vector<vector<int>>& matrix, int originalSize) {
        vector<vector<int>> result(originalSize, vector<int>(originalSize));
        
        for (int i = 0; i < originalSize; i++) {
            for (int j = 0; j < originalSize; j++) {
                result[i][j] = matrix[i][j];
            }
        }
        
        return result;
    }
    
    vector<vector<int>> addMatrix(const vector<vector<int>>& A, 
                                   const vector<vector<int>>& B) {
        int n = A.size();
        vector<vector<int>> result(n, vector<int>(n));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                result[i][j] = A[i][j] + B[i][j];
        
        return result;
    }
    
    void splitMatrix(const vector<vector<int>>& parent, 
                     vector<vector<int>>& child11, 
                     vector<vector<int>>& child12,
                     vector<vector<int>>& child21, 
                     vector<vector<int>>& child22) {
        int n = parent.size();
        int mid = n / 2;
        
        child11.resize(mid, vector<int>(mid));
        child12.resize(mid, vector<int>(mid));
        child21.resize(mid, vector<int>(mid));
        child22.resize(mid, vector<int>(mid));
        
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                child11[i][j] = parent[i][j];
                child12[i][j] = parent[i][j + mid];
                child21[i][j] = parent[i + mid][j];
                child22[i][j] = parent[i + mid][j + mid];
            }
        }
    }
    
    vector<vector<int>> combineMatrices(const vector<vector<int>>& C11,
                                         const vector<vector<int>>& C12,
                                         const vector<vector<int>>& C21,
                                         const vector<vector<int>>& C22) {
        int mid = C11.size();
        int n = 2 * mid;
        vector<vector<int>> result(n, vector<int>(n));
        
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                result[i][j] = C11[i][j];
                result[i][j + mid] = C12[i][j];
                result[i + mid][j] = C21[i][j];
                result[i + mid][j + mid] = C22[i][j];
            }
        }
        
        return result;
    }
    
    vector<vector<int>> multiplyRecursive(const vector<vector<int>>& A, 
                                           const vector<vector<int>>& B) {
        int n = A.size();
        
        if (n == 1) {
            vector<vector<int>> result(1, vector<int>(1));
            result[0][0] = A[0][0] * B[0][0];
            return result;
        }
        
        vector<vector<int>> A11, A12, A21, A22;
        vector<vector<int>> B11, B12, B21, B22;
        
        splitMatrix(A, A11, A12, A21, A22);
        splitMatrix(B, B11, B12, B21, B22);
        
        vector<vector<int>> C11 = addMatrix(multiplyRecursive(A11, B11),
                                             multiplyRecursive(A12, B21));
        vector<vector<int>> C12 = addMatrix(multiplyRecursive(A11, B12),
                                             multiplyRecursive(A12, B22));
        vector<vector<int>> C21 = addMatrix(multiplyRecursive(A21, B11),
                                             multiplyRecursive(A22, B21));
        vector<vector<int>> C22 = addMatrix(multiplyRecursive(A21, B12),
                                             multiplyRecursive(A22, B22));
        
        return combineMatrices(C11, C12, C21, C22);
    }
    
public:
    vector<vector<int>> multiply(const vector<vector<int>>& A, 
                                   const vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        
        // Check if matrices can be multiplied
        if (n == 0 || m == 0 || A[0].size() != m) {
            throw invalid_argument("Invalid matrix dimensions for multiplication");
        }
        
        // Check if size is power of 2
        if ((n & (n - 1)) != 0) {
            int newSize = nextPowerOfTwo(n);
            vector<vector<int>> A_padded = padMatrix(A, newSize);
            vector<vector<int>> B_padded = padMatrix(B, newSize);
            
            vector<vector<int>> result_padded = multiplyRecursive(A_padded, B_padded);
            return unpadMatrix(result_padded, n);
        }
        
        return multiplyRecursive(A, B);
    }
};

// Function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    MatrixMultiplier multiplier;
    
    // Example 1: 2x2 matrices
    cout << "Example 1: 2x2 Matrices" << endl;
    vector<vector<int>> A1 = {{1, 2}, {3, 4}};
    vector<vector<int>> B1 = {{5, 6}, {7, 8}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A1);
    cout << "\nMatrix B:" << endl;
    printMatrix(B1);
    
    vector<vector<int>> result1 = multiplier.multiply(A1, B1);
    cout << "\nResult:" << endl;
    printMatrix(result1);
    
    // Example 2: 3x3 matrices (not power of 2)
    cout << "\n\nExample 2: 3x3 Matrices (Not Power of 2)" << endl;
    cout << "========================================" << endl;
    vector<vector<int>> A2 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
    vector<vector<int>> B2 = {{9, 8, 7},
                              {6, 5, 4},
                              {3, 2, 1}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A2);
    cout << "\nMatrix B:" << endl;
    printMatrix(B2);
    
    vector<vector<int>> result2 = multiplier.multiply(A2, B2);
    cout << "\nResult:" << endl;
    printMatrix(result2);
    
    // Example 3: 4x4 matrices
    cout << "\n\nExample 3: 4x4 Matrices" << endl;
    cout << "========================" << endl;
    vector<vector<int>> A3 = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}};
    vector<vector<int>> B3 = {{16, 15, 14, 13},
                              {12, 11, 10, 9},
                              {8, 7, 6, 5},
                              {4, 3, 2, 1}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A3);
    cout << "\nMatrix B:" << endl;
    printMatrix(B3);
    
    vector<vector<int>> result3 = multiplier.multiply(A3, B3);
    cout << "\nResult:" << endl;
    printMatrix(result3);
    
    return 0;
}