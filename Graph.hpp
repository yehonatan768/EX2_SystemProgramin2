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
        std::vector<std::vector<int>> g; ///< Adjacency matrix of the graph.
        int size; ///< Size of the graph (number of vertices).

    public:
        /**
         * @brief Default constructor initializes an empty graph.
         */
        Graph() : size(0) {}

        /**
         * @brief Loads a graph from a given adjacency matrix.
         * @param graph A square matrix representing the graph.
         * @throws std::invalid_argument if the graph is not a square matrix.
         */
        void setMatrix(const std::vector<std::vector<int>>& graph);

        /**
         * @brief Prints the graph as a string.
         * @return A string representation of the graph.
         */
        std::string printGraph() const;

        /**
         * @brief Gets the adjacency matrix of the graph.
         * @return The adjacency matrix of the graph.
         */
        std::vector<std::vector<int>> getMatrix() const;

        
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

        /**
         * @brief Counts the number of edges in a graph.
         * @param matrix The adjacency matrix of the graph.
         * @return The number of edges.
         */
        int countEdges(const std::vector<std::vector<int>>& matrix) const;

        /**
         * @brief Adds two graphs.
         * @param other The graph to add.
         * @return The result of the addition.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        Graph operator+(const Graph& other) const;

        /**
         * @brief Adds another graph to this graph.
         * @param other The graph to add.
         * @return A reference to this graph.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        Graph& operator+=(const Graph& other);

        /**
         * @brief Returns a copy of this graph.
         * @return A copy of this graph.
         */
        Graph operator+() const;

        /**
         * @brief Subtracts one graph from another.
         * @param other The graph to subtract.
         * @return The result of the subtraction.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        Graph operator-(const Graph& other) const;

        /**
         * @brief Subtracts another graph from this graph.
         * @param other The graph to subtract.
         * @return A reference to this graph.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        Graph& operator-=(const Graph& other);

        /**
         * @brief Negates the graph.
         * @return The negated graph.
         */
        Graph operator-() const;

        /**
         * @brief Compares two graphs to determine if this graph is greater than the other.
         * @param other The graph to compare with.
         * @return True if this graph is greater than the other, false otherwise.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        bool operator>(const Graph& other) const;

        /**
         * @brief Compares two graphs to determine if this graph is less than the other.
         * @param other The graph to compare with.
         * @return True if this graph is less than the other, false otherwise.
         */
        bool operator<(const Graph& other) const;

        /**
         * @brief Compares two graphs for equality.
         * @param other The graph to compare with.
         * @return True if the graphs are equal, false otherwise.
         */
        bool operator==(const Graph& other) const;

        /**
         * @brief Compares two graphs for inequality.
         * @param other The graph to compare with.
         * @return True if the graphs are not equal, false otherwise.
         */
        bool operator!=(const Graph& other) const;

        /**
         * @brief Compares two graphs to determine if this graph is greater than or equal to the other.
         * @param other The graph to compare with.
         * @return True if this graph is greater than or equal to the other, false otherwise.
         */
        bool operator>=(const Graph& other) const;

        /**
         * @brief Compares two graphs to determine if this graph is less than or equal to the other.
         * @param other The graph to compare with.
         * @return True if this graph is less than or equal to the other, false otherwise.
         */
        bool operator<=(const Graph& other) const;

        /**
         * @brief Increments all elements of the graph by 1 (prefix).
         * @return A reference to this graph.
         */
        Graph& operator++(); // Pre-increment

        /**
         * @brief Increments all elements of the graph by 1 (postfix).
         * @return A copy of this graph before the increment.
         */
        Graph operator++(int); // Post-increment

        /**
         * @brief Decrements all elements of the graph by 1 (prefix).
         * @return A reference to this graph.
         */
        Graph& operator--(); // Pre-decrement

        /**
         * @brief Decrements all elements of the graph by 1 (postfix).
         * @return A copy of this graph before the decrement.
         */
        Graph operator--(int); // Post-decrement

        /**
         * @brief Multiplies all elements of the graph by a scalar.
         * @param scalar The scalar to multiply by.
         * @return The result of the multiplication.
         */
        Graph operator*(int scalar) const;

        /**
         * @brief Multiplies all elements of this graph by a scalar.
         * @param scalar The scalar to multiply by.
         * @return A reference to this graph.
         */
        Graph& operator*=(int scalar);

        /**
         * @brief Multiplies two graphs (matrix multiplication).
         * @param other The graph to multiply by.
         * @return The result of the multiplication.
         * @throws std::invalid_argument if the graphs are not of the same size.
         */
        Graph operator*(const Graph& other) const;

        /**
         * @brief Multiplies this graph by another graph (matrix multiplication).
         * @param other The graph to multiply by.
         * @return A reference to this graph.
         */
        Graph& operator*=(const Graph& other);
};

#endif // GRAPH_HPP
