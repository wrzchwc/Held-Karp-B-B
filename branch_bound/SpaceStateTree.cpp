#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(Node *node) {
    minimalLeaf = node;
    nodes.push_back(node);
}

void SpaceStateTree::addNode(Node *node) {
    if (node->getCost() < minimalLeaf->getCost()) {
        minimalLeaf = node;
    }
    nodes.push_back(node);
}

Node *SpaceStateTree::getMinimalLeaf() {
    return minimalLeaf;
}

SpaceStateTree::~SpaceStateTree() = default;


