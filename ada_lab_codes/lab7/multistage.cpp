#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int INF = 1e9;

int main() {
    int n, stages;
    if (!(cin >> n >> stages)) return 0;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    auto start = high_resolution_clock::now();

    vector<int> cost(n, 0);
    vector<int> path(n, 0);

    cost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        int min_val = INF;
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] + cost[j] < min_val) {
                min_val = graph[i][j] + cost[j];
                path[i] = j;
            }
        }
        cost[i] = min_val;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Shortest path cost: " << cost[0] << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}