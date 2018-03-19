

//#include "ParseGraphFile.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "PrimSolver.h"


void readGraph(char *location, CSRGraph *csrGraph) {

    std::string graphType;
    size_t numberOfNodes;
    size_t numberOfEdges;


    std::ifstream inFile;

    inFile.open("/home/dan/CSC_final_year/CSC3002_project/code/SolvingProgram/resources/testGraph.txt");

    if (!inFile) {
        std::cout << "unable to open file";
        exit(1);
    }

    getline(inFile, graphType);
    std::string temp;
    getline(inFile, temp);
    std::istringstream stream(temp);
    stream >> numberOfNodes;
    getline(inFile, temp);
    std::istringstream stream2(temp);
    stream2 >> numberOfEdges;

    csrGraph->numberOfNodes = numberOfNodes;
    csrGraph->numberOfEdges = numberOfEdges;

    csrGraph->nodeList = new int[numberOfNodes + 1];
    csrGraph->nodeList[0] = 0;
    csrGraph->edgeList = new int[numberOfEdges];
    csrGraph->weightsList = new int[numberOfEdges];


    std::cout << graphType << "\n" << numberOfNodes << "\n" << numberOfEdges << "\n";


    std::string line;
    size_t count = 0;
    while (count < numberOfEdges) {
        getline(inFile, line);
        std::cout << line << " count - " << count << "\n";

        std::istringstream is(line);

        int index;
        is >> index;

        int n;
        while (is >> n) {
            printf("%d ", n);
            csrGraph->edgeList[count] = n;
            count++;
        }
        csrGraph->nodeList[index + 1] = count; //TODO change nodelist to size_t
        printf("\n");
    }

    count = 0;
    while (count < numberOfEdges) {
        getline(inFile, line);
        std::cout << line << " count - " << count << "\n";

        std::istringstream is(line);

        int index;
        is >> index;

        int n;
        while (is >> n) {
            printf("%d ", n);
            csrGraph->weightsList[count] = n;
            count++;
        }
        printf("\n");
    }


//    while (inFile >> x) {
//        printf("\n%d\n", x);
//    }
//    inFile >> x;
//    printf("\n%d\n", x);


    inFile.close();

//    return csrGraph;
}


