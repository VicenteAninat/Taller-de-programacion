#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
    public:
    // Atributos
    unordered_map<int, set<int>> vertexNeighbors; // Tabla hash de vecinos
    unordered_map<int, int> vertexColor; // Tabla hash de colores

    // Metodos
    // Constructor por defecto
    /*
    Descripción:
    Entrada:
    Salida:
    */
    Graph();

    // Constructor con parametros
    /*
    Descripción:
    Entrada:
    Salida:
    */
    Graph(vector<vector<int>> edges); 

    // Obteiene el numero de colores usados
    /*
    Descripción:
    Entrada:
    Salida:
    */
    int getNumberOfColors();

    // Verifica si es posible colorear un nodo con un color dado
    /*
    Descripción:
    Entrada:
    Salida:
    */
    bool canColor(int vertex, int color);

    // Imprime el grafo
    /*
    Descripción:
    Entrada:
    Salida:
    */
    void printGraph();
};
