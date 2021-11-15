#include <algorithm>
#include <iterator>
#include <string>
#include "HeldKarp.h"

void HeldKarp::travelling_salesman() {
    int size = matrix->getSize();
    int *vertexes = matrix->getVertexes(true);
    vector<int> set(vertexes, vertexes + size);


    for (int i = 1; i < size - 1; i++) {
        for (vector<int> subset: getSubsets(vertexes, size, i)) {
            vector<int> diff;
            set_difference(set.begin() + 1, set.end(), subset.begin(), subset.end(), inserter(diff, diff.begin()));
            for (int d: diff) {
                vector<int> new_key({d});
                new_key.insert(new_key.end(), subset.begin(), subset.end());
                int value;
                if (subset.size() == 1) {
                    value = costs[subset] + matrix->getData(subset.at(0), d);
                } else {
                    value = get_optimum(subset, d);
                }
                costs[new_key] = value;
            }
        }
    }

    cout << get_hamiltonian_cycle(vertexes)<<endl;
}

vector<vector<int>> HeldKarp::getSubsets(int *array, int arraySize, int subsetSize) {
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

HeldKarp::HeldKarp(AdjacencyMatrix *matrix) {
    this->matrix = matrix;

    for (int i = 1; i < matrix->getSize(); i++) {
        this->costs[{i}] = matrix->getData(0, i);
    }
}

int HeldKarp::get_hamiltonian_cycle(int *array) {
    auto size = matrix->getSize();
    auto set = getSubsets(array, size, size - 1).at(0);
    vector<int> tsp_set;
    for (int i = 0; i < set.size(); i++) {
        auto tmp = set.at(i);
        set.erase(set.begin() + i);
        vector<int> key({tmp});
        key.insert(key.end(), set.begin(), set.end());
        tsp_set.push_back(costs[key] + matrix->getData(tmp, 0));
        set.insert(set.begin() + i, tmp);
    }

    return *min_element(tsp_set.begin(), tsp_set.end());
}

int HeldKarp::get_optimum(vector<int> &subset, int vertex) {
    vector<int> set;
    for (int i = 0; i < subset.size(); i++) {
        auto tmp = subset.at(i);
        subset.erase(subset.begin() + i);
        vector<int> key({tmp});
        key.insert(key.end(), subset.begin(), subset.end());
        set.push_back(costs[key] + matrix->getData(tmp, vertex));
        subset.insert(subset.begin() + i, tmp);
    }
    return *min_element(set.begin(), set.end());
}


HeldKarp::~HeldKarp() = default;










