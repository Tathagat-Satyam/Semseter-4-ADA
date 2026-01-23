#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto start = high_resolution_clock::now();

    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << "Duplicate number: " << arr[i] << "\n";
                found = 1;
                break;
            }
        }
    }

    if (found == 0) {
        cout << "No duplicate found" << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
