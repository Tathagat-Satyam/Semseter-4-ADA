#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define INF 99999
#define MAX 100

void floydWarshall(int V, int graph[MAX][MAX]) {
    int dist[MAX][MAX];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    auto start = high_resolution_clock::now();

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
}

int main() {
    int V;
    if (!(cin >> V)) return 0;

    int graph[MAX][MAX];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(V, graph);

    return 0;
}