#include "Node.h"
#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(Node *node) {
    nodes.insert({node->getCost(), node});
}

void SpaceStateTree::addNode(Node *node) {
    auto parentValue = node->getParent()->getCost();
    auto iterator = nodes.find(parentValue);

    if (iterator != nodes.end()) {
        while (iterator->second != node->getParent() && iterator->second != nodes.rbegin()->second) {
            iterator++;
        }

        if (iterator->second==node->getParent()){
            nodes.erase(iterator);
        }
    }
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

SpaceStateTree::~SpaceStateTree() = default;


