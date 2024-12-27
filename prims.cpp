#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int findMinKeyVertex(vector<int>& key, vector<bool>& inMST, int V) {
    int minKey = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}
void printMST(vector<int>& parent, vector<vector<int>>& graph, int V) {
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primsAlgorithm(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);        
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;      
    parent[0] = -1;  

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(key, inMST, V); 
        inMST[u] = true;                      
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primsAlgorithm(graph, V);

    return 0;
}
