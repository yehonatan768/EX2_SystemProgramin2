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

void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
    if (graph.empty() || graph.size() != graph[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }

    this->g = graph;
    this->size = this->g.size();
}

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

std::vector<std::vector<int>> Graph::setMatrix() const {
    return this->g;
}

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

Graph Graph::operator+() const {
    return *this;
}

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

bool Graph::operator<(const Graph& other) const {
    return other > *this;
}

bool Graph::operator==(const Graph& other) const {
    if (this->size != other.size) {
        return false;
    }
    return !(*this > other) && !(other > *this);
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator>=(const Graph& other) const {
    return *this > other || *this == other;
}

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

Graph& Graph::operator++() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            ++this->g[i][j];
        }
    }
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            --this->g[i][j];
        }
    }
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

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

Graph& Graph::operator*=(int scalar) {
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            this->g[i][j] *= scalar;
        }
    }
    return *this;
}

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

Graph& Graph::operator*=(const Graph& other) {
    *this = *this * other;
    return *this;
}

int Graph::countEdges(const std::vector<std::vector<int>>& matrix) const {
    int count = 0;
    for (const auto& row : matrix) {
        count += std::count(row.begin(), row.end(), 1);
    }
    return count;
}