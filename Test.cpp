/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */
#include "doctest.h"
#include "Graph.hpp"
#include <vector>

using namespace std;

TEST_CASE("Test graph addition")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    g2 += g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test graph multiplication")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    Graph g3 = g1 * g2;

    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    Graph expected;
    expected.loadGraph(expectedGraph);

    CHECK((g3 == expected) == true);
}


TEST_CASE("Test unary plus operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = +g1;

    CHECK((g1 == g2) == true);
}

TEST_CASE("Test unary minus operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = -g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, -1},
        {-1, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test graph subtraction")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 3},
        {2, 1}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(graph2);

    Graph g3 = g1 - g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {1, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test scalar multiplication")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1 * 2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2},
        {2, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test scalar multiplication assignment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    g1 *= 3;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 3},
        {3, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph pre-increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    ++g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph post-increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    Graph g2 = g1++;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g2 == expectedGraph) == true);

    expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph pre-decrement")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2},
        {2, 1}};
    g1.loadGraph(graph1);

    --g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph post-decrement")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2},
        {2, 1}};
    g1.loadGraph(graph1);

    Graph g2 = g1--;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g2 == expectedGraph) == true);

    expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph comparison operators")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1},
        {1, 1}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}};
    g2.loadGraph(graph2);

    CHECK((g1 == g2) == true);
    CHECK((g1 != g2) == false);
    CHECK((g1 >= g2) == true);
    CHECK((g1 <= g2) == true);
    CHECK((g1 > g2) == false);
    CHECK((g1 < g2) == false);
}

TEST_CASE("Test self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g1.loadGraph(graph1);

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph addition with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    Graph g3 = g1 + g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 2},
        {1, 2, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test graph subtraction with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {2, 1, 1},
        {1, 2, 2},
        {1, 2, 2}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3 = g1 - g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 2},
        {1, 2, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test graph multiplication with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g2.loadGraph(graph2);

    Graph g3 = g1 * g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    expectedGraph.loadGraph(expectedData);

    CHECK((g3 == expectedGraph) == true);
}
