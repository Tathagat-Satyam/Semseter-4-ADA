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

    vector<int> fcost(n, 0);
    for (int i = 1; i < n; i++) {
        fcost[i] = INF;
        for (int j = 0; j < i; j++) {
            if (dist[j][i] != 0 && fcost[j] + dist[j][i] < fcost[i]) {
                fcost[i] = fcost[j] + dist[j][i];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Forward Cost: " << fcost[n-1] << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}