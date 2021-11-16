#include "Node.h"
#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(const shared_ptr<Node>& node) {
    nodes.insert(pair<int, shared_ptr<Node>>(node->getCost(), node));
}

void SpaceStateTree::addNode(const shared_ptr<Node>& node) {
    nodes.insert(pair<const int, shared_ptr<Node>>(node->getCost(), node));
}

shared_ptr<Node> SpaceStateTree::getMinimalLeaf() {
    auto minimal = nodes.begin();
    auto value = minimal->first;
    while (minimal->first == value) {
        minimal++;
    }
    minimal--;

    return minimal->second;
}


void SpaceStateTree::removeNode(const shared_ptr<Node>& node) {
    auto iterator = nodes.find(node->getCost());
    if (iterator != nodes.end()) {
        while (iterator->second != node) {
            iterator++;
        }
        nodes.erase(iterator);
    }
}


SpaceStateTree::~SpaceStateTree() = default;


