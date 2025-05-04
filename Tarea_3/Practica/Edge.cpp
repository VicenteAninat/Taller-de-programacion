#include "Edge.h"

Edge::Edge() {

}

Edge::Edge(int id, Vertex* originVertex, Vertex* destinationVertex, int flowCapacity) {
    this->id = id;
    this->originVertex = originVertex;
    this->destinationVertex = destinationVertex;
    this->flowCapacity = flowCapacity;
}

void Edge::printEdge() {
    cout << "Edge ID: " << to_string(this->id) << endl;
    cout << "Origin Vertex: " << to_string(this->originVertex->id) << endl;
    cout << "Destination Vertex: " << to_string(this->destinationVertex->id) << endl;
    cout << "Flow Capacity: " << to_string(this->flowCapacity) << endl;
    cout << endl;
}