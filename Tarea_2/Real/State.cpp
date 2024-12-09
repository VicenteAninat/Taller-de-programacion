#include "State.h"

State::State() {
    //No hace nada
}

State::State(Graph graph) {
    this->graph = graph;
    // sacamos todos los vertices ya eue son llaves en el mapa
    for (auto const& par : graph.vertexNeighbors) {
        uncoloredVertices.insert(par.first);
    }
}

int State::getVertex(){
    auto it = uncoloredVertices.begin();
    if (it==uncoloredVertices.end()) { // caso vacio
        return -1; // OJO: convenimos que si no hay mas entonces retornamos -1
    }
    return *it;
}

void State::pushColorSelectVertex(int vertex, int color) {
    graph.vertexColor[vertex] = color;
    coloredVertices.insert(vertex);
    uncoloredVertices.erase(vertex);
}

bool State::isVertexColored(int vertex) {
    return coloredVertices.find(vertex) != coloredVertices.end();
}

bool State::isAllColored() {
    return uncoloredVertices.size() == 0;
}

void State::printColor() {
    for (auto const& par : graph.vertexColor) {
        cout << par.first << "->" << par.second << " ";
    }
    cout << endl;
}

void State::incrementColor() {
    int c = graph.getNumberOfColors();
    availableColors.insert(c);
}