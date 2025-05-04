#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Vertex.h"
#include <unordered_map>

using namespace std;

class Graph {
    public:
    // Atributos
    vector<vector<Vertex>> adjList;
    
    unordered_map<int, Vertex*> vertexes; // Conjunto de vértices
    unordered_map<int, Edge*> edges; // Conjunto de aristas

    // Metodos
    void addVertex(Vertex* vertex);

    void printGraph();

    void printGraphLite();
};    

#endif
