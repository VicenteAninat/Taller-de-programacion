#include "Graph.h"

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

    Graph graph;
    graph.vertexes.insert({1, &vertex});
    graph.vertexes.insert({2, &vertex2});
    graph.vertexes.insert({3, &vertex3});
    graph.edges.insert({1, &edge});
    graph.edges.insert({2, &edge2});
    graph.edges.insert({3, &edge3});

    graph.printGraph();
    return 0;
}