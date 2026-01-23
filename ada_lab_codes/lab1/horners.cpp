#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int horner(int poly[], int n, int x) 
{ 
    int result = poly[0];
    for (int i = 1; i < n; i++) 
        result = result * x + poly[i]; 
    return result; 
} 

int main() 
{ 
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    
    int poly[n + 1]; 
    cout << "Enter " << n + 1 << " coefficients (from highest degree to constant): ";
    for(int i = 0; i <= n; i++) {
        cin >> poly[i];
    }
    
    int x;
    cout << "Enter value of x: ";
    cin >> x;
    
    auto start = steady_clock::now();
    
    int result = horner(poly, n + 1, x);
    
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Value of polynomial is " << result << endl;
    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;
    
    return 0;
}