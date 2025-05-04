#include "Edge.h"
#include <iostream>

int main () {
    int id1 = 1;
    int id2 = 2;

    Edge* e = new Edge(id1, id2, 10);

    if (e->isResidual()) {
        cout << "Es residual" << endl;
    } else {
        cout << "No es residual" << endl;
    }

    cout << "Capacidad restante: " << e->remainingCapacity() << endl;

    e->augment(5);

    cout << "Capacidad restante: " << e->remainingCapacity() << endl;

    printf("%s\n", e->toString(id1, id2).c_str());
}