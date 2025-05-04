#include "Vertex.h"

int main () {
    Vertex vertex(1, true, false);
    Vertex vertex2(2, false, true);
    Vertex vertex3(3, false, false);

    Edge edge(1, &vertex, &vertex2, 10);
    Edge edge2(2, &vertex2, &vertex3, 20);
    Edge edge3(3, &vertex, &vertex3, 30);

    vertex.addEdge(&edge);
    vertex2.addEdge(&edge2);
    vertex.addEdge(&edge3);

    vertex.printVertex();
    vertex2.printVertex();
    vertex3.printVertex();
    return 0;
}