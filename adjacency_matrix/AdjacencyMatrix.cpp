#include <iostream>
#include <string>
#include "AdjacencyMatrix.h"
#include "../utility/Utility.h"

using namespace std;

void AdjacencyMatrix::content() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int AdjacencyMatrix::getData(int row, int column) {
    return matrix[row][column];
}

AdjacencyMatrix::~AdjacencyMatrix() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    size = 0;
}

int AdjacencyMatrix::getSize() const {
    return size;
}

AdjacencyMatrix::AdjacencyMatrix(const string &filepath) {
    fstream file;
    string tmp;
    this->matrix = nullptr;

    file.open(filepath, ios::in);

    getline(file, tmp);
    this->name = tmp;
    getline(file, tmp);
    this->size = atoi(tmp.c_str());
    initializeMatrix();

    auto row = 0;
    while (getline(file, tmp) && row < size) {
        auto edge = Utility::split(tmp, "[ ]+");
        for (int column = 0; column < size; column++) {
            matrix[row][column] = atoi(edge.at(column).c_str());
        }
        row++;
    }
    file.close();
}


int *AdjacencyMatrix::getVertexes(bool reversed) const {
    int *tmp = new int[size];
    if (reversed) {
        for (int i = size - 1; i >= 0; i--) {
            tmp[i] = i;
        }
    } else {
        for (int i = 0; i < size; i++) {
            tmp[i] = i;
        }
    }

    return tmp;
}

void AdjacencyMatrix::initializeMatrix() {
    matrix = new int *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[this->size];
    }
}

const string &AdjacencyMatrix::getName() const {
    return name;
}
