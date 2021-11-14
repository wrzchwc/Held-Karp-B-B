#include "Node.h"
#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(Node *node) {
    m.insert({node->getCost(), node});
}

void SpaceStateTree::addNode(Node *node) {
    auto parentValue = node->getParent()->getCost();
    auto iterator = m.find(parentValue);
    if ( iterator != m.end() && iterator->second == node->getParent()) {
        m.erase(iterator);
    }
    m.insert({node->getCost(), node});
}

Node *SpaceStateTree::getMinimalLeaf() {
    return m.begin()->second;
}

SpaceStateTree::~SpaceStateTree() = default;


