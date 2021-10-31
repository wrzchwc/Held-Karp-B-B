#ifndef INC_2_HELDKARPALGORTIHM_H
#define INC_2_HELDKARPALGORTIHM_H

#include <set>
#include <vector>
#include "../adjacency_matrix/AdjacencyMatrix.h"

class HeldKarpAlgortihm {
private:
    static vector<vector<int>> getSubsets(int *array, int arraySize, int subsetSize);
    static string getKey(const vector<int>& subset);

public:
    static void travellingSalesman(AdjacencyMatrix* matrix);
};


#endif //INC_2_HELDKARPALGORTIHM_H
