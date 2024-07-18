#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adjList;

    void BFSUtil(int start, vector<bool> &visited) {
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
                if (!visited[*i]) { //*i here is not an index of the list but *i dereferences the value and puts the value to be visited
                    visited[*i] = true;
                    q.push(*i);
                }
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

    void BFS(int start) {
        vector<bool> visited(V, false);
        BFSUtil(start, visited);
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

    cout << "BFS starting from vertex 0:" << endl;
    g.BFS(4);

    return 0;
}
