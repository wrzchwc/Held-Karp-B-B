#include <algorithm>
#include <string>
#include <map>
#include "HeldKarpAlgortihm.h"

void HeldKarpAlgortihm::travellingSalesman(AdjacencyMatrix *matrix) {
    auto size = matrix->getSize();
    map<string, int> mappings;
    for (int i = 1; i < size; i++) {
        mappings[to_string(i)] = matrix->getData(i, 0);
    }




}

vector<vector<int>> HeldKarpAlgortihm::getSubsets(int *array, int arraySize, int subsetSize) {
    auto size = arraySize - 1;
    auto binary = new int[size];
    vector<vector<int>> subsets;

    for (int i = 0; i < size; i++) {
        binary[i] = i >= size - subsetSize ? 1 : 0;
    }

    do {
        vector<int> tmp;
        for (int i = 0; i < size; i++) {
            if (binary[i] == 1) {
                tmp.push_back(array[i + 1]);
            }
        }
        subsets.push_back(tmp);
    } while (next_permutation(binary, binary + size));

    return subsets;
}

string HeldKarpAlgortihm::getKey(const vector<int> &subset) {
    string key;
    for (int s: subset) {
        key.append(to_string(s));
    }
    return key;
}






