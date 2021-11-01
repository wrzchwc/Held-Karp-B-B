#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include "HeldKarpAlgortihm.h"

void HeldKarpAlgortihm::travellingSalesman(AdjacencyMatrix *matrix) {
    int size = matrix->getSize();
    int *vertexes = matrix->getVertexes(true);
    vector<int> set(vertexes, vertexes + size);
    map<string, int> costs;

    for (int i = 1; i < size; i++) {
        costs[to_string(i)] = matrix->getData(0, i);
    }

    for (int i = 1; i < 3; i++) {
        //subset is a set of vertices, we go through
        for (auto &subset: getSubsets(vertexes, size, i)) {
            cout << "via: " << getKey(subset) << endl;
            vector<int> diff; //each vertex in the diff is a vertex we can get to
            set_difference(set.begin() + 1, set.end(), subset.begin(), subset.end(), inserter(diff, diff.begin()));
            for (int d: diff) {
                cout << "to " << d << ": ";
                //new cost is a sum of cost of going through subset and final fragment
                auto old_key = getKey(subset);
                auto new_key = to_string(d).append(getKey(subset));
                int value;
                if (subset.size() == 1) {
                    value = costs[old_key] + matrix->getData(subset.at(0), d);
                } else {
                    vector<int> min_values;
                    for (int j = 0; j < subset.size(); j++) {
                        auto tmp = subset.at(j);
                        subset.erase(subset.begin() + j);
                        string key = to_string(tmp).append(getKey(subset));
                        min_values.push_back(costs[key] + matrix->getData(tmp, d));
                        subset.insert(subset.begin() + j, tmp);
                    }
                    value = *min_element(min_values.begin(), min_values.end());
                }
                cout << value << endl;
                costs[new_key] = value;
            }
            cout << endl;
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








