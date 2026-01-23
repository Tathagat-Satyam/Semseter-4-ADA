#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }

    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        int curr = arr[i];
        while (curr + 1 < arr[i + 1]) {
            cout << curr + 1 << "\n";
            curr++; 
            found = 1;
        }
    }

    if (!found) cout << "No missing number" << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}