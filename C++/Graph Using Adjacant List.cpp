#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList = vector<list<int>>(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graphs
    }

    void printList() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            for (auto v : adjList[i]) {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printList();

    return 0;
}
//The auto keyword in C++ is used for type inference. It allows the compiler to automatically 
//deduce the type of a variable from its initializer. This can make the code cleaner and easier to read, 
//especially when dealing with complex types.

//The syntax for (auto v : container) is a range-based for loop, which iterates over each element in 
//a container (like a vector, list, array, etc.). Here, auto deduces the type of each element in the container.