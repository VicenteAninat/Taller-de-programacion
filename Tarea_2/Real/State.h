#ifndef STATE_H
#define STATE_H

#include "Graph.h"

class State {
    public:
    // Atributos
    set<int> uncoloredVertices;
    set<int> coloredVertices;
    set<int> availableColors;

    // Metodos
    Graph graph; // va a ser el grafo semi coloreado durante le desarrolo del algoritmo
    State() {
    }
    State(Graph graph) {
        this->graph = graph;
        // sacamos todos los vertices ya eue son llaves en el mapa
        for (auto const& par : graph.vertexNeighbors) {
            uncoloredVertices.insert(par.first);
        }
    }
    int getVertex(){
        auto it = uncoloredVertices.begin();
        if (it==uncoloredVertices.end()) { // caso vacio
            return -1; // OJO: convenimos que si no hay mas entonces retornamos -1
        }
        return *it;
    }
    // sacamos el vertice no coloreados lo agregamos a los coloreados y lo coloreamos en graph
    void pushColorSelectVertex(int vertex, int color) {
        graph.vertexColor[vertex] = color;
        coloredVertices.insert(vertex);
        uncoloredVertices.erase(vertex);
    }

    // consultamos si el vertice esta coloreado
    bool isVertexColored(int vertex) {
        // find retorna un iterador, si el iterador es igual a end() entonces no se encontro
        return coloredVertices.find(vertex) != coloredVertices.end();
    }

    bool isAllColored() {
        return uncoloredVertices.size() == 0;
    }

    void printColor() {
        for (auto const& par : graph.vertexColor) {
            cout << par.first << "->" << par.second << " ";
        }
        cout << endl;
    }

    void incrementColor() {
        int c = graph.getNumberOfColors();
        availableColors.insert(c);
    }

};

#endif