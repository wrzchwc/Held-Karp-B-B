#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include "HeldKarpAlgortihm.h"

void HeldKarpAlgortihm::travellingSalesman(AdjacencyMatrix *matrix) {
    int size = matrix->getSize();
    int *vertexes = matrix->getVertexes(true);
    map<string, int> costs;

    for (int i = 1; i < size; i++) {
        costs[to_string(i)] = matrix->getData(0, i);
    }

    for (int i = 1; i < size-1; i++) {
        for (const auto &subset: getSubsets(vertexes, size, i)) {
            cout<<"via: "<<getKey(subset)<<endl;
            for (int j = 1; j < size; j++) {
                //if this if is true, we know, that
                if(count(subset.begin(),  subset.end(), j)==0){
                    cout<<"to "<<j<<": ";
                    cout<<costs[getKey(subset)]+matrix->getData(subset.at(0),j)<<endl;
                    costs[to_string(j).append(getKey(subset))] = costs[getKey(subset)]+matrix->getData(subset.at(0),j);
                }
            }
            cout<<endl;
        }
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






