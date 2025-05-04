#include "Dinic.h"
#include <algorithm>
#include <fstream>
#include <set>

class Read {
    public:
    // Atributos

    // Metodos

    // Descripción: Constructor por defecto de la clase Menu. Inicializa los atributos de la clase con valores por defecto.
    // Entrada: Ninguna.
    // Salida: Ninguna (void)
    Read();

    // Descripción: Lee un archivo de grafo y crea una instancia del algoritmo de Dinic con los datos del grafo.
    // Entrada: Nombre del archivo (string nombreArchivo), Cantidad de vértices (int cantidad).
    // Salida: Devuelve un puntero a una instancia de Dinic inicializada con los datos del grafo (Dinic*).
    Dinic* readDinic(string nombreArchivo, int cantidadVertices);

    // Descripción: Cuenta el número de vértices en un archivo de grafo y devuelve la cantidad total de vértices, incluyendo dos vértices adicionales.
    // Entrada: Nombre del archivo (string nombreArchivo), Cantidad inicial de vértices (int cantidadVertices).
    // Salida: Devuelve la cantidad total de vértices (int).
    int contarVertices(string nombreArchivo, int cantidadVertices);
};