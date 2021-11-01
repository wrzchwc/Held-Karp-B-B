#include <iostream>
#include <map>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "held_karp/HeldKarp.h"

using namespace std;

int main() {
    auto matrix = new AdjacencyMatrix("m16.txt");
    auto held_karp = new HeldKarp(matrix);
    held_karp->travelling_salesman();

    return 0;
}
