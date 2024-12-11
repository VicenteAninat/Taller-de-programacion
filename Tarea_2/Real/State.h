#ifndef STATE_H
#define STATE_H

#include "Graph.h"

class State {
    public:
    // Atributos
    set<int> uncoloredVertices; // conjunto de vertices sin colorear
    set<int> coloredVertices; // conjunto de vertices coloreados
    set<int> availableColors; // conjunto de colores disponibles
    Graph graph; // grafo semi coloreado durante el desarrolo del algoritmo

    // Metodos

    // Descripción:
    // Entrada:
    // Salida:
    State();

    // Descripción:
    // Entrada:
    // Salida:
    State(Graph graph);

    // Descripción: Obtiene un vértice no coloreado del conjunto de vértices no coloreados
    // Entrada: Ninguna
    // Salida: Un vértice no coloreado (int) o -1 si no hay más vértices no coloreados
    int getVertex();

    // Descripción: Asigna un color a un vértice, lo marca como coloreado y 
    // lo elimina del conjunto de vértices no coloreados
    // Entrada: Vértice a colorear (int vertex), Color a asignar (int color)
    // Salida: Ninguna (void)
    void pushColorSelectVertex(int vertex, int color);

    // Descripción: Verifica si un vértice está coloreado
    // Entrada: Vértice a verificar (int vertex)
    // Salida: Verdadero si el vértice está coloreado (bool), Falso en caso contrario
    bool isVertexColored(int vertex);

    // Descripción: Verifica si todos los vértices están coloreados
    // Entrada: Ninguna
    // Salida: Verdadero si todos los vértices están coloreados (bool), Falso en caso contrario
    bool isAllColored();

    // Descripción: Imprime los colores asignados a cada vértice
    // Entrada: Ninguna
    // Salida: Ninguna (void)
    void printColor();

    // Descripción: Incrementa el número de colores disponibles añadiendo un nuevo color
    // Entrada: Ninguna
    // Salida: Ninguna (void)
    void incrementColor();
};

#endif