#include "Graph.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Read {
    public:
    // Atributos

    // Metodos
    int countVertexes(int counter, istringstream line);

    Graph* loadGraph(string fileName);
};