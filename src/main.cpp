
#include "KruskalSolver.h"
#include "PrimSolver.h"
#include "ParseGraphFile.h"
#include <iostream>
#include <cstring>

void run(char* graphType, char* location, char* solverType) {
    auto * csrGraph = new CSRGraph();
    Solver* solver;

    if (!strcmp(graphType, "COO")) {
        readCooFile(location, csrGraph);
    } else if (!strcmp(graphType, "CSR")) {
        readCsrFile(location, csrGraph);
    } else {
        throw std::invalid_argument(std::string("Invalid Graph Type: ") + graphType);
    }

    if (!strcmp(solverType, "PRIM")) {
        solver = new PrimSolver(csrGraph);
    } else if (!strcmp(solverType, "KRUSKAL")) {
        solver = new KruskalSolver(csrGraph);
    } else {
        throw std::invalid_argument(std::string("Invalid Solver Type: ") + solverType);
    }

    Edge mstEdges[csrGraph->numberOfNodes - 1] = {};
    solver->solve(mstEdges);

    for (int x = 0; x < csrGraph->numberOfNodes - 1; x++) {

        printf("\nEdge %d, NodeA %d, Node B %d, Weight %d", x, mstEdges[x].nodeA, mstEdges[x].nodeB, mstEdges[x].weight);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    run(argv[1], argv[2], argv[3]);

}
