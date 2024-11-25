#include <vector>
#include <iostream>
#include <chrono>
#include "Graph.h"
#include "ColoringOperation.h"
#include "Read.h"

using namespace std;

int main() {
    
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4},
        {1, 2}, {1, 5}, {1, 6},
        {2, 3}, {2, 6}, {2, 7},
        {3, 4}, {3, 7}, {3, 8},
        {4, 8}, {4, 9},
        {5, 6}, {6, 7}, {7, 8}, {8, 9},
        {5, 10}, {6, 10}, {7, 11}, {8, 11},
        {10, 11}, {10, 12}, {11, 12} };
    Graph graph(edges);
    
    graph.printGraph();
    State g(graph);
    State* s = &g;
    
    // Ingresar nombre por consola
    /*
    string fileName;
    cout << "Ingrese el nombre del archivo: ";
    cin >> fileName;
    fileName = fileName + ".txt";
    
    Read r;
    State* s = r.readFile(fileName);
    */
    //s->graph.printGraph();
    //s->printColor();
    ColoringOperation co;
    // Inicia el reloj
    auto start = chrono::high_resolution_clock::now();
    co.greedyColoring(s);
    // Detiene el reloj
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Tiempo de ejecucion greedy: " << duration.count() << " microsegundos" << endl;
    cout << "Numero de colores greedy: " << s->graph.getNumberOfColors() << endl;
    cout << "Mejor coloreo encontrado: ";
    // co.best->printColor();
    // Inicia el reloj
    start = chrono::high_resolution_clock::now();
    int c = co.backtrack(s);
    // Detiene el reloj
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Tiempo de ejecucion backtrack: " << duration.count() << " microsegundos" << endl;
    cout << "Numero de colores backtrack : " << c << endl;
    // co.best->printColor();
    // Inicia el reloj
    start = chrono::high_resolution_clock::now();
    c = co.branchBound(s);
    // Detiene el reloj
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Tiempo de ejecucion branchBound: " << duration.count() << " microsegundos" << endl;
    cout << "Numero de colores branchBound : " << c << endl;
    // co.best->printColor();
    return 0;
}