/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <sstream>

/**
 * @brief Loads a graph represented as an adjacency matrix.
 * 
 * @param graph The adjacency matrix representing the graph.
 * @throws std::invalid_argument If the graph is not a square matrix.
 */
void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
    if (graph.empty() || graph.size() != graph[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }

    this->g = graph;
    this->size = this->g.size();
}

/**
 * @brief Returns a string representation of the graph.
 * 
 * @return A string representing the adjacency matrix of the graph.
 */
std::string Graph::printGraph() const {
    std::ostringstream oss;
    for (const auto& row : this->g) {
        for (int val : row) {
            oss << val << " ";
        }
        oss << "\n";
    }
    return oss.str();
}

/**
 * @brief Returns the adjacency matrix of the graph.
 * 
 * @return The adjacency matrix of the graph.
 */
std::vector<std::vector<int>> Graph::setMatrix() const {
    return this->g;
}

/**
 * @brief Adds two graphs.
 * 
 * @param other The graph to be added.
 * @return A new graph that is the sum of the current graph and the other graph.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
Graph Graph::operator+(const Graph& other) const {
    if (this->size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size to add.");
    }

    Graph result;
    result.size = this->size;
    result.g.resize(this->size, std::vector<int>(this->size, 0));

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result.g[i][j] = this->g[i][j] + other.g[i][j];
        }
    }

    return result;
}

/**
 * @brief Adds another graph to the current graph.
 * 
 * @param other The graph to be added.
 * @return A reference to the current graph after addition.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
Graph& Graph::operator+=(const Graph& other) {
    if (this->size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size to add.");
    }

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->g[i][j] += other.g[i][j];
        }
    }

    return *this;
}

/**
 * @brief Unary plus operator.
 * 
 * @return A copy of the current graph.
 */
Graph Graph::operator+() const {
    return *this;
}

/**
 * @brief Subtracts one graph from another.
 * 
 * @param other The graph to be subtracted.
 * @return A new graph that is the difference between the current graph and the other graph.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
Graph Graph::operator-(const Graph& other) const {
    if (this->size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size to subtract.");
    }

    Graph result;
    result.size = this->size;
    result.g.resize(this->size, std::vector<int>(this->size, 0));

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result.g[i][j] = this->g[i][j] - other.g[i][j];
        }
    }

    return result;
}

/**
 * @brief Subtracts another graph from the current graph.
 * 
 * @param other The graph to be subtracted.
 * @return A reference to the current graph after subtraction.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
Graph& Graph::operator-=(const Graph& other) {
    if (this->size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size to subtract.");
    }

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->g[i][j] -= other.g[i][j];
        }
    }

    return *this;
}

/**
 * @brief Unary minus operator.
 * 
 * @return A new graph where each element is the negation of the current graph's elements.
 */
Graph Graph::operator-() const {
    Graph result;
    result.size = this->size;
    result.g.resize(this->size, std::vector<int>(this->size, 0));

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result.g[i][j] = -this->g[i][j];
        }
    }

    return result;
}

/**
 * @brief Compares if the current graph is greater than another graph.
 * 
 * @param other The graph to be compared with.
 * @return True if the current graph is greater, false otherwise.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
bool Graph::operator>(const Graph& other) const {
    if (this->size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size to compare.");
    }

    bool thisContainedInOther = true;
    bool otherContainedInThis = true;

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            if (this->g[i][j] > other.g[i][j]) {
                otherContainedInThis = false;
            }
            if (this->g[i][j] < other.g[i][j]) {
                thisContainedInOther = false;
            }
        }
    }

    if (otherContainedInThis && !thisContainedInOther) {
        return false;
    } else if (thisContainedInOther && !otherContainedInThis) {
        return true;
    }

    int thisEdges = countEdges(this->g);
    int otherEdges = countEdges(other.g);

    if (thisEdges != otherEdges) {
        return otherEdges > thisEdges;
    }

    return this->g < other.g;
}

/**
 * @brief Compares if the current graph is less than another graph.
 * 
 * @param other The graph to be compared with.
 * @return True if the current graph is less, false otherwise.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
bool Graph::operator<(const Graph& other) const {
    return other > *this;
}

/**
 * @brief Checks if two graphs are equal.
 * 
 * @param other The graph to be compared with.
 * @return True if the graphs are equal, false otherwise.
 */
bool Graph::operator==(const Graph& other) const {
    if (this->size != other.size) {
        return false;
    }
    return !(*this > other) && !(other > *this);
}

/**
 * @brief Checks if two graphs are not equal.
 * 
 * @param other The graph to be compared with.
 * @return True if the graphs are not equal, false otherwise.
 */
bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

/**
 * @brief Checks if the current graph is greater than or equal to another graph.
 * 
 * @param other The graph to be compared with.
 * @return True if the current graph is greater than or equal, false otherwise.
 */
bool Graph::operator>=(const Graph& other) const {
    return *this > other || *this == other;
}

/**
 * @brief Checks if the current graph is less than or equal to another graph.
 * 
 * @param other The graph to be compared with.
 * @return True if the current graph is less than or equal, false otherwise.
 */
bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

/**
 * @brief Pre-increment operator.
 * 
 * @return A reference to the current graph after incrementing each element by one.
 */
Graph& Graph::operator++() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            ++this->g[i][j];
        }
    }
    return *this;
}

/**
 * @brief Post-increment operator.
 * 
 * @return A copy of the current graph before incrementing each element by one.
 */
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief Pre-decrement operator.
 * 
 * @return A reference to the current graph after decrementing each element by one.
 */
Graph& Graph::operator--() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            --this->g[i][j];
        }
    }
    return *this;
}

/**
 * @brief Post-decrement operator.
 * 
 * @return A copy of the current graph before decrementing each element by one.
 */
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

/**
 * @brief Multiplies each element of the graph by a scalar.
 * 
 * @param scalar The scalar value to multiply by.
 * @return A new graph with each element multiplied by the scalar.
 */
Graph Graph::operator*(int scalar) const {
    Graph result;
    result.size = this->size;
    result.g.resize(this->size, std::vector<int>(this->size, 0));

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            result.g[i][j] = this->g[i][j] * scalar;
        }
    }

    return result;
}

/**
 * @brief Multiplies each element of the current graph by a scalar.
 * 
 * @param scalar The scalar value to multiply by.
 * @return A reference to the current graph after multiplication.
 */
Graph& Graph::operator*=(int scalar) {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->g[i][j] *= scalar;
        }
    }
    return *this;
}

/**
 * @brief Multiplies two graphs using matrix multiplication.
 * 
 * @param other The graph to be multiplied with.
 * @return A new graph that is the result of matrix multiplication.
 * @throws std::invalid_argument If the graphs are not of the same size.
 */
Graph Graph::operator*(const Graph& other) const {
    if (this->size != other.size) {
        throw std::invalid_argument("Matrix multiplication requires matrices of the same size.");
    }

    Graph result;
    result.size = this->size;
    result.g.resize(this->size, std::vector<int>(this->size, 0));

    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            for (int k = 0; k < this->size; ++k) {
                result.g[i][j] += this->g[i][k] * other.g[k][j];
            }
        }
    }

    return result;
}

/**
 * @brief Multiplies the current graph by another graph using matrix multiplication.
 * 
 * @param other The graph to be multiplied with.
 * @return A reference to the current graph after multiplication.
 */
Graph& Graph::operator*=(const Graph& other) {
    *this = *this * other;
    return *this;
}

/**
 * @brief Counts the number of edges in the graph.
 * 
 * @param matrix The adjacency matrix representing the graph.
 * @return The number of edges in the graph.
 */
int Graph::countEdges(const std::vector<std::vector<int>>& matrix) const {
    int count = 0;
    for (const auto& row : matrix) {
        count += std::count(row.begin(), row.end(), 1);
    }
    return count;
}
