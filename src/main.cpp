#include <iostream>
#include "PrimSolver.h"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    Edge edge = Edge();
//    CSRGraph csrGraph = CSRGraph();
//    PrimSolver primsolver = PrimSolver(&csrGraph);
//    primsolver.solve(&edge);
//    int y = x.edgeList[0];
//    return 0;




    CSRGraph csrGraph = CSRGraph();
    csrGraph.numberOfNodes = 10;
    csrGraph.numberOfEdges = 42;
    int nodeList[csrGraph.numberOfNodes + 1] ={0, 4, 8, 13, 16, 20, 24, 28, 34, 39, 42};
    int edgeList[csrGraph.numberOfEdges] = {1, 2, 8, 9, 0, 2, 7, 8, 0, 1, 3, 4, 7, 2, 4, 5, 2, 3, 5, 7, 3, 4, 6, 7, 5, 7, 8, 9, 1, 2, 4, 5, 6, 8, 0, 1, 6, 7, 9, 0, 6, 8};
    int weightList[csrGraph.numberOfEdges] = {2, 9, 4, 6, 2, 9, 8, 2, 9, 9, 4, 5, 7, 4, 1, 4, 5, 1, 3, 9, 4, 3, 18, 10, 18, 8, 9, 9, 8, 7, 9, 10, 8, 9, 4, 2, 9, 9, 3, 6, 9, 3};

    csrGraph.nodeList = new int[csrGraph.numberOfNodes + 1];
    csrGraph.edgeList = new int[csrGraph.numberOfEdges];
    csrGraph.weightsList = new int [csrGraph.numberOfEdges];
    for (int i = 0; i <= csrGraph.numberOfNodes; i++) {
        csrGraph.nodeList[i] = nodeList[i];
    }
    for (int i = 0; i < csrGraph.numberOfEdges; i++) {
        csrGraph.edgeList[i] = edgeList[i];
        csrGraph.weightsList[i] = weightList[i];
    }
    PrimSolver primSolver = PrimSolver(&csrGraph);
    Edge mstEdges[csrGraph.numberOfNodes - 1] = {};
    primSolver.solve(mstEdges);

    Edge knownMstEdges[csrGraph.numberOfNodes - 1] = {};
    knownMstEdges[0] = Edge(0, 1, 2);
    knownMstEdges[1] = Edge(1, 8, 2);
    knownMstEdges[2] = Edge(8, 9, 3);
    knownMstEdges[3] = Edge(1, 7, 8);
    knownMstEdges[4] = Edge(7, 2, 7);
    knownMstEdges[5] = Edge(2, 3, 4);
    knownMstEdges[6] = Edge(3, 4, 1);
    knownMstEdges[7] = Edge(4, 5, 3);
    knownMstEdges[8] = Edge(7, 6, 8);

    for (int x = 0; x < csrGraph.numberOfNodes - 1; x++) {
//        EXPECT_EQ(mstEdges[x], knownMstEdges[x]);
        printf("\n%s", mstEdges[x] == knownMstEdges[x] ? "True" : "False");

        printf("\nEdge %d, NodeA %d, Node B %d, Weight %d", x, mstEdges[x].nodeA, mstEdges[x].nodeB, mstEdges[x].weight);
    }
    printf("\n");
}