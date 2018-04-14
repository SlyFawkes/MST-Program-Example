
#ifndef SOLVINGPROGRAM_PARSEGRAPHFILE_H
#define SOLVINGPROGRAM_PARSEGRAPHFILE_H 1


#include <DataStructures/CSRGraph.h>

void readCsrFile(const char *location, CSRGraph *csrGraph);

void readCooFile(const char *location, CSRGraph *csrGraph);


#endif //SOLVINGPROGRAM_PARSEGRAPHFILE_H
