#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    int vertices; 
    std::vector<std::list<int>> adjList; 
public:
    Graph(int v) {
        vertices = v;
        adjList.resize(vertices); 
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjList[src].push_back(dest);  
        } else {
            std::cout << "Invalid edge!" << std::endl;
        }
    }

    void display() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < vertices; i++) {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i]) {
                std::cout << " -> " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numVertices = 5; 
    Graph g(numVertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    return 0;
}
