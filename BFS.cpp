#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void Graph::BFS(int start) {
    vector<bool> visited(V, false); 
    queue<int> q; 

    visited[start] = true; 
    q.push(start); 

    while (!q.empty()) {
        int node = q.front();
        cout << node << " "; 
        q.pop(); 

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; 
                q.push(neighbor); 
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "Breadth-First Search starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}
