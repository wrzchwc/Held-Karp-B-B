# Held-Karp Branch & Bound

## Context

The project was created as one of the tasks during Effective Algorithms Design course which I took part in during my
studies at [Wroclaw University of Science and Technology](https://pwr.edu.pl/en/).

## Introduction

The task aimed to create the implementation
of [Held-Karp algorithm](https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm) and an algorithm based on
the [Branch & Bound algorithms design paradigm](https://en.wikipedia.org/wiki/Branch_and_bound). The B&B based algorithm
features `low cost method` to traverse state space tree.

The process of verifying the accuracy and correctness of created algorithms was based on the test instances come from
the following sources:

- [1st source](http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/pea-stud/tsp)
- [2nd source](http://jaroslaw.rudy.staff.iiar.pwr.wroc.pl/files/pea/instances.zip)

The instances are also available in the `/instances` directory in this repository.

## Application modes

`Demonstrate` - mode designed to present application functioning for the individual instance. User can choose the
desired algorithm and then after entering the name of file containing matrix the TSP is being solved and the result as
well as the time of the execution is displayed. **The instance file should be placed inside the /instances directory
located in the same directory as the executable file.**

`Execute` - mode designed to perform measurement and research on the test instances. After providing the name of the
`configuration file` the application solves TSP for specified instances given number of times and saves the results to
the `output csv files`.

### Configuration file

The configuration file should have .txt extension. The required format presents as follows:

`name` `number`  
`name`  `number`  
(...)  
`name` `number`

where:

- `name` - name of the file containing test instance
- `number` - number of times each instance should be solved

### Output csv files

Depending on the chosen algorithm the results of time measurement will be solved in `held_karp.csv` file
or `branch_bound.csv` file. The first line contains the row contains the names of all instances read from configuration
files. The following lines contain the times of executions for given instances.

## Instance format
The instances in the application are loaded from the txt files. The instances represent graphs as the adjacency matrices. 
The required format of the instance presents as follows:  
`name`  
`x` `x` `x`  
`x` `x` `x`  
`x` `x` `x`  
`solution`

where:

- `name` - name of the instance
- `x` - weight of given edge 
- `solution` - Minimal Hamiltonian cycle (TSP solution); this parameter is optional



