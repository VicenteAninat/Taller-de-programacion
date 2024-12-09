#ifndef STATE_H
#define STATE_H

#include "Graph.h"

class State {
    public:
    // Atributos
    set<int> uncoloredVertices;
    set<int> coloredVertices;
    set<int> availableColors;
    Graph graph; // va a ser el grafo semi coloreado durante le desarrolo del algoritmo

    // Metodos
    State();
    State(Graph graph);
    int getVertex();

    void pushColorSelectVertex(int vertex, int color);

    bool isVertexColored(int vertex);

    bool isAllColored();

    void printColor();

    void incrementColor();
};

#endif