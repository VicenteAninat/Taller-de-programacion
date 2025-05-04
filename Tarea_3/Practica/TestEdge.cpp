#include "Edge.h"

int main () {
    Vertex* vertex = new Vertex(1, true, false);
    Vertex* vertex2 = new Vertex(2, false, true);
    Vertex* vertex3 = new Vertex(3, false, false);

    Edge edge;
    Edge edge2(1, vertex, vertex2, 10);
    Edge edge3(2, vertex2, vertex3, 20);

    edge2.printEdge();
    edge3.printEdge();
    return 0;
}