/*
yehonatan768@gmail.com
213637424
*/

/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace Algorithms;

int main()
{
    Graph g;
    // 3x3 matrix that represents a connected graph.
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    std::cout << Algorithms::isConnected(g) << std::endl;        // Should print: "1" (true).
    std::cout << Algorithms::shortestPath(g, 0, 2) << std::endl; // Should print: 0->1->2.
    std::cout << Algorithms::isContainsCycle(g) << std::endl;    // Should print: "0" (false).
    std::cout << Algorithms::isBipartite(g) << std::endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    // 5x5 matrix that represents a non-connected graph with a cycle.
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    std::cout << Algorithms::isConnected(g) << std::endl;        // Should print: "0" (false).
    std::cout << Algorithms::shortestPath(g, 0, 4) << std::endl; // Should print: "-1" (there is no path between 0 and 4).
    std::cout << Algorithms::isContainsCycle(g) << std::endl;    // Should print: "The cycle is: 0->1->2->0".
    std::cout << Algorithms::isBipartite(g) << std::endl;        // Should print: "0" (false).

    // 5x5 matrix that reprsents a connected weighted graph.
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    std::cout << Algorithms::isConnected(g) << std::endl;        // Should print: "1" (true).
    std::cout << Algorithms::shortestPath(g, 0, 4) << std::endl; // Should print: 0->2->3->4.
    std::cout << Algorithms::isContainsCycle(g) << std::endl;    // Should print: "0" (false). (mistake: 0->1->2->0)
    std::cout << Algorithms::isBipartite(g) << std::endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

    // 5x4 matrix that reprsents invalid graph.
    std::vector<std::vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
}