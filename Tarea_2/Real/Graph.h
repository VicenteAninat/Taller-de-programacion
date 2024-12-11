#ifndef GRAPH_H
#define GRAPH_H

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
    Graph();

    // Constructor con parametros
    Graph(vector<vector<int>> edges); 

    // Descripción: Obtiene el número de colores únicos utilizados en el grafo
    // Entrada: Ninguna
    // Salida: Número de colores únicos utilizados (int)
    int getNumberOfColors();

    // Descripción: Verifica si un vértice puede ser coloreado con un color 
    // específico sin que ningún vecino tenga el mismo color
    // Entrada: Vértice a colorear (int vertex), Color a verificar (int color)
    // Salida: Verdadero si el vértice puede ser coloreado con el color 
    // especificado (bool), Falso en caso contrario
    bool canColor(int vertex, int color);

    // Descripción: Imprime el grafo mostrando cada vértice y sus vecinos
    // Entrada: Ninguna
    // Salida: Ninguna (void)
    void printGraph();
};

#endif