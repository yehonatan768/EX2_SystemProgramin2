/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include "Algorithms.hpp"
#include <limits>

namespace Algorithms {

    /**
     * @brief Checks if the given graph is connected.
     * 
     * @param graph The Graph object representing the graph.
     * @return int Returns 1 if the graph is connected, 0 otherwise.
     */
    int isConnected(Graph graph) {
        const std::vector<std::vector<int>> g = graph.getMatrix();
        int n = g.size();
        if (n == 0) return 1;
        std::vector<bool> visited(n, false);
        std::stack<int> stk;
        // Start DFS from vertex 0
        stk.push(0);
        visited[0] = true;
        int counter = 1;
        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();
            for (int i = 0; i < n; i++) {
                if (g[current][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    stk.push(i);
                    counter++;
                }
            }
        }
        if (counter == n) return 1;
        return 0;
    }

    /**
     * @brief Checks if the given graph contains a cycle.
     * 
     * @param graph The Graph object representing the graph.
     * @return bool Returns true if the graph contains a cycle, false otherwise.
     */
    bool isContainsCycle(Graph graph) {
        const std::vector<std::vector<int>> g = graph.getMatrix();
        int n = g.size();
        if (n <= 1) return false;
        std::vector<bool> visited(n, false);
        std::stack<std::pair<int, int>> stk;

        for (int startVer = 0; startVer < n; startVer++) {
            if (visited[startVer]) continue;
            stk.push({startVer, -1});

            while (!stk.empty()) {
                int current = stk.top().first;
                int parent = stk.top().second;
                stk.pop();
                if (visited[current]) continue;
                visited[current] = true;
                for (int i = 0; i < n; i++) {
                    if (g[current][i] != 0) {
                        if (visited[i] && i != parent) {
                            return true; // Found a cycle
                        }
                        if (!visited[i]) {
                            stk.push({i, current}); // Push the node and its parent
                        }
                    }
                }
            }
        }
        return false;
    }

    /**
     * @brief Checks if the given graph is bipartite and returns the partitioning.
     * 
     * @param graph The Graph object representing the graph.
     * @return std::string Returns a string indicating if the graph is bipartite and its partitioning.
     */
    std::string isBipartite(Graph graphObj){
        const std::vector<std::vector<int>> g = graphObj.getMatrix();
        int n=g.size();
        if(n==0)return "The graph is bipartite: A={}, B={}";
        if(n==1)return "The graph is bipartite: A={0}, B={}";
        if(n==2)return "The graph is bipartite: A={0}, B={1}";
        std::vector<int> side(n,0);std::queue<int> q;
        for(int startVertix=0;startVertix<n;startVertix++){//for each vertix make sure the while got it (if not connected)
            if(side[startVertix]==0){
                q.push(startVertix);side[startVertix]=1;
                while (!q.empty()) {//check for each connected vertix if not bipartite
                    int current = q.front();
                    q.pop();
                    for(int i=0;i<n;i++){
                        if (g[current][i]!=0 && i>current){
                            if(side[i]==side[current])return "0";
                            if(side[i]==0)q.push(i);
                            side[i]=side[current]*(-1);
                        }
                    }
                }
            }
        }
        std::string sideA = "";
        std::string sideB = "";
        for(int i=0;i<n;i++){
            std::string next = std::to_string(i);
            if(side[i]==1){
                if(!sideA.empty())sideA+=", ";
                sideA+=next;
            }
            else{
                if(!sideB.empty())sideB+=", ";
                sideB+=next;
            }
        }
        std::string ans = "The graph is bipartite: A={"+sideA+"}, B={"+sideB+"}";
        return ans;
    }

    /**
     * @brief Finds the shortest path between two vertices in the graph using Bellman-Ford.
     * 
     * @param graph The Graph object representing the graph.
     * @param start The starting vertex.
     * @param end The ending vertex.
     * @return std::string Returns a string representing the shortest path between the vertices.
     */
    std::string shortestPath(Graph graph, int start, int end) {
    const std::vector<std::vector<int>> g = graph.getMatrix();
    int n = g.size();
    if (start >= n || end >= n || start < 0 || end < 0) return "Input vertices don't match Graph size.";
    if (end == start) return std::to_string(start);

    std::vector<int> VerDist(n, std::numeric_limits<int>::max());
    std::vector<int> reconstruct(n, -1);
    VerDist[start] = 0;

    // Bellman-Ford algorithm
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (g[u][v] != 0 && VerDist[u] != std::numeric_limits<int>::max() && VerDist[u] + g[u][v] < VerDist[v]) {
                    VerDist[v] = VerDist[u] + g[u][v];
                    reconstruct[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (g[u][v] != 0 && VerDist[u] != std::numeric_limits<int>::max() && VerDist[u] + g[u][v] < VerDist[v]) {
                return "Graph contains a negative-weight cycle.";
            }
        }
    }

    if (VerDist[end] == std::numeric_limits<int>::max()) return "-1";
    
    // Reconstruct the path from endVer back to startVer
    std::string ans;
    for (int at = end; at != -1; at = reconstruct[at]) {
        ans = std::to_string(at) + (ans.empty() ? "" : "->" + ans);
    }

    return ans;
}

    /**
     * @brief Finds a negative cycle in the graph using Bellman-Ford algorithm.
     * 
     * @param graph The Graph object representing the graph.
     * @return std::string Returns a string representing the vertices in the negative cycle.
     */
    std::string negativeCycle(Graph graph) {
        const std::vector<std::vector<int>> g = graph.getMatrix();
        int n = g.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> predecessor(n, -1);

        int cycleStart = -1;
        dist[0] = 0;

        // detect with Belman Ford if there is a cycle and one vertex on it
        for (int step = 0; step < n; ++step) {
            cycleStart = -1;
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (g[u][v] && dist[u] != std::numeric_limits<int>::max() && dist[u] + g[u][v] < dist[v]) {
                        dist[v] = dist[u] + g[u][v];
                        predecessor[v] = u;
                        if (step == n - 1) {
                            cycleStart = v;
                        }
                    }
                }
            }
        }

        if (cycleStart == -1) return "No Negative Cycle";
        else {
            // Finding the cycle
            std::vector<int> cycle;
            int v = cycleStart;
            for (int i = 0; i < n; ++i) {
                v = predecessor[v];
            }

            // Store the cycle in reverse order
            int u = v;
            cycle.push_back(v);
            while (true) {
                v = predecessor[v];
                if (v == u) {
                    break;
                }
                cycle.push_back(v);
            }
            cycle.push_back(u); // Complete the cycle by returning to the start vertex

            // Convert cycle to string format
            std::string ans = "";
            for (size_t i = 0; i < cycle.size(); i++) {
                if (i > 0) ans = ans + "->";
                std::string next = std::to_string(cycle[i]);
                ans = ans + next;
            }
            return ans;
        }
    }
}
