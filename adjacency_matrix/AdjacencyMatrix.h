#ifndef ONE_ADJACENCYMATRIX_H
#define ONE_ADJACENCYMATRIX_H

#include <iostream>
#include <fstream>

using namespace std;

class AdjacencyMatrix {
private:
    //dynamic two-dimensional array containing id
    int **matrix;

    //number of vertexes
    int size;

    //name of the matrix
    string name;

    //initializes matrix
    void initializeMatrix();

public:

    //constructor loading graph from file
    explicit AdjacencyMatrix(const string &filepath);

    //destructor
    virtual ~AdjacencyMatrix();

    //returns id stored in a specified row and column
    int getData(int row, int column);

    //returns number of vertexes
    [[nodiscard]] int getSize() const;

    //displays content of the matrix
    void content();

    //returns array containing sorted numbers representing vertexes
    [[nodiscard]] int *getVertexes(bool reversed) const;

    //returns name of the matrix
    [[nodiscard]] const string &getName() const;
};


#endif //ONE_ADJACENCYMATRIX_H
