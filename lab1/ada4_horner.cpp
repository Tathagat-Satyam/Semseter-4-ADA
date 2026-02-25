#include <iostream> 
using namespace std; 

int horner(int poly[], int n, int x) 
{ 
    int result = poly[0];

    for (int i=1; i<n; i++) 
        result = result*x + poly[i]; 

    return result; 
} 

int main() 
{ 

  int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    
    int poly[n]; 
    
    cout << "Enter " << n+1 << " coefficients (from highest degree to constant): ";
    for(int i = 0; i <= n; i++) {
        cin >> poly[i];
    }
    
    int x;
    cout << "Enter value of x: ";
    cin >> x;
    
    cout << "Value of polynomial is " << horner(poly, n+1, x) << endl;
    
    return 0;
}