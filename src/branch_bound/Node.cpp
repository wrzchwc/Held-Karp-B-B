#include "Node.h"

#include <utility>

Node::Node(int id, shared_ptr<Node> parent, AdjacencyMatrix *matrix, int cost, const vector<int> &unvisited) {
    this->id = id;
    this->parent = move(parent);
    this->matrix = matrix;
    this->cost = cost;
    this->unvisited = unvisited;
}

Node::~Node() {
    delete matrix;
}

int Node::getID() const {
    return id;
}

AdjacencyMatrix *Node::getMatrix() const {
    return matrix;
}

int Node::getCost() const {
    return cost;
}

const vector<int> &Node::getUnvisited() const {
    return unvisited;
}

