#ifndef INC_2_BRANCHBOUND_H
#define INC_2_BRANCHBOUND_H

#include "../adjacency_matrix/AdjacencyMatrix.h"

class BranchBound {
private:
    static int reduceRows(AdjacencyMatrix *matrix);

    static int reduceColumns(AdjacencyMatrix *matrix);

    static void infiniteRow(AdjacencyMatrix *matrix, int row);

    static void infiniteColumn(AdjacencyMatrix *matrix, int column);

    static void infiniteDiagonal(AdjacencyMatrix *matrix);

    static int reduceMatrix(AdjacencyMatrix *matrix);

    static void infiniteMatrix(AdjacencyMatrix *matrix, int row, int column);

public:
    static double travellingSalesman(AdjacencyMatrix *adjacencyMatrix);
};


#endif //INC_2_BRANCHBOUND_H
