#include "Node.h"

Node::Node(int id, Node *parent, AdjacencyMatrix *matrix, int cost, const vector<int> &unvisited, bool parenthood) {
    this->id = id;
    this->parent = parent;
    this->matrix = matrix;
    this->cost = cost;
    this->unvisited = unvisited;
    this->parenthood = parenthood;
}

Node::~Node() {
    delete parent;
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

Node *Node::getParent() const {
    return parent;
}

bool Node::isParent() const {
    return parenthood;
}

void Node::setParenthood(bool value) {
    this->parenthood = value;
}
