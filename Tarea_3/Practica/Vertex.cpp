#include "Vertex.h"

Vertex::Vertex() {
    this->id = -1;
    this->source = false;
    this->sink = false;
    this->edges = vector<Edge*>();
}

Vertex::Vertex(int id, bool source, bool sink) {
    this->id = id;
    this->source = source;
    this->sink = sink;
    this->edges = vector<Edge*>();
}

void Vertex::addEdge(Edge* edge) {
    this->edges.push_back(edge);
}

void Vertex::printVertex() {
    cout << "Vertex ID: " << to_string(this->id) << endl;

    if (this->source) {
        cout << "Source: Yes" << endl;
    } else {
        cout << "Source: No" << endl;
    }

    if (this->sink) {
        cout << "Sink: Yes" << endl;
    } else {
        cout << "Sink: No" << endl;
    }

    cout << endl;
    cout << "Edges: " << endl;
    for (Edge* edge : this->edges) {
        edge->printEdge();
    }
    cout << endl;
    cout << endl;
}