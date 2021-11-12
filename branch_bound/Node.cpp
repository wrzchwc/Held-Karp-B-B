#include "Node.h"

Node::Node(int id, Node *parent, AdjacencyMatrix *matrix, int cost, const vector<int> &unvisited) {
    this->id = id;
    this->parent = parent;
    this->matrix = matrix;
    this->cost = cost;
    this->unvisited = unvisited;
}

Node::~Node() {
    parent = nullptr;
    matrix = nullptr;
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

Node *Node::getParent() const {
    return parent;
}
