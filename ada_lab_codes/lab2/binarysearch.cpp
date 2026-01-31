#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n, target;
    cout << "Array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Sorted numbers: "; 
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "element to find: ";
    cin >> target;

    auto start = high_resolution_clock::now();

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            found = mid;
            break;
        }
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;                
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    if(found != -1) cout << "Number index " << found << " par mila.\n";
    else cout << "Not found\n";
    
    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;
    
    return 0;
}