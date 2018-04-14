#include <iostream>
#include <DataStructures/CSRGraph.h>
#include <DataStructures/Edge.h>
#include "KruskalSolver.h"
#include "ParseGraphFile.h"


int main() {

    const char* a = "/home/dan/CSC_final_year/CSC3002_project/code/SolvingProgram/resources/testGraph.txt";

    CSRGraph csrGraph1 = CSRGraph();
    readCsrFile(a, &csrGraph1);


    KruskalSolver primSolver1 = KruskalSolver(&csrGraph1);
    Edge mstEdges1[csrGraph1.numberOfNodes - 1] = {};
    primSolver1.solve(mstEdges1);

    Edge knownMstEdges1[csrGraph1.numberOfNodes - 1] = {};
    knownMstEdges1[0] = Edge(0, 1, 2);
    knownMstEdges1[1] = Edge(1, 8, 2);
    knownMstEdges1[2] = Edge(8, 9, 3);
    knownMstEdges1[3] = Edge(1, 7, 8);
    knownMstEdges1[4] = Edge(7, 2, 7);
    knownMstEdges1[5] = Edge(2, 3, 4);
    knownMstEdges1[6] = Edge(3, 4, 1);
    knownMstEdges1[7] = Edge(4, 5, 3);
    knownMstEdges1[8] = Edge(7, 6, 8);

    for (int x = 0; x < csrGraph1.numberOfNodes - 1; x++) {
        printf("\n%s", mstEdges1[x] == knownMstEdges1[x] ? "True" : "False");

        printf("\nEdge %d, NodeA %d, Node B %d, Weight %d", x, mstEdges1[x].nodeA, mstEdges1[x].nodeB, mstEdges1[x].weight);
    }
    printf("\n");


    const char* b = "/home/dan/CSC_final_year/CSC3002_project/code/SolvingProgram/resources/G64.mtx";


    CSRGraph csrGraph2 = CSRGraph();
    readCooFile(b, &csrGraph2);



    KruskalSolver primSolver2 = KruskalSolver(&csrGraph2);
    Edge mstEdges2[csrGraph2.numberOfNodes - 1] = {};
    primSolver2.solve(mstEdges2);

    for (int x = 0; x < csrGraph2.numberOfNodes - 1; x++) {

        printf("\nEdge %d, NodeA %d, Node B %d, Weight %d", x, mstEdges2[x].nodeA, mstEdges2[x].nodeB, mstEdges2[x].weight);
    }
    printf("\n");

}