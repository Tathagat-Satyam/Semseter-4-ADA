#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Edge {
    int u, v, weight;
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskals(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DSU dsu(V);
    int mst_weight = 0;
    int edges_count = 0;

    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.weight;
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
            edges_count++;
        }
        if (edges_count == V - 1) break;
    }
    cout << "Total MST Weight: " << mst_weight << endl;
}

int main() {
    int V, E;
    if (!(cin >> V >> E)) return 0;
    
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    auto start = high_resolution_clock::now();

    kruskals(V, edges);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}