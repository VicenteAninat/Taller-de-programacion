#include "Read.h"

int main () {
    Read r;
    int c = 0;
    c = r.contarVertices("ejemplo", c);
    cout << "Numero de Vertices: " << c << endl;

    Dinic* d = r.readDinic("ejemplo", c);

    d->printGraph();

    /*
    // Imprimir cada arista del grafo
    for (int i = 0; i < d->graph.size(); i++) {
        for (Edge* e : d->graph[i]) {
            cout << e->toString(d->s, d->t) << endl;
        }
    }
    */
}
