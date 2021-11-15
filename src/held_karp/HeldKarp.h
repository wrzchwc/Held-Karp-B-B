#ifndef INC_2_HELDKARP_H
#define INC_2_HELDKARP_H

#include <map>
#include <vector>
#include "../adjacency_matrix/AdjacencyMatrix.h"

class HeldKarp {
private:
    static vector<vector<int>> getSubsets(int *array, int arraySize, int subsetSize);

    int get_hamiltonian_cycle(int *array);

    int get_optimum(vector<int> &subset, int vertex);

    map<vector<int>, int> costs;

    AdjacencyMatrix *matrix;


public:
    explicit HeldKarp(AdjacencyMatrix *matrix);

    virtual ~HeldKarp();

    void travelling_salesman();


};


#endif //INC_2_HELDKARP_H
