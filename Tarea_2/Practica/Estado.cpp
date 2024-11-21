#include "Grafo.cpp"

class Estado {
public:
    Grafo* grafo; // Grafo del estado

    Estado() {
        this->grafo = nullptr;
    }
};