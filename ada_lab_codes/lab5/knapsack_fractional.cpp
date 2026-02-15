#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, compare);

    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    if (!(cin >> n >> W)) return 0;

    Item arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }

    auto start = high_resolution_clock::now();

    double result = fractionalKnapsack(W, arr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Maximum value: " << result << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}