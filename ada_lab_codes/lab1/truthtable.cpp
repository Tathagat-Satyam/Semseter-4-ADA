#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    
    int rows = 1;
    for (int i = 0; i < n; i++) {
        rows *= 2;
    }
    
    cout << "Truth table for " << n << " variables:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = n - 1; j >= 0; j--) {
            int bit = (i >> j) & 1;
            cout << bit << " ";
        }
        cout << endl;
    }
    
    return 0;
}