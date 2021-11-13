#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(const shared_ptr<Node>& node) {
    minimalLeaf = node;
    nodes.push_back(node);
}

void SpaceStateTree::addNode(const shared_ptr<Node>& node) {
    if (node->getCost() < minimalLeaf->getCost()) {
        minimalLeaf = node;
    }
    nodes.push_back(node);
}

shared_ptr<Node> SpaceStateTree::getMinimalLeaf() {
    return minimalLeaf;
}

SpaceStateTree::~SpaceStateTree() = default;


