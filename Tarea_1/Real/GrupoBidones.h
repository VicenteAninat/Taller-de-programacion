#ifndef GRUPOBIDONES_H
#define GRUPOBIDONES_H

#include <string>
#include <cmath>
#include "Bidon.h"

using namespace std;

class GrupoBidones{
    public:
    // Se definen los atributos del estado
    Bidon** bidones; // Arreglo de punteros a bidones
    GrupoBidones *parent; // Puntero al padre
    string operation; // Operación realizada
    int cantidad; // Cantidad de bidones para construir arreglos
    int distancia; // Distancia al objetivo

    GrupoBidones(); // Constructor por defecto

    GrupoBidones(int n); // Constructor por defecto. Necesita la cantidad de bidones

    // Constructor del estado
    GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad);

    // Función para imprimir los bidones de un arreglo
    string imprimirBidones(Bidon** bidones, int cantidad);

    string print(); // Imprime el estado y toda la secuencia de operaciones que lo generaron
};

#endif