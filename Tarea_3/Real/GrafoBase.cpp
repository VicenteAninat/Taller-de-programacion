#include "GrafoBase.h"
#include <limits>

const long long GrafoBase::INF = numeric_limits<long long>::max() / 2;

GrafoBase::GrafoBase() {
    this->n = 0;
    this->s = 0;
    this->t = 0;
    this->solved = false;
    this->graph = initializeEmptyGraph();
}

GrafoBase::GrafoBase(int n) {
    this->n = n;
    this->solved = false;
    this->graph = initializeEmptyGraph();
}

GrafoBase::GrafoBase(int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    this->solved = false;
    this->graph = initializeEmptyGraph();
}

vector<list<Edge*>> GrafoBase::initializeEmptyGraph() {
    vector<list<Edge*>> graph = vector<list<Edge*>>(n);
    for (int i = 0; i < n; i++) {
        graph[i] = list<Edge*>();
    }
    return graph;
}

void GrafoBase::addEdge(int origin, int destination, long long capacity) {
    Edge* e1 = new Edge(origin, destination, capacity);
    Edge* e2 = new Edge(destination, origin, 0);
    e1->residual = e2;
    e2->residual = e1;
    e1->flow = 0;
    e2->flow = 0;
    graph[origin].push_back(e1);
    graph[destination].push_back(e2);
}

long long GrafoBase::getMaxFlow() {
    execute();
    return maxFlow;
}

vector<list<Edge*>> GrafoBase::getGraph() {
    execute();
    return graph;
}

void GrafoBase::execute() {
    if (!solved) {
        solve();
        solved = true;
    }
}

void GrafoBase::printGraph(){
    for (int i = 0; i < graph.size(); i++) {
        for (Edge* e : graph[i]) {
            cout << e->toString(s, t) << endl;
        }
    }
}
