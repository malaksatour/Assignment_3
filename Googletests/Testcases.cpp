// Name: Malak Satour
// ID: 900241965

#include "../Code/Graph.h"

#include <gtest/gtest.h>

namespace {

Graph makeSampleGraph() {
    Graph graph(5);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(2, 1, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 3);
    return graph;
}

std::vector<std::vector<int>> expectedSampleApsp() {
    const int inf = Graph::INF;
    return {
        {0, 3, 1, 4, 7},
        {inf, 0, inf, 1, 4},
        {inf, 2, 0, 3, 6},
        {inf, inf, inf, 0, 3},
        {inf, inf, inf, inf, 0},
    };
}

}

TEST(DijkstraTests, ComputesShortestPathsFromSingleSource) {
    Graph graph = makeSampleGraph();

    EXPECT_EQ(graph.dijkstra(0), (std::vector<int>{0, 3, 1, 4, 7}));
}

TEST(DijkstraTests, KeepsUnreachableVerticesAtInf) {
    Graph graph = makeSampleGraph();

    EXPECT_EQ(graph.dijkstra(4), (std::vector<int>{
        Graph::INF, Graph::INF, Graph::INF, Graph::INF, 0
    }));
}

TEST(ApspTests, RepeatedDijkstraBuildsAllPairsMatrix) {
    Graph graph = makeSampleGraph();

    EXPECT_EQ(graph.repeatedDijkstra(), expectedSampleApsp());
}

TEST(ApspTests, FloydWarshallBuildsAllPairsMatrix) {
    Graph graph = makeSampleGraph();

    EXPECT_EQ(graph.floydWarshall(), expectedSampleApsp());
}

TEST(ApspTests, FloydWarshallMatchesRepeatedDijkstra) {
    Graph graph = makeSampleGraph();

    EXPECT_EQ(graph.floydWarshall(), graph.repeatedDijkstra());
}
