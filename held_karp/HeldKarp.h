#ifndef INC_2_HELDKARP_H
#define INC_2_HELDKARP_H

#include <map>
#include <vector>
#include "../adjacency_matrix/AdjacencyMatrix.h"

class HeldKarp {
private:
    static vector<vector<int>> getSubsets(int *array, int arraySize, int subsetSize);

    static string getKey(const vector<int> &subset);

    int get_hamiltonian_cycle(int *array);

    int get_optimum(vector<int> &subset, int vertex);

    map<vector<int>, int> costs;

    static void displayKey(vector<int> v);

    AdjacencyMatrix *matrix;


public:
    explicit HeldKarp(AdjacencyMatrix *matrix);

    virtual ~HeldKarp();

    void travelling_salesman();


};


#endif //INC_2_HELDKARP_H
