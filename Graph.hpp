/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

/**
 * @class Graph
 * @brief A class to represent a graph using an adjacency matrix.
 */
class Graph {
    private:
        std::vector<std::vector<int>> g; ///< The adjacency matrix of the graph.
        int size; ///< The size of the graph (number of vertices).

    public:
        /**
         * @brief Default constructor initializes an empty graph.
         */
        Graph() : size(0) {}

        /**
         * @brief Loads a graph represented as an adjacency matrix.
         * 
         * @param graph The adjacency matrix representing the graph.
         * @throws std::invalid_argument If the graph is not a square matrix.
         */
        void loadGraph(const std::vector<std::vector<int>>& graph);

        /**
         * @brief Returns a string representation of the graph.
         * 
         * @return A string representing the adjacency matrix of the graph.
         */
        std::string printGraph() const;

        /**
         * @brief Returns the adjacency matrix of the graph.
         * 
         * @return The adjacency matrix of the graph.
         */
        std::vector<std::vector<int>> setMatrix() const;

        /**
         * @brief Counts the number of edges in a given adjacency matrix.
         * 
         * @param matrix The adjacency matrix.
         * @return The number of edges in the graph.
         */
        int countEdges(const std::vector<std::vector<int>>& matrix) const;

        /**
         * @brief Adds two graphs.
         * 
         * @param other The graph to be added.
         * @return A new graph that is the sum of the current graph and the other graph.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        Graph operator+(const Graph& other) const;

        /**
         * @brief Adds another graph to the current graph.
         * 
         * @param other The graph to be added.
         * @return A reference to the current graph after addition.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        Graph& operator+=(const Graph& other);

        /**
         * @brief Unary plus operator.
         * 
         * @return A copy of the current graph.
         */
        Graph operator+() const;

        /**
         * @brief Subtracts one graph from another.
         * 
         * @param other The graph to be subtracted.
         * @return A new graph that is the difference between the current graph and the other graph.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        Graph operator-(const Graph& other) const;

        /**
         * @brief Subtracts another graph from the current graph.
         * 
         * @param other The graph to be subtracted.
         * @return A reference to the current graph after subtraction.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        Graph& operator-=(const Graph& other);

        /**
         * @brief Unary minus operator.
         * 
         * @return A new graph where each element is the negation of the current graph's elements.
         */
        Graph operator-() const;

        /**
         * @brief Compares if the current graph is greater than another graph.
         * 
         * @param other The graph to be compared with.
         * @return True if the current graph is greater, false otherwise.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        bool operator>(const Graph& other) const;

        /**
         * @brief Compares if the current graph is less than another graph.
         * 
         * @param other The graph to be compared with.
         * @return True if the current graph is less, false otherwise.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        bool operator<(const Graph& other) const;

        /**
         * @brief Checks if two graphs are equal.
         * 
         * @param other The graph to be compared with.
         * @return True if the graphs are equal, false otherwise.
         */
        bool operator==(const Graph& other) const;

        /**
         * @brief Checks if two graphs are not equal.
         * 
         * @param other The graph to be compared with.
         * @return True if the graphs are not equal, false otherwise.
         */
        bool operator!=(const Graph& other) const;

        /**
         * @brief Checks if the current graph is greater than or equal to another graph.
         * 
         * @param other The graph to be compared with.
         * @return True if the current graph is greater than or equal, false otherwise.
         */
        bool operator>=(const Graph& other) const;

        /**
         * @brief Checks if the current graph is less than or equal to another graph.
         * 
         * @param other The graph to be compared with.
         * @return True if the current graph is less than or equal, false otherwise.
         */
        bool operator<=(const Graph& other) const;

        /**
         * @brief Pre-increment operator.
         * 
         * @return A reference to the current graph after incrementing each element by one.
         */
        Graph& operator++(); // Pre-increment

        /**
         * @brief Post-increment operator.
         * 
         * @return A copy of the current graph before incrementing each element by one.
         */
        Graph operator++(int); // Post-increment

        /**
         * @brief Pre-decrement operator.
         * 
         * @return A reference to the current graph after decrementing each element by one.
         */
        Graph& operator--(); // Pre-decrement

        /**
         * @brief Post-decrement operator.
         * 
         * @return A copy of the current graph before decrementing each element by one.
         */
        Graph operator--(int); // Post-decrement

        /**
         * @brief Multiplies each element of the graph by a scalar.
         * 
         * @param scalar The scalar to multiply with.
         * @return A new graph after scalar multiplication.
         */
        Graph operator*(int scalar) const;

        /**
         * @brief Multiplies each element of the current graph by a scalar.
         * 
         * @param scalar The scalar to multiply with.
         * @return A reference to the current graph after scalar multiplication.
         */
        Graph& operator*=(int scalar);

        /**
         * @brief Multiplies two graphs (matrix multiplication).
         * 
         * @param other The graph to be multiplied.
         * @return A new graph that is the product of the current graph and the other graph.
         * @throws std::invalid_argument If the graphs are not of the same size.
         */
        Graph operator*(const Graph& other) const;

        /**
         * @brief Multiplies another graph with the current graph (matrix multiplication).
         * 
         * @param other The graph to be multiplied.
         * @return A reference to the current graph after multiplication.
         */
        Graph& operator*=(const Graph& other);
};

#endif // GRAPH_HPP
