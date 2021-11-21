#include <iostream>
#include <chrono>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/BranchBound.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"
#include "utility/Utility.h"

using namespace std;
using namespace std::chrono;

void header() {
    cout << "Effective Algorithms Design" << endl;
    cout << "Project 2 & 3 - TSP using Held-Karp algorithm & B&B method " << endl;
    cout << "Jakub Wierzchowiec, November 2021" << endl;

    cout << endl;
}

int algorithms() {
    auto option = 0;
    cout << "0 Back" << endl;
    cout << "1 Held-Karp" << endl;
    cout << "2 Branch and Bound" << endl;
    cout << "> ";
    cin >> option;
    return option;
}

int modes() {
    auto option = 0;
    cout << "0 Quit" << endl;
    cout << "1 Demonstrate" << endl;
    cout << "2 Execute" << endl;
    cout << "> ";
    cin >> option;
    return option;
}

void demonstrate(int algorithm) {
    string path = "../instances/";
    string name;
    double time = 0.0;
    cout << "Instance name: ";
    cin >> name;
    auto matrix = new AdjacencyMatrix(path.append(name));
    cout << "Minimal Hamiltonian path: ";

    if (algorithm == 1) {
        auto heldKarp = new HeldKarp(matrix);
        auto start = steady_clock::now();
        heldKarp->travelling_salesman();
        auto end = steady_clock::now();
        time = double(duration_cast<nanoseconds>(end - start).count());
        delete heldKarp;
    } else if (algorithm == 2) {
        time = BranchBound::travellingSalesman(matrix);
    }
    cout << "Time of execution: " << time << " ns" << endl;
    delete matrix;
}

string getSetupFile() {
    string tmp;
    cout << "Enter the name of the initialization file: ";
    cin >> tmp;
    return tmp;
}

void fileNotFound(const string &filepath) {
    cout << "Error! File " << filepath << " not found!" << endl;
}

void saveDouble(double value, const string &filepath, const string &separator, bool endLine) {
    fstream file;
    file.open(filepath, ios::out | ios::app);
    endLine ? file << value << separator << endl : file << value << separator;
    file.close();
}

void saveString(const string &text, const string &filepath, const string &separator, bool endLine) {
    fstream file;
    file.open(filepath, ios::out | ios::app);
    endLine ? file << text << separator << endl : file << text << separator;
    file.close();
}

void saveHeaders(vector<vector<string>> configs, const string &output) {
    for (int i = 0; i < configs.size(); i++) {
        if (i < configs.size() - 1) {
            saveString(configs.at(i).at(0), output, ",", false);
        } else {
            saveString(configs.at(i).at(0), output, "", true);
        }
    }
}


void execute(const string &filepath, int algorithm, const string &output) {
    fstream file(filepath);
    string tmp;
    vector<vector<string>> configs;

    if (file.good()) {

        while (getline(file, tmp)) {
            configs.push_back(Utility::split(tmp, "[ ]+"));
        }

        file.close();
        saveHeaders(configs, output);
        auto iterations = atoi(configs.at(0).at(1).c_str());

        for (int i = 0; i < iterations; i++) {
            for (int j = 0; j < configs.size(); j++) {
                if (atoi(configs.at(j).at(1).c_str()) > i) {
                    auto time = 0.0;
                    auto matrix = new AdjacencyMatrix(configs.at(j).at(0));
                    if (algorithm == 1) {
                        auto heldKarp = new HeldKarp(matrix);
                        auto start = steady_clock::now();
                        heldKarp->travelling_salesman();
                        auto end = steady_clock::now();
                        time = double(duration_cast<nanoseconds>(end - start).count());
                        delete heldKarp;
                    } else if (algorithm == 2) {
                        time = BranchBound::travellingSalesman(matrix);
                    }
                    saveDouble(time, output, ",", j >= configs.size() - 1);
                } else {
                    saveString(" ", output, ",", j >= configs.size() - 1);
                }
            }
        }
    } else {
        fileNotFound(filepath);
    }

}


int main() {
    header();
    while (true) {
        auto mode = modes();

        if (mode == 0) {
            break;
        } else if (mode == 1) {
            while (true) {
                auto algorithm = algorithms();
                if (algorithm == 0) {
                    break;
                } else if (algorithm == 1 || algorithm == 2) {
                    demonstrate(algorithm);
                }
            }

        } else if (mode == 2) {
            while (true) {
                auto algorithm = algorithms();
                if (algorithm == 0) {
                    break;
                } else if (algorithm == 1) {
                    execute(getSetupFile(), algorithm, "held_karp.csv");
                } else if (algorithm == 2) {
                    execute(getSetupFile(), algorithm, "branch_bound.csv");
                }
            }
        }
    }

    return 0;
}
