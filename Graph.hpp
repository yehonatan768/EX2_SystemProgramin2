/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>


class Graph {
    private:
        std::vector<std::vector<int>> g;
        int size;

    public:
        Graph() : size(0) {}

        void loadGraph(const std::vector<std::vector<int>>& graph);

        std::string printGraph() const;

        std::vector<std::vector<int>> setMatrix() const;

        int countEdges(const std::vector<std::vector<int>>& matrix) const;

        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator+() const;

        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator-() const;

        bool operator>(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<=(const Graph& other) const;

        Graph& operator++(); // Pre-increment
        Graph operator++(int); // Post-increment
        Graph& operator--(); // Pre-decrement
        Graph operator--(int); // Post-decrement

        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);

        Graph operator*(const Graph& other) const;
        Graph& operator*=(const Graph& other);
};

#endif // GRAPH_HPP
