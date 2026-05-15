// Name: Malak Satour
// ID: 900241965

#include "Graph.h"

#include <fstream>
#include <queue>
#include <stdexcept>

Graph::Graph() : vertexCount(0) {}

Graph::Graph(int vertices) : vertexCount(vertices), adjacency(vertices) {
    if (vertices < 0) {
        throw std::invalid_argument("Number of vertices cannot be negative.");
    }
}

Graph::Graph(const std::string& fileName) : vertexCount(0) {
    loadFromFile(fileName);
}

void Graph::loadFromFile(const std::string& fileName) {
    std::ifstream input(fileName);
    if (!input) {
        throw std::runtime_error("Could not open graph file: " + fileName);
    }

    int vertices;
    int edges;
    input >> vertices >> edges;

    if (!input || vertices < 0 || edges < 0) {
        throw std::runtime_error("Invalid graph header. Expected: vertices edges");
    }

    vertexCount = vertices;
    adjacency.assign(vertexCount, {});

    for (int i = 0; i < edges; ++i) {
        int from;
        int to;
        int weight;
        input >> from >> to >> weight;

        if (!input) {
            throw std::runtime_error("Invalid edge entry in graph file.");
        }

        addEdge(from, to, weight);
    }
}

void Graph::addEdge(int from, int to, int weight) {
    validateVertex(from);
    validateVertex(to);

    if (weight < 0) {
        throw std::invalid_argument("Dijkstra requires non-negative edge weights.");
    }

    adjacency[from].push_back({to, weight});
}

int Graph::vertices() const {
    return vertexCount;
}

const std::vector<std::vector<std::pair<int, int>>>& Graph::adjacencyList() const {
    return adjacency;
}

std::vector<int> Graph::dijkstra(int src) const {
    validateVertex(src);

    std::vector<int> distance(vertexCount, INF);
    distance[src] = 0;

    using QueueItem = std::pair<int, int>;
    std::priority_queue<QueueItem, std::vector<QueueItem>, std::greater<QueueItem>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        const int currentDistance = pq.top().first;
        const int currentVertex = pq.top().second;
        pq.pop();

        if (currentDistance != distance[currentVertex]) {
            continue;
        }

        for (const auto& edge : adjacency[currentVertex]) {
            const int neighbor = edge.first;
            const int weight = edge.second;

            if (distance[currentVertex] <= INF - weight &&
                distance[currentVertex] + weight < distance[neighbor]) {
                distance[neighbor] = distance[currentVertex] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    return distance;
}

std::vector<std::vector<int>> Graph::repeatedDijkstra() const {
    std::vector<std::vector<int>> allPairs(vertexCount);

    for (int source = 0; source < vertexCount; ++source) {
        allPairs[source] = dijkstra(source);
    }

    return allPairs;
}

std::vector<std::vector<int>> Graph::floydWarshall() const {
    std::vector<std::vector<int>> distance(vertexCount, std::vector<int>(vertexCount, INF));

    for (int i = 0; i < vertexCount; ++i) {
        distance[i][i] = 0;
    }

    for (int from = 0; from < vertexCount; ++from) {
        for (const auto& edge : adjacency[from]) {
            const int to = edge.first;
            const int weight = edge.second;
            if (weight < distance[from][to]) {
                distance[from][to] = weight;
            }
        }
    }

    for (int middle = 0; middle < vertexCount; ++middle) {
        for (int from = 0; from < vertexCount; ++from) {
            if (distance[from][middle] == INF) {
                continue;
            }

            for (int to = 0; to < vertexCount; ++to) {
                if (distance[middle][to] == INF) {
                    continue;
                }

                if (distance[from][middle] <= INF - distance[middle][to] &&
                    distance[from][middle] + distance[middle][to] < distance[from][to]) {
                    distance[from][to] = distance[from][middle] + distance[middle][to];
                }
            }
        }
    }

    return distance;
}

void Graph::validateVertex(int vertex) const {
    if (vertex < 0 || vertex >= vertexCount) {
        throw std::out_of_range("Vertex index is out of range.");
    }
}
