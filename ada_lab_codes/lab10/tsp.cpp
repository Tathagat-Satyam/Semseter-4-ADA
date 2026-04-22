#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX 15
#define INF 999999

int n;
int dist[MAX][MAX];
int memo[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; 
    }

    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return memo[mask][pos] = ans;
}

int main() {
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1;
        }
    }

    auto start = high_resolution_clock::now();

    int result = tsp(1, 0);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Minimum Cost: " << result << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}