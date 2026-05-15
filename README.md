# Assignment 3: Dijkstra and Floyd-Warshall

Name: Malak Satour  
ID: 900241965

## Project Description

This project implements shortest path algorithms for a weighted directed graph:

- `dijkstra(int src)`: computes shortest paths from one source vertex to every other vertex.
- `repeatedDijkstra()`: computes all-pairs shortest paths by running Dijkstra from every vertex.
- `floydWarshall()`: computes all-pairs shortest paths using dynamic programming.

The graph uses zero-based vertex numbering. Unreachable paths are represented by `Graph::INF`.

## Input File Format

Graph files use this format:

```text
number_of_vertices number_of_edges
from_vertex to_vertex weight
from_vertex to_vertex weight
...
```

Example:

```text
5 6
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
```

## How to Build and Run

```bash
cmake -S . -B build
cmake --build build
./build/assignment_3_demo
```

If CMake is not installed, use the included Makefile:

```bash
make run
```

## How to Run Tests

GoogleTest cases are in `Googletests/Testcases.cpp`.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

If CMake reports that GoogleTest is missing, install GoogleTest or copy the `Code` files into the course-provided project that already includes GoogleTest.

## Assumptions and Notes

- The graph is directed.
- Edge weights are non-negative because Dijkstra's algorithm requires non-negative weights.
- Vertices are indexed from `0` to `n - 1`.
- `Graph::INF` means no path exists between two vertices.
