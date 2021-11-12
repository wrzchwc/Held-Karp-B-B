#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/m8.txt");
    auto node = new Node(0, nullptr, matrix, 25, vector<int>({1, 2, 3, 4}));
    auto node2 = new Node(1, nullptr, matrix, 24, vector<int>({1, 89, 3, 4}));
    auto tree = new SpaceStateTree(node);
    tree->addNode(node2);

    cout<<"ID of minimal node: "<<tree->getMinimalLeaf()->getID()<<endl;
    cout<<"parent of minmal node: "<<tree->getMinimalLeaf()->getParent()<<endl;
    tree->getMinimalLeaf()->getMatrix()->content();
    cout<<"cost of minimal matrix: "<<tree->getMinimalLeaf()->getCost()<<endl;
    cout<<"second unvisited: "<<tree->getMinimalLeaf()->getUnvisited().at(1)<<endl;



    delete matrix;
    delete node;
    delete tree;
    return 0;
}
