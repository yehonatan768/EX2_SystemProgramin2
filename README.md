# Graph Algorithms

This repository contains implementations of various graph algorithms in C++. These algorithms are designed to work with an adjacency matrix representation of graphs.

## Table of Contents

- [Introduction](#introduction)
- [Algorithms](#algorithms)
- [Usage](#usage)
- [Run](#run)


## Introduction

Graph algorithms are fundamental to computer science and are used in various applications such as network routing, social network analysis, and data mining. This repository provides efficient implementations of several common graph algorithms, including:

- **Is Connected:** Checks if a graph is connected.
- **Contains Cycle:** Determines if a graph contains a cycle.
- **Is Bipartite:** Checks if a graph is bipartite.
- **Shortest Path:** Finds the shortest path between two vertices in a graph.
- **Negative Cycle:** Detects the presence of a negative cycle in a graph.

These algorithms are implemented using C++ and assume an adjacency matrix representation of the input graph.

## Algorithms

### Is Connected

This algorithm determines whether a given graph is connected or not. It uses a Depth-First Search (DFS) approach to traverse the graph and count the number of reachable vertices from a starting vertex.

### Contains Cycle

The Contains Cycle algorithm checks whether a given graph contains a cycle or not. It uses a Depth-First Search (DFS) approach to traverse the graph and detect back edges.

### Is Bipartite

This algorithm checks whether a given graph is bipartite or not. It assigns vertices to two different sets (A and B) such that no two adjacent vertices belong to the same set. It uses a Depth-First Search (DFS) approach to assign vertices to sets.

### Shortest Path

The shortestPath algorithm efficiently computes the shortest path between two vertices in a graph by utilizing a modified Breadth-First Search (BFS) approach.

### Negative Cycle

This algorithm detects the presence of a negative cycle in a graph. It uses the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices and then checks for negative cycles.

## Usage

To use these algorithms, include the appropriate header file (`Algorithms.hpp`) in your C++ project and call the desired function with the graph object as a parameter.

Example usage:

```cpp
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <vector>

using namespace std;
using namespace Algorithms;

int main() {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    cout << isConnected(g) << endl;
    cout << isContainsCycle(g) << endl;
    cout << isBipartite(g) << endl;
    cout << shortestPath(g, 0, 2) << endl;
    cout << negativeCycle(g) << endl;
    return 0;
}
```

## Run
To run this project follow those steps:

- **Enter Terminal**
- **Run "make all" command**
- **Run "./test" or "./demo" command** 
- **Run "make clean" command when finished**
