#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/m8.txt");
    matrix->content();
    matrix->setData(89, 0, 0);
    matrix->setData(98, 2, 2);
    matrix->setData(65, 4, 4);
    cout<<endl;
    matrix->content();


    delete matrix;
    return 0;
}
