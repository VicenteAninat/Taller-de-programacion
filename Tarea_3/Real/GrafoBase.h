#ifndef GRAFOBASE_H
#define GRAFOBASE_H

#include <iostream>
#include <vector>
#include <list>
#include "Edge.h"

using namespace std;

class GrafoBase {
    public:
    // Atributos
    static const long long INF;
    int n;
    int s;
    int t;
    bool solved;
    long long maxFlow;
    vector<list<Edge*>> graph;

    // Metodos

    // Descripción: Constructor por defecto de la clase GrafoBase. Inicializa los atributos del grafo con valores por defecto.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    GrafoBase();

    // Descripción: Constructor de la clase GrafoBase que inicializa los atributos con un número específico de nodos.
    // Entrada: Número de nodos (int n).
    // Salida: Ninguna (void)
    GrafoBase(int n);

    // Descripción: Constructor de la clase GrafoBase que inicializa los atributos con un número específico de nodos, un nodo fuente y un nodo sumidero.
    // Entrada: Número de nodos (int n), Nodo fuente (int s), Nodo sumidero (int t).
    // Salida: Ninguna (void)
    GrafoBase(int n, int s, int t);

    // Descripción: Inicializa un grafo vacío con n nodos, donde cada nodo tiene una lista de adyacencia vacía.
    // Entrada: Ninguna.
    // Salida: Devuelve un vector de listas de punteros a aristas (vector<list<Edge*>>).
    vector<list<Edge*>> initializeEmptyGraph();

    // Descripción: Ejecuta la resolución del problema de flujo máximo si no ha sido resuelto previamente.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    void execute();

    // Descripción: Agrega una arista dirigida y su arista residual al grafo.
    // Entrada: Nodo de origen (int origin), Nodo de destino (int destination), Capacidad de la arista (long long capacity).
    // Salida: Ninguna (void)
    void addEdge(int origin, int destination, long long capacity);

    // Descripción: Devuelve el flujo máximo calculado para el grafo.
    // Entrada: Ninguna.
    // Salida: Devuelve el flujo máximo (long long).
    long long getMaxFlow();

    // Descripción: Devuelve el grafo residual.
    // Entrada: Ninguna.
    // Salida: Devuelve el grafo residual como un vector de listas de punteros a aristas (vector<list<Edge*>>).
    vector<list<Edge*>> getGraph();

    virtual void solve() = 0;

    // Descripción: Imprime la representación en cadena de todas las aristas del grafo.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    void printGraph();
};

#endif