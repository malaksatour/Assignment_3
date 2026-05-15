// Name: Malak Satour
// ID: 900241965

#ifndef ASSIGNMENT_3_GRAPH_H
#define ASSIGNMENT_3_GRAPH_H

#include <string>
#include <utility>
#include <vector>

class Graph {
public:
    static constexpr int INF = 1000000000;

    Graph();
    explicit Graph(int vertices);
    explicit Graph(const std::string& fileName);

    void loadFromFile(const std::string& fileName);
    void addEdge(int from, int to, int weight);

    int vertices() const;
    const std::vector<std::vector<std::pair<int, int>>>& adjacencyList() const;

    std::vector<int> dijkstra(int src) const;
    std::vector<std::vector<int>> repeatedDijkstra() const;
    std::vector<std::vector<int>> floydWarshall() const;

private:
    int vertexCount;
    std::vector<std::vector<std::pair<int, int>>> adjacency;

    void validateVertex(int vertex) const;
};

#endif
