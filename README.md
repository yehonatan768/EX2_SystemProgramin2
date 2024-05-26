# Graph Algorithms

This repository contains implementations of various graph algorithms in C++. These algorithms are designed to work with an adjacency matrix representation of graphs.

## Table of Contents

- [Introduction](#introduction)
- [Graph Class Functions](#graph-class-functions)
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

## Graph Class Functions

The `Graph` class provides a comprehensive set of functions to manage and manipulate graphs using adjacency matrices. Below are the functions implemented in `Graph.cpp` along with their explanations:

### Loading and Printing the Graph

- **`void loadGraph(const std::vector<std::vector<int>>& graph)`**
  - Loads the graph from an adjacency matrix. Throws an exception if the matrix is not square.

- **`std::string printGraph() const`**
  - Returns a string representation of the graph in matrix form.

- **`std::vector<std::vector<int>> setMatrix() const`**
  - Returns the adjacency matrix of the graph.

### Graph Operators

- **`Graph operator+(const Graph& other) const`**
  - Returns a new graph which is the sum of two graphs. Throws an exception if the sizes do not match.

- **`Graph& operator+=(const Graph& other)`**
  - Adds another graph to the current graph. Throws an exception if the sizes do not match.

- **`Graph operator+() const`**
  - Returns a copy of the current graph.

- **`Graph operator-(const Graph& other) const`**
  - Returns a new graph which is the difference of two graphs. Throws an exception if the sizes do not match.

- **`Graph& operator-=(const Graph& other)`**
  - Subtracts another graph from the current graph. Throws an exception if the sizes do not match.

- **`Graph operator-() const`**
  - Returns a new graph which is the negation of the current graph.

- **`bool operator>(const Graph& other) const`**
  - Compares two graphs to determine if the current graph is greater than the other graph.

- **`bool operator<(const Graph& other) const`**
  - Compares two graphs to determine if the current graph is less than the other graph.

- **`bool operator==(const Graph& other) const`**
  - Checks if two graphs are equal.

- **`bool operator!=(const Graph& other) const`**
  - Checks if two graphs are not equal.

- **`bool operator>=(const Graph& other) const`**
  - Checks if the current graph is greater than or equal to the other graph.

- **`bool operator<=(const Graph& other) const`**
  - Checks if the current graph is less than or equal to the other graph.

- **`Graph& operator++()`**
  - Pre-increment operator. Increments all elements of the graph by 1.

- **`Graph operator++(int)`**
  - Post-increment operator. Increments all elements of the graph by 1 and returns the original graph.

- **`Graph& operator--()`**
  - Pre-decrement operator. Decrements all elements of the graph by 1.

- **`Graph operator--(int)`**
  - Post-decrement operator. Decrements all elements of the graph by 1 and returns the original graph.

- **`Graph operator*(int scalar) const`**
  - Multiplies all elements of the graph by a scalar and returns the resulting graph.

- **`Graph& operator*=(int scalar)`**
  - Multiplies all elements of the current graph by a scalar.

- **`Graph operator*(const Graph& other) const`**
  - Multiplies two graphs (matrix multiplication). Throws an exception if the sizes do not match.

- **`Graph& operator*=(const Graph& other)`**
  - Multiplies the current graph by another graph (matrix multiplication). Throws an exception if the sizes do not match.

### Utility Functions

- **`int countEdges(const std::vector<std::vector<int>>& matrix) const`**
  - Counts the number of edges in the graph represented by the adjacency matrix.

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
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);
    
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(graph2);
    
    // Print the graphs
    cout << "Graph 1:" << endl;
    cout << g1.printGraph() << endl;

    cout << "Graph 2:" << endl;
    cout << g2.printGraph() << endl;

    // Add the graphs
    Graph g3 = g1 + g2;
    cout << "Graph 1 + Graph 2:" << endl;
    cout << g3.printGraph() << endl;

    // Subtract the graphs
    Graph g4 = g1 - g2;
    cout << "Graph 1 - Graph 2:" << endl;
    cout << g4.printGraph() << endl;

    // Negate a graph
    Graph g5 = -g1;
    cout << "-Graph 1:" << endl;
    cout << g5.printGraph() << endl;

    // Multiply graph by a scalar
    Graph g6 = g1 * 2;
    cout << "Graph 1 * 2:" << endl;
    cout << g6.printGraph() << endl;

    // Compare graphs
    cout << "Graph 1 == Graph 2: " << (g1 == g2) << endl;
    cout << "Graph 1 != Graph 2: " << (g1 != g2) << endl;

    return 0;
}

```

## Run
To run this project follow those steps:

- **Enter Terminal**
- **Run "make all" command**
- **Run "./test" or "./demo" command** 
- **Run "make clean" command when finished**
