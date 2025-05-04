#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <sstream>

using namespace std;

class Edge {
    // Atributos
    public:
    int originID;
    int destID;
    Edge* residual;
    long flow;
    long long capacity;

    // Metodos
    // Descripción: Constructor por defecto de la clase Edge. Inicializa los atributos de la arista con valores por defecto.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    Edge();

    // Descripción: Constructor de la clase Edge que inicializa los atributos con los valores proporcionados.
    // Entrada: ID del nodo de origen (int originID), ID del nodo de destino (int destID), Capacidad de la arista (long long capacity).
    // Salida: Ninguna (void)
    Edge(int originID, int destID, long long capacity);

    // Descripción: Verifica si la arista es residual.
    // Entrada: Ninguna.
    // Salida: Devuelve true si la capacidad de la arista es 0, de lo contrario devuelve false.
    bool isResidual();

    // Descripción: Calcula la capacidad restante de la arista.
    // Entrada: Ninguna.
    // Salida: Devuelve la capacidad restante de la arista (long).
    long remainingCapacity();

    // Descripción: Aumenta el flujo a través de la arista y ajusta el flujo en la arista residual.
    // Entrada: Cantidad de flujo a aumentar (long long bottleNeck).
    // Salida: Ninguna (void)
    void augment(long long bottleNeck);

    // Descripción: Genera una representación en cadena de la arista, incluyendo información sobre los nodos de origen y destino, el flujo actual, la capacidad y si es residual.
    // Entrada: Nodo fuente (int s), Nodo sumidero (int t).
    // Salida: Devuelve una cadena de texto con la representación de la arista (string).
    string toString(int s, int t);
};

#endif
