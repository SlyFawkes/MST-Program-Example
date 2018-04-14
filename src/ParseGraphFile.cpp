

#include <fstream>
#include <iostream>
#include <sstream>

#include "ParseGraphFile.h"
#include "mmio.h"



void readCsrFile(const char *location, CSRGraph *csrGraph) {

    std::string graphType;
    size_t numberOfNodes;
    size_t numberOfEdges;


    std::ifstream inFile;

    inFile.open(location);

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

    inFile.close();

}


void readCooFile(const char *location, CSRGraph *csrGraph) {

    MM_typecode matcode;
    FILE *f;
    int M, N, nz;
    int i, *I, *J;
    int *val;

    f = fopen(location, "r");

    if (mm_read_banner(f, &matcode) != 0) {
        printf("bad bad bad");
    }

    if (mm_read_mtx_crd_size(f, &M, &N, &nz) != 0) {
        printf("mtxcrdsize");
        exit(1);
    }

    I = (int *) malloc(nz * sizeof(int));
    J = (int *) malloc(nz * sizeof(int));
    val = (int *) malloc(nz * sizeof(int));
    int nodeCount[M] = {};


    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    for (i=0; i<nz; i++)
    {
        fscanf(f, "%d %d %d\n", &I[i], &J[i], &val[i]);
        I[i]--;  /* adjust from 1-based to 0-based */
        J[i]--;
        nodeCount[I[i]]++;
        nodeCount[J[i]]++;

    }

    if (f !=stdin) fclose(f);

    size_t numberOfNodes;
    size_t numberOfEdges;

    numberOfNodes = static_cast<size_t>(M);
    numberOfEdges = static_cast<size_t>(nz) * 2;


    csrGraph->numberOfNodes = numberOfNodes;
    csrGraph->numberOfEdges = numberOfEdges;

    csrGraph->nodeList = new int[numberOfNodes + 1];
    csrGraph->nodeList[0] = 0;
    csrGraph->edgeList = new int[numberOfEdges];
    csrGraph->weightsList = new int[numberOfEdges];

    for (int j = 0; j < numberOfNodes; j++) {
        csrGraph->nodeList[j+1] = csrGraph->nodeList[j] + nodeCount[j];
    }

    int edgeCount[M] = {};

    for (int edge = 0; edge < nz; edge++) {
        int node1 = J[edge];
        int node2 = I[edge];
        int weight = val[edge];

        csrGraph->edgeList[csrGraph->nodeList[node1] + edgeCount[node1]] = node2;
        csrGraph->edgeList[csrGraph->nodeList[node2] + edgeCount[node2]] = node1;
        csrGraph->weightsList[csrGraph->nodeList[node1] + edgeCount[node1]] = weight;
        csrGraph->weightsList[csrGraph->nodeList[node2] + edgeCount[node2]] = weight;

        edgeCount[node1]++;
        edgeCount[node2]++;

    }


    for (int x = 0; x < nz*2+1; x++) {
        printf("%d\n", csrGraph->edgeList[x]);
    }

    printf("------------------------------------------------------");
    for (int x = 0; x < M+1; x++) {
        printf("%d, %d, %d\n", csrGraph->nodeList[x], csrGraph->edgeList[csrGraph->nodeList[x]], x);
    }

}