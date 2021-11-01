#include <iostream>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "held_karp/HeldKarpAlgorithm.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("wiki.txt");
    HeldKarpAlgorithm::travellingSalesman(matrix);

    return 0;
}
