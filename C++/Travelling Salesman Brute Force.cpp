#include <iostream>
#include <vector>
#include <algorithm>

int calculateCost(std::vector<std::vector<int>>& graph, std::vector<int>& path) {
    int cost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }
    cost += graph[path.back()][path[0]]; // Return to the starting city
    return cost;
}

int tspBruteForce(std::vector<std::vector<int>>& graph) {
    std::vector<int> path;
    for (int i = 0; i < graph.size(); i++) {
        path.push_back(i);
    }
    
    int minCost = INT_MAX;
    do {
        int cost = calculateCost(graph, path);
        minCost = std::min(minCost, cost);
    } while (std::next_permutation(path.begin() + 1, path.end()));
    
    return minCost;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    std::cout << "Minimum cost: " << tspBruteForce(graph) << std::endl;
    return 0;
}
