#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int start);
    void DFSUtil(int v, vector<bool>& visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true; 
    cout << v << " "; 

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false); 
    DFSUtil(start, visited);
}

int main() {
    Graph g(5); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    cout << "Depth-First Search starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}
