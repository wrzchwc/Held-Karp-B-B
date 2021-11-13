#include <algorithm>
#include <vector>
#include "../adjacency_matrix/AdjacencyMatrix.h"
#include "BranchBound.h"
#include "Node.h"
#include "SpaceStateTree.h"

void BranchBound::travellingSalesman(AdjacencyMatrix *adjacencyMatrix) {
    auto vertexes = adjacencyMatrix->getVertexes(false);
    auto size = adjacencyMatrix->getSize();
    auto matrix = new AdjacencyMatrix(adjacencyMatrix);
    infiniteDiagonal(matrix);
    auto reductionCost = reduceMatrix(matrix);
    vector<int> unvisited(vertexes + 1, vertexes + size);
    auto node = new Node(0, nullptr, matrix, reductionCost, unvisited);
    auto tree = new SpaceStateTree(node);

    while (!(unvisited.empty())) {
        auto unvisitedSize = unvisited.size();
        cout<<"current cost: "<<node->getCost();

        for (int i = 0; i < unvisitedSize; i++) {
            auto tmp = new AdjacencyMatrix(matrix);
            infiniteMatrix(tmp, node->getID(), unvisited.at(i));
            auto cost = reduceMatrix(tmp) + node->getCost() + matrix->getData(node->getID(), unvisited.at(i));
            vector<int> newUnvisited(unvisited);
            newUnvisited.erase(newUnvisited.begin()+i);
            auto newNode = new Node(unvisited.at(i), node, tmp, cost, newUnvisited);
            tree->addNode(newNode);
        }

        node = tree->getMinimalLeaf();
        cout<<" new cost "<<node->getCost()<<endl;
        unvisited = node->getUnvisited();
        matrix = node->getMatrix();
    }

    cout << node->getCost() << endl;
    delete tree;
}

int BranchBound::reduceMatrix(AdjacencyMatrix *matrix) {
    return reduceRows(matrix) + reduceColumns(matrix);
}

int BranchBound::reduceRows(AdjacencyMatrix *matrix) {
    auto reductionCost = 0;
    auto size = matrix->getSize();
    for (int i = 0; i < size; i++) {
        auto minimum = INT_MAX;
        for (int j = 0; j < size; j++) {
            auto value = matrix->getData(i, j);
            if (value < INT_MAX && value < minimum) {
                minimum = value;
            }
        }

        if (minimum < INT_MAX) {
            reductionCost += minimum;
        }

        for (int j = 0; j < size; j++) {
            auto value = matrix->getData(i, j);
            if (value > 0 && value < INT_MAX && minimum < INT_MAX) {
                matrix->setData(value - minimum, i, j);
            }
        }
    }
    return reductionCost;
}

int BranchBound::reduceColumns(AdjacencyMatrix *matrix) {
    auto reductionCost = 0;
    auto size = matrix->getSize();
    for (int i = 0; i < size; i++) {
        auto minimum = INT_MAX;
        for (int j = 0; j < size; j++) {
            auto value = matrix->getData(j, i);
            if (value < INT_MAX && value < minimum) {
                minimum = value;
            }
        }

        if (minimum < INT_MAX) {
            reductionCost += minimum;
        }

        for (int j = 0; j < size; j++) {
            auto value = matrix->getData(j, i);
            if (value > 0 && value < INT_MAX && minimum < INT_MAX) {
                matrix->setData(value - minimum, j, i);
            }
        }
    }
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

void BranchBound::infiniteDiagonal(AdjacencyMatrix *matrix) {
    for (int i = 0; i < matrix->getSize(); i++) {
        matrix->setData(INT_MAX, i, i);
    }
}









