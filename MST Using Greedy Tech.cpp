#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    parent[rootX] = rootY;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cout << "Enter edge (u v weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<Edge> result;
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (auto edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            result.push_back(edge);
            unionSets(parent, edge.u, edge.v);
        }
    }

    cout << "Edges in the MST:\n";
    for (auto edge : result) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }
    return 0;
}
