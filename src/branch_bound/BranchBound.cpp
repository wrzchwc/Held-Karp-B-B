#include "../adjacency_matrix/AdjacencyMatrix.h"
#include "BranchBound.h"

void BranchBound::travellingSalesman(AdjacencyMatrix *matrix) {

}

int BranchBound::reduceMatrix(AdjacencyMatrix *matrix) {
    return reduceRows(matrix) + reduceColumns(matrix);
}

int BranchBound::reduceRows(AdjacencyMatrix *matrix) {
    auto reductionCost = 0;
    return reductionCost;
}

int BranchBound::reduceColumns(AdjacencyMatrix *matrix) {
    auto reductionCost = 0;
    return reductionCost;
}

void BranchBound::infiniteMatrix(AdjacencyMatrix *matrix, int row, int column) {
    infiniteRow(matrix, row);
    infiniteColumn(matrix, column);
    matrix->setData(INT_MAX, column, 0);
}

void BranchBound::infiniteRow(AdjacencyMatrix *matrix, int row) {
    for (int i = 0; i < matrix->getSize(); i++) {
        matrix->setData(INT_MAX, row, i);
    }
}

void BranchBound::infiniteColumn(AdjacencyMatrix *matrix, int column) {
    for (int i = 0; i < matrix->getSize(); i++) {
        matrix->setData(INT_MAX, i, column);
    }
}









