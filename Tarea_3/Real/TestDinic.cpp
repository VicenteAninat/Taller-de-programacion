#include "Dinic.h"
#include <iostream>

int main () {
    int n = 10;
    int s = 8;
    int t = 9;

    Dinic* solver = new Dinic(n, s, t);

    solver->addEdge(0, 1, 10);
    solver->addEdge(0, 2, 10);
    solver->addEdge(1, 3, 15);
    solver->addEdge(2, 4, 25);
    solver->addEdge(3, 2, 6);
    solver->addEdge(3, 5, 10);
    solver->addEdge(4, 5, 10);
    solver->addEdge(3, 7, 5);
    solver->addEdge(6, 1, 5);

    solver->addEdge(8, 0, solver->INF);
    solver->addEdge(8, 6, solver->INF);

    solver->addEdge(5, 9, solver->INF);
    solver->addEdge(7, 9, solver->INF);

    // Imprimir cada arista del grafo
    for (int i = 0; i < solver->graph.size(); i++) {
        for (Edge* e : solver->graph[i]) {
            cout << e->toString(s, t) << endl;
        }
    }

    cout << "Flujo maximo: " << solver->getMaxFlow() << endl;
    //cout << solver->maxFlow << endl;
}