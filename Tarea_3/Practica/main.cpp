#include <iostream>
#include <chrono>
#include "FordFulkerson.h"
#include "Read.h"

using namespace std;

int main () {
    int option;
    string fileName;
    FordFulkerson fordFulkerson;
    Read read;
    Graph* graph = nullptr;

    cout << "Bienvenido, ¿que operacion desea realizar?" << endl;
    cout << "Por favor, seleccione una opcion segun su numero correspondiente:" << endl;
    cout << "1. Cargar un grafo" << endl;
    cout << "2. Mostrar el grafo" << endl;
    cout << "3. Calcular el flujo maximo" << endl;
    cout << "4. Salir" << endl;

    
    cin >> option;

    switch (option) {
        case 1:
            {
            // Se ha seleccionado la opcion de cargar un grafo
            cout << "Por favor, ingrese el nombre del archivo (sin extension)" << endl;
            cin >> fileName;
            graph = read.loadGraph(fileName);
            break;
            }

        case 2:
            {
            // Se ha seleccionado la opcion de mostrar el grafo
            if (graph != nullptr) {
                graph->printGraph();
            } else {
                cout << "Error: No se ha cargado ningun grafo." << endl;
            }
            break;
            }

        case 3:
            {
            // Se ha seleccionado la opcion de calcular el flujo maximo
            auto start = chrono::high_resolution_clock::now();
            int flow = fordFulkerson.operate(graph);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            graph->printGraphLite();
            cout << "Flujo Total: " << to_string(flow) << endl;
            cout << duration.count() + " [ms]" << endl;
            break;
            }

        case 4:
            {
            cout << "Saliendo..." << endl;
            break;
            }
    
        default:
            {
            cout << "Opcion invalida, por favor seleccione una opcion valida" << endl;
            break;
            }
    }

    return 0;
}