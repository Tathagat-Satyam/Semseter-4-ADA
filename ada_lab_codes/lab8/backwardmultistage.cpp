#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int INF = 1e9;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> dist[i][j];

    auto start = high_resolution_clock::now();

    vector<int> bcost(n, 0);
    bcost[n-1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        bcost[i] = INF;
        for (int j = i + 1; j < n; j++) {
            if (dist[i][j] != 0 && dist[i][j] + bcost[j] < bcost[i]) {
                bcost[i] = dist[i][j] + bcost[j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Backward Cost: " << bcost[0] << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}