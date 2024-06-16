#include "doctest.h"
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <vector>

using namespace std;
using namespace Algorithms;

TEST_CASE("Test isConnected")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::isConnected(g) == 1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(Algorithms::isConnected(g) == 0);
}

TEST_CASE("Test shortestPath")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 100},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {100, 0, 0, 1, 0}};
    g.setMatrix(graph3);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g.setMatrix(graph4);
    
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->4");

    vector<vector<int>> graph5 = {
        {0, -1, 1, 0, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {1, 0, 0, -1, 0}};
    g.setMatrix(graph5);
    
    CHECK(Algorithms::shortestPath(g, 0, 0) == "0");
    
}
TEST_CASE("Test isContainsCycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::isContainsCycle(g) == false);
    

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph3);
    CHECK(Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    g.setMatrix(graph4);
    CHECK(Algorithms::isContainsCycle(g) == false);
}


TEST_CASE("Test isBipartite")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.setMatrix(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.setMatrix(graph2);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.setMatrix(graph3);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.setMatrix(graph4);
    CHECK(Algorithms::isBipartite(g) == "0");


    vector<vector<int>> graph5 = {{0}};
    g.setMatrix(graph5);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={}");

    vector<vector<int>> graph6 = {
        {0, 1},
        {1, 0}
    };
    g.setMatrix(graph6);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");

    vector<vector<int>> graph7 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph7);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}


TEST_CASE("Test negativeCycle")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    g.setMatrix(graph);
    CHECK(Algorithms::negativeCycle(g)=="No Negative Cycle");


    vector<vector<int>> graph2 = {
        {0, 1, 0, -100},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {-100, 0, 1, 0},
    };
    g.setMatrix(graph2);
    CHECK(Algorithms::negativeCycle(g)=="0->3->0");


    vector<vector<int>> graph3 = {
        {0, 1, 0, -100},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
    };
    g.setMatrix(graph3);
    CHECK(Algorithms::negativeCycle(g)=="2->3->0->1->2");
}


TEST_CASE("Test graph addition")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.setMatrix(graph2);

    g2 += g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test graph multiplication")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.setMatrix(graph2);

    Graph g3 = g1 * g2;

    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    Graph expected;
    expected.setMatrix(expectedGraph);

    CHECK((g3 == expected) == true);
}

TEST_CASE("Test unary plus operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    Graph g2 = +g1;

    CHECK((g1 == g2) == true);
}

TEST_CASE("Test unary minus operator")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    Graph g2 = -g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, -1},
        {-1, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test graph subtraction")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 3},
        {2, 1}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}};
    g2.setMatrix(graph2);

    Graph g3 = g1 - g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {1, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test scalar multiplication")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    Graph g2 = g1 * 2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 2},
        {2, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g2 == expectedGraph) == true);
}

TEST_CASE("Test scalar multiplication assignment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    g1 *= 3;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 3},
        {3, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph pre-increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    ++g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph post-increment")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.setMatrix(graph1);

    Graph g2 = g1++;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g2 == expectedGraph) == true);

    expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph pre-decrement")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2},
        {2, 1}};
    g1.setMatrix(graph1);

    --g1;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph post-decrement")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2},
        {2, 1}};
    g1.setMatrix(graph1);

    Graph g2 = g1--;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 2},
        {2, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g2 == expectedGraph) == true);

    expectedData = {
        {0, 1},
        {1, 0}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph comparison operators")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1},
        {1, 1}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1},
        {1, 1}};
    g2.setMatrix(graph2);

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
    g1.setMatrix(graph1);

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g1 == expectedGraph) == true);
}

TEST_CASE("Test graph addition with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.setMatrix(graph2);

    Graph g3 = g1 + g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 2},
        {1, 2, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test graph subtraction with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {2, 1, 1},
        {1, 2, 2},
        {1, 2, 2}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g2.setMatrix(graph2);

    Graph g3 = g1 - g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 2},
        {1, 2, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g3 == expectedGraph) == true);
}

TEST_CASE("Test graph multiplication with self edges")
{
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g1.setMatrix(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g2.setMatrix(graph2);

    Graph g3 = g1 * g2;

    Graph expectedGraph;
    vector<vector<int>> expectedData = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    expectedGraph.setMatrix(expectedData);

    CHECK((g3 == expectedGraph) == true);
}
