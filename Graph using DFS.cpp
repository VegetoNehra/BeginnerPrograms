#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adjList;
    /*vector<bool> &visited: This is a reference to a vector of boolean values.
     The visited vector keeps track of whether each vertex has been visited (true) or not (false). 
     The use of a reference (&) means that changes to this vector within the function will affect the original vector passed to the function.*/


    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adjList = vector<list<int>>(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graphs
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
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

    cout << "DFS starting from vertex 0:" << endl;
    g.DFS(0);

    return 0;
}
/*this code first enter the vector with v lists, and then itirates thru each list 
and print each element till and if the element is already visited it goes to next
 element and after printing that element it jumps to that elements list and .....etc*/
