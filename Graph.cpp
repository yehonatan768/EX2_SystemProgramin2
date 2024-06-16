/*
 * Author: yehonatan768@gmail.com
 * ID: 213637424
 */

#include "Graph.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <sstream>

/**
 * @brief Loads a graph from a given adjacency matrix.
 * @param graph A square matrix representing the graph.
 * @throws std::invalid_argument if the graph is not a square matrix.
 */
void Graph::setMatrix(const std::vector<std::vector<int>>& graph) {
    if (graph.empty() || graph.size() != graph[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }

    this->g = graph;
    this->size = this->g.size();
}

/**
 * @brief Prints the graph as a string.
 * @return A string representation of the graph.
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
 * @brief Gets the adjacency matrix of the graph.
 * @return The adjacency matrix of the graph.
 */
std::vector<std::vector<int>> Graph::getMatrix() const {
    return this->g;
}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.size; ++i) {
        for (int j = 0; j < graph.size; ++j) {
            os << std::setw(4)<< graph.getMatrix()[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

/**
 * @brief Adds two graphs.
 * @param other The graph to add.
 * @return The result of the addition.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Adds another graph to this graph.
 * @param other The graph to add.
 * @return A reference to this graph.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Returns a copy of this graph.
 * @return A copy of this graph.
 */
Graph Graph::operator+() const {
    return *this;
}

/**
 * @brief Subtracts one graph from another.
 * @param other The graph to subtract.
 * @return The result of the subtraction.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Subtracts another graph from this graph.
 * @param other The graph to subtract.
 * @return A reference to this graph.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Negates the graph.
 * @return The negated graph.
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
 * @brief Compares two graphs to determine if this graph is greater than the other.
 * @param other The graph to compare with.
 * @return True if this graph is greater than the other, false otherwise.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Compares two graphs to determine if this graph is less than the other.
 * @param other The graph to compare with.
 * @return True if this graph is less than the other, false otherwise.
 */
bool Graph::operator<(const Graph& other) const {
    return other > *this;
}

/**
 * @brief Compares two graphs for equality.
 * @param other The graph to compare with.
 * @return True if the graphs are equal, false otherwise.
 */
bool Graph::operator==(const Graph& other) const {
    if (this->size != other.size) {
        return false;
    }
    return !(*this > other) && !(other > *this);
}

/**
 * @brief Compares two graphs for inequality.
 * @param other The graph to compare with.
 * @return True if the graphs are not equal, false otherwise.
 */
bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

/**
 * @brief Compares two graphs to determine if this graph is greater than or equal to the other.
 * @param other The graph to compare with.
 * @return True if this graph is greater than or equal to the other, false otherwise.
 */
bool Graph::operator>=(const Graph& other) const {
    return *this > other || *this == other;
}

/**
 * @brief Compares two graphs to determine if this graph is less than or equal to the other.
 * @param other The graph to compare with.
 * @return True if this graph is less than or equal to the other, false otherwise.
 */
bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

/**
 * @brief Increments all elements of the graph by 1 (prefix).
 * @return A reference to this graph.
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
 * @brief Increments all elements of the graph by 1 (postfix).
 * @return A copy of this graph before the increment.
 */
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief Decrements all elements of the graph by 1 (prefix).
 * @return A reference to this graph.
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
 * @brief Decrements all elements of the graph by 1 (postfix).
 * @return A copy of this graph before the decrement.
 */
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

/**
 * @brief Multiplies all elements of the graph by a scalar.
 * @param scalar The scalar to multiply by.
 * @return The result of the multiplication.
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
 * @brief Multiplies all elements of this graph by a scalar.
 * @param scalar The scalar to multiply by.
 * @return A reference to this graph.
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
 * @brief Multiplies two graphs (matrix multiplication).
 * @param other The graph to multiply by.
 * @return The result of the multiplication.
 * @throws std::invalid_argument if the graphs are not of the same size.
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
 * @brief Multiplies this graph by another graph (matrix multiplication).
 * @param other The graph to multiply by.
 * @return A reference to this graph.
 */
Graph& Graph::operator*=(const Graph& other) {
    *this = *this * other;
    return *this;
}

/**
 * @brief Counts the number of edges in a graph.
 * @param matrix The adjacency matrix of the graph.
 * @return The number of edges.
 */
int Graph::countEdges(const std::vector<std::vector<int>>& matrix) const {
    int count = 0;
    for (const auto& row : matrix) {
        count += std::count(row.begin(), row.end(), 1);
    }
    return count;
}
