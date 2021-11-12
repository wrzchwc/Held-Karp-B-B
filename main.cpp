#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/Node.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/gr24.txt");
    vector<int> unvisited({1,2,3,4});
    auto* node = new Node(0, nullptr, matrix, 25, unvisited);
    node->getMatrix()->content();
    cout<<"ID: "<<node->getID()<<endl;
    cout<<"parent: "<<node->getParent()<<endl;
    cout<<"cost: "<<node->getCost()<<endl;
    cout<<"unvisited number: "<<node->getUnvisited().size()<<endl;

    delete node;
    delete matrix;
    return 0;
}
