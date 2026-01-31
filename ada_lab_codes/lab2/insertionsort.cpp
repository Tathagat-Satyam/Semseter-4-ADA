#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n;
    cout << "no to sort ";
    cin >> n;

    vector<int> arr(n);
    cout << "enetr Numbers: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted List: ";
    for(int x : arr) cout << x << " ";
    
    cout << "\nExecution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}