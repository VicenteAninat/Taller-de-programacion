#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Vertex;

class Edge {
    public:
    // Atributos
    int id;
    Vertex* originVertex;
    Vertex* destinationVertex;
    int flowCapacity;

    // Metodos
    Edge();

    Edge(int id, Vertex* originVertex, Vertex* destinationVertex, int flowCapacity);

    void printEdge();
};

#endif
