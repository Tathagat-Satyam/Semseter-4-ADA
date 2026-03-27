#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool isCyclic(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v] && isCyclic(v, adj, visited, recStack)) return true;
        else if (recStack[v]) return true;
    }

    recStack[u] = false;
    return false;
}

int main() {
    int V, E;
    if (!(cin >> V >> E)) return 0;
    
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    auto start = high_resolution_clock::now();

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    bool cycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclic(i, adj, visited, recStack)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle) cout << "Graph contains cycle" << endl;
    else cout << "No cycle in graph" << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}