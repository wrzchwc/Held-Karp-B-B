#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/BranchBound.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/m16.txt");
    BranchBound::travellingSalesman(matrix);
    delete matrix;
    return 0;
}
