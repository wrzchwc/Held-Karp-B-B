#include "Node.h"
#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(Node *node) {
    nodes.insert({node->getCost(), node});
}

void SpaceStateTree::addNode(Node *node) {
    nodes.insert({node->getCost(), node});
}

Node *SpaceStateTree::getMinimalLeaf() {
    auto minimal = nodes.begin();
    auto value = minimal->first;
    while (minimal->first == value) {
        minimal++;
    }
    minimal--;

    return minimal->second;
}

void SpaceStateTree::removeNode(Node *node) {
    auto iterator = nodes.find(node->getCost());
    if (iterator != nodes.end()) {
        while (iterator->second != node) {
            iterator++;
        }
        nodes.erase(iterator);
    }
}


SpaceStateTree::~SpaceStateTree() = default;


