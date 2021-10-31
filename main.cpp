#include <iostream>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "held_karp/HeldKarpAlgortihm.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("wiki.txt");
    HeldKarpAlgortihm::travellingSalesman(matrix);

    return 0;
}
