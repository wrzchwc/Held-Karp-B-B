#ifndef INC_2_BRANCHBOUND_H
#define INC_2_BRANCHBOUND_H

#include "../adjacency_matrix/AdjacencyMatrix.h"

class BranchBound {
private:
    static int reduceRows(AdjacencyMatrix *matrix);

    static int reduceColumns(AdjacencyMatrix *matrix);

    static void infiniteRow(AdjacencyMatrix *matrix, int row);

    static void infiniteColumn(AdjacencyMatrix *matrix, int column);

public:
    static void travellingSalesman(AdjacencyMatrix *matrix);

    static int reduceMatrix(AdjacencyMatrix *matrix);

    static void infiniteMatrix(AdjacencyMatrix *matrix, int row, int column);
};


#endif //INC_2_BRANCHBOUND_H
