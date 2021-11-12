#include <iostream>
#include <map>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("../cmake-build-debug/instances/gr24.txt");
    delete matrix;


    return 0;
}
