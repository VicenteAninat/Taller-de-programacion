#include "Nodo.cpp"
#include <unordered_map>

class Grafo {
public:
    Nodo** nodos; // Lista de nodos del grafo
    int coloresAsignados; // Cantidad de colores asignados al grafo
    int coloresUsados; // Cantidad de colores usados en el grafo
    vector<int> grafoColoreado; // Conjunto de IDs de nodos coloreados
    vector<int> grafoNoColoreado; // Conjunto de IDS de nodos no coloreados

    Grafo() {
        this->nodos = nullptr;
        this->coloresAsignados = 0;
        this->coloresUsados = 0;
        this->grafoColoreado = vector<int>();
        this->grafoNoColoreado = vector<int>();
    }
};