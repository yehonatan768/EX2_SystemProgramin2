/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#include <vector>
#include <queue>
#include "Graph.hpp"
#include <string>


namespace Algorithms {
    /**
     * @brief Checks if the given graph is connected.
     * 
     * @param g The Graph object representing the graph.
     * @return int Returns 1 if the graph is connected, 0 otherwise.
     */
    int isConnected(Graph g);

    /**
     * @brief Checks if the given graph contains a cycle.
     * 
     * @param g The Graph object representing the graph.
     * @return bool Returns true if the graph contains a cycle, false otherwise.
     */
    bool isContainsCycle(Graph g);

    /**
     * @brief Checks if the given graph is bipartite and returns the partitioning.
     * 
     * @param g The Graph object representing the graph.
     * @return std::string Returns a string indicating if the graph is bipartite and its partitioning.
     */
    std::string isBipartite(Graph g);

    /**
     * @brief Finds the shortest path between two vertices in the graph using Bellman-Ford.
     * 
     * @param g The Graph object representing the graph.
     * @param start The starting vertex.
     * @param end The ending vertex.
     * @return std::string Returns a string representing the shortest path between the vertices.
     */
    std::string shortestPath(Graph g, int start, int end);

    /**
     * @brief Finds a negative cycle in the graph using Bellman-Ford algorithm.
     * 
     * @param g The Graph object representing the graph.
     * @return std::string Returns a string representing the vertices in the negative cycle.
     */
    std::string negativeCycle(Graph g);

}