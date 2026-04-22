#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    if (!(cin >> n >> W)) return 0;

    int val[n], wt[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];

    auto start = high_resolution_clock::now();

    int result = knapsack(W, wt, val, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Maximum Value: " << result << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}