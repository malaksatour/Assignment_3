// Name: Malak Satour
// ID: 900241965

#include "Code/Graph.h"

#include <iostream>
#include <vector>

void printDistances(const std::vector<int>& distances) {
    for (int distance : distances) {
        if (distance == Graph::INF) {
            std::cout << "INF ";
        } else {
            std::cout << distance << ' ';
        }
    }
    std::cout << '\n';
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        printDistances(row);
    }
}

int main() {
    Graph graph("data/sample_graph.txt");

    std::cout << "Dijkstra from vertex 0:\n";
    printDistances(graph.dijkstra(0));

    std::cout << "\nRepeated Dijkstra APSP:\n";
    printMatrix(graph.repeatedDijkstra());

    std::cout << "\nFloyd-Warshall APSP:\n";
    printMatrix(graph.floydWarshall());

    return 0;
}
