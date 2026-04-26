#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define V 10

bool isSafe(int v, bool graph[V][V], int color[], int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v, int n) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, n))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    bool graph[V][V];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int color[V];
    for (int i = 0; i < n; i++) color[i] = 0;

    auto start = high_resolution_clock::now();

    bool solved = graphColoringUtil(graph, m, color, 0, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (solved) {
        for (int i = 0; i < n; i++)
            cout << "Node " << i << " -> Color " << color[i] << endl;
    } else {
        cout << "Solution does not exist" << endl;
    }

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}