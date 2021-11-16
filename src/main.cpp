#include <iostream>
#include <vector>
#include "adjacency_matrix/AdjacencyMatrix.h"
#include "branch_bound/BranchBound.h"
#include "branch_bound/Node.h"
#include "branch_bound/SpaceStateTree.h"
#include "held_karp/HeldKarp.h"

using namespace std;

void header() {
    cout << "Effective Algorithms Design" << endl;
    cout << "Project 2 & 3 - TSP using Held-Karp algorithm & B&B method " << endl;
    cout << "Jakub Wierzchowiec, November 2021" << endl;

    cout << endl;
}

int algorithms() {
    auto option = 0;
    cout << "Available algorithms" << endl;
//    cout << "0 Held-Karp" << endl;
    cout << "1 Branch and Bound" << endl;
    cout << "2 Quit" << endl;
    cout << "> ";
    cin >> option;
    return option;
}

void demonstrate(int algorithm) {
    string path = "../instances/";
    string name;
    cout << "Instance name: ";
    cin >> name;
    auto matrix = new AdjacencyMatrix(path.append(name));
    cout << "Minimal Hamiltonian path: ";

    if (algorithm == 0) {
        auto heldKarp = new HeldKarp(matrix);
        heldKarp->travelling_salesman();
        delete heldKarp;
    } else if (algorithm == 1) {
        BranchBound::travellingSalesman(matrix);
    }
    system("pause");
    delete matrix;
}

int main() {
    header();
    while (true) {
        auto choice = algorithms();

        if (choice == 2) {
            break;
        }

        demonstrate(choice);
    }

    return 0;
}
