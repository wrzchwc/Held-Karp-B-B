#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/m8.txt");
    auto node = new Node(0, nullptr, matrix, 25, vector<int>({1,2,3,4}));
    auto tree = new SpaceStateTree(static_cast<const shared_ptr<struct Node>>(node));
    cout<<tree->getMinimalLeaf()->getCost()<<endl;
    cout<<tree->getMinimalLeaf()->getParent()<<endl;
    cout<<tree->getMinimalLeaf()->getID()<<endl;
    cout<<tree->getMinimalLeaf()->getUnvisited().at(3)<<endl;
    tree->getMinimalLeaf()->getMatrix()->content();

    delete tree;
    return 0;
}
