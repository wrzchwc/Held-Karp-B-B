#ifndef INC_2_HELDKARPALGORITHM_H
#define INC_2_HELDKARPALGORITHM_H

#include <set>
#include <vector>
#include "../adjacency_matrix/AdjacencyMatrix.h"

class HeldKarpAlgorithm {
private:
    static vector<vector<int>> getSubsets(int *array, int arraySize, int subsetSize);
    static string getKey(const vector<int>& subset);

public:
    static void travellingSalesman(AdjacencyMatrix* matrix);
};


#endif //INC_2_HELDKARPALGORITHM_H
