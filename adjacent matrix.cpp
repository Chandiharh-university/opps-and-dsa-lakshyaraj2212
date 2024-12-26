#include <iostream>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix; 

public:
    Graph(int v) {
        vertices = v;
        adjMatrix.resize(vertices, std::vector<int>(vertices, 0)); 
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1; 
        } else {
            std::cout << "Invalid edge!" << std::endl;
        }
    }

    void display() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
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
