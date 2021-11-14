#include <iostream>
#include <map>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/BranchBound.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/tsp_17.txt");
    matrix->content();
    BranchBound::travellingSalesman(matrix);

    delete matrix;
    return 0;
}
