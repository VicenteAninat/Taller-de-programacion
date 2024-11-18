#include "Nodo.cpp"

struct Arista {
    Nodo* nodo1;
    Nodo* nodo2;
};

class Grafo {
public:
    Nodo** nodos;
    Arista** aristas;
    int coloresAsignados;
    int numeroCromatico;

    Grafo() {
        this->nodos = nullptr;
        this->aristas = nullptr;
        this->coloresAsignados = 0;
        this->numeroCromatico = -1;
    }

    int calcularNumeroCromatico();
};