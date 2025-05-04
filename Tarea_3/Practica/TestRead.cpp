#include "Read.h"

int main () {
    string fileName = "ejemplo";
    Read read;
    Graph* graph = read.loadGraph(fileName);
    graph->printGraph();
}