#include "Node.h"
#include "SpaceStateTree.h"

SpaceStateTree::SpaceStateTree(Node *node) {
    nodes.push_back(node);
    leaves.push_back(node);
}

void SpaceStateTree::addNode(Node *node) {
    auto tmp = node;
    nodes.push_back(tmp);
    leaves.push_back(tmp);

    if (find(leaves.begin(), leaves.end(), node->getParent()) != leaves.end()){
        leaves.erase(remove(leaves.begin(), leaves.end(), node->getParent()));
    }
}

Node *SpaceStateTree::getMinimalLeaf() {
    auto tmp = leaves.at(0);

    for (int i = 1; i < leaves.size(); i++) {
        if (leaves.at(i)->getCost()<tmp->getCost()){
            tmp = leaves.at(i);
        }
    }

    return tmp;
}

SpaceStateTree::~SpaceStateTree() = default;


