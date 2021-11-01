#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include "HeldKarp.h"

void HeldKarp::travelling_salesman() {
    int size = matrix->getSize();
    int *vertexes = matrix->getVertexes(true);
    vector<int> set(vertexes, vertexes + size);


    for (int i = 1; i < size - 1; i++) {
        //subset is a set of vertices, we go through
        for (auto &subset: getSubsets(vertexes, size, i)) {
//            cout << "via: " << getKey(subset) << endl;
            vector<int> diff; //each vertex in the diff is a vertex we can get to
            set_difference(set.begin() + 1, set.end(), subset.begin(), subset.end(), inserter(diff, diff.begin()));
            for (int d: diff) {
//                cout << "to " << d << ": ";
                //new cost is a sum of cost of going through subset and final fragment
                auto new_key = to_string(d).append(getKey(subset));
                int value;
                if (subset.size() == 1) {
                    value = costs[getKey(subset)] + matrix->getData(subset.at(0), d);
                } else {
                    value = get_optimum(subset, d);
                }
//                cout << value << endl;
                costs[new_key] = value;
            }
//            cout << endl;
        }
    }

    cout << get_hamiltonian_cycle(vertexes);
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

string HeldKarp::getKey(const vector<int> &subset) {
    string key;
    for (int s: subset) {
        key.append(to_string(s));
    }
    return key;
}

HeldKarp::HeldKarp(AdjacencyMatrix *matrix) {
    this->matrix = matrix;

    for (int i = 1; i < matrix->getSize(); i++) {
        this->costs[to_string(i)] = matrix->getData(0, i);
    }

//    cout<<"Mapped values"<<endl;
//    for (const auto& cost:costs) {
//        cout<<cost.first<<" "<<cost.second<<endl;
//    }
}

int HeldKarp::get_hamiltonian_cycle(int *array) {
    auto size = matrix->getSize();
    auto set = getSubsets(array, size, size - 1).at(0);
    vector<int> tsp_set;
    for (int i = 0; i < set.size(); i++) {
        auto tmp = set.at(i);
        set.erase(set.begin() + i);
        string key = to_string(tmp).append(getKey(set));
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
        string key = to_string(tmp).append(getKey(subset));
        set.push_back(costs[key] + matrix->getData(tmp, vertex));
        subset.insert(subset.begin() + i, tmp);
    }
    return *min_element(set.begin(), set.end());
}


HeldKarp::~HeldKarp() = default;










