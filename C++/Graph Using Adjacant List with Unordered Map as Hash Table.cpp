#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graphs
    }

    /*for: This is a range-based for loop that iterates over all elements in the adjList map.
const auto& pair: Declares the loop variable pair as a constant reference to each element in the adjList map. 
The auto keyword lets the compiler deduce the type of pair, which is std::pair<const int, std::list<int>>.
adjList: The adjacency list map where each key-value pair represents a vertex and its list of adjacent vertices.
*/

    void printList() {
        for (const auto& pair : adjList) {
            cout << "Vertex " << pair.first << ":";
            for (auto v : pair.second) {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }
};
/*for: This is a range-based for loop that iterates over the list of adjacent vertices for the current vertex.
auto v: Declares the loop variable v, which takes the value of each element in the list pair.second. The auto keyword lets the compiler deduce the type of v, which in this case is int.
pair.second: Accesses the value of the current map entry, which is the list of adjacent vertices for the current vertex.
*/

int main() {
    Graph g;

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
