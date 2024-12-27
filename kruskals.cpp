#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalsAlgorithm(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges); 

    DSU dsu(V);
    vector<Edge> mst; 

    for (Edge& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mst.push_back(edge); 
            dsu.unionSets(edge.src, edge.dest); 
        }
    }

    cout << "Edge\tWeight\n";
    for (Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << "\n";
    }
}

int main() {
    int V = 5; 
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalsAlgorithm(edges, V);

    return 0;
}
