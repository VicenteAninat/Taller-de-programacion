#ifndef DINIC_H
#define DINIC_H

#include "GrafoBase.h"
#include <queue>

class Dinic : public GrafoBase {
    public:
    // Atributos
    vector<int> level;
    vector<int> nextEdge;
    vector<list<Edge*>::iterator> ptr;

    // Metodos

    // Descripción: Constructor por defecto de la clase Dinic. Inicializa los atributos de la clase con valores por defecto.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    Dinic();

    // Descripción: Constructor de la clase Dinic que inicializa los atributos con un número específico de nodos.
    // Entrada: Número de nodos (int n).
    // Salida: Ninguna (void)
    Dinic(int n);

    // Descripción: Constructor de la clase Dinic que inicializa los atributos con un número específico de nodos, un nodo fuente y un nodo sumidero.
    // Entrada: Número de nodos (int n), Nodo fuente (int s), Nodo sumidero (int t).
    // Salida: Ninguna (void)
    Dinic(int n, int s, int t);

    // Descripción: Resuelve el problema de flujo máximo utilizando el algoritmo de Dinic.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    void solve() override;

    // Descripción: Realiza una búsqueda en anchura (BFS) para construir el grafo de niveles.
    // Entrada: Ninguna.
    // Salida: Devuelve true si el nodo sumidero t es alcanzable desde el nodo fuente s, de lo contrario devuelve false.
    bool bfs();

    // Descripción: Realiza una búsqueda en profundidad (DFS) para encontrar caminos aumentantes y empujar flujo.
    // Entrada: Nodo actual (int u), Flujo disponible (long long flow).
    // Salida: Devuelve el flujo encontrado en el camino aumentante (long long).
    long long dfs(int u, long long flow);

    // bool bfs2(int source, int sink);

    // long long dfs2(int u, int sink, long long flow);

    //int max_flow();
};

#endif