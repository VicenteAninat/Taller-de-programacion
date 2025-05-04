#include "Menu.h"

Menu::Menu() {
}

void Menu::mostrarMenu() {
    bool salir = false;
    Dinic* dinic = nullptr;
    Read* r = new Read();
    int aux = 0;
    string nombreArchivo;
    int cantidadVertices = 0;

    cout << "Bienvenido al programa de flujo máximo." << endl;

    int opcion;

    while (!salir) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Ingresar un grafo." << endl;
        cout << "2. Visualizar el grafo ingresado." << endl;
        cout << "3. Calcular el flujo máximo." << endl;
        cout << "4. Salir." << endl;
        cout << endl;

        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del grafo sin extension de archivo." << endl;
                cin >> nombreArchivo;
                cantidadVertices = r->contarVertices(nombreArchivo, aux);
                dinic = r->readDinic(nombreArchivo, cantidadVertices);
                cout << "Grafo ingresado exitosamente." << endl;
                cout << endl;
                break;
                
            case 2:
                cout << "Ha elegido visualizar el grafo ingresado." << endl;
                if (dinic == nullptr) {
                    cout << "No se ha ingresado un grafo aun." << endl;
                    cout << endl;
                    break;
                }
                else{
                    dinic->printGraph();
                    cout << endl;
                    break;
                }
                
            case 3:
                cout << "Ha elegido calcular el flujo máximo." << endl;
                if (dinic == nullptr) {
                    cout << "No se ha ingresado un grafo aun." << endl;
                    break;
                }
                else{
                    auto start = chrono::high_resolution_clock::now();
                    //cout << "Flujo máximo: " << dinic->getMaxFlow() << endl;
                    cout << "Flujo máximo: " << dinic->getMaxFlow() << endl;
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos." << endl;
                    break;
                }
                
            case 4:
                salir = true;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }
}