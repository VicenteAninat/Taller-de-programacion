#include "Graph.h"

void Graph::addVertex(Vertex* vertex) {
    this->vertexes.insert({vertex->id, vertex});
}

void Graph::printGraph() {
    for (auto const& vertex : this->vertexes) {
        vertex.second->printVertex();
    }
    for (auto const& edge : this->edges) {
        edge.second->printEdge();
    }
}

void Graph::printGraphLite() {

}