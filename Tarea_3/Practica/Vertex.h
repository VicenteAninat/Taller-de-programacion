#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"
#include <set>
#include <vector>
#include <iostream>

using namespace std;
class Edge;

class Vertex {
    public:
    // Atributos
    int id;
    bool source;
    bool sink;
    vector<Edge*> edges;
    // Podría agregar lista de vecinos

    // Metodos
    Vertex();

    Vertex(int id, bool source, bool sink);

    void addEdge(Edge* edge);

    void printVertex();
};

#endif
