#include<iostream>
#include<chrono>

using namespace std::chrono;
using namespace std;

int ls(int arr[], int t, int index) {
    if (index == 0) {
        return -1;
    }
    else if (arr[index - 1] == t) { 
        return index - 1;
    }
    return ls(arr, t, index - 1);  
}

int main() {
    int* arr = new int[5];
    cout << "Enter " << 5 << " elements:\n";
    
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    int t;
    cout << "Element to search: ";
    cin >> t;
    
    auto start1 = high_resolution_clock::now();
    int result = ls(arr, t, 5);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1 - start1);
    
    if (result != -1) {
        cout << "Index: " << result << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    
    cout << "Time taken: " << duration1.count() << " nanoseconds" << endl;
    
    delete[] arr;  
    return 0;
}