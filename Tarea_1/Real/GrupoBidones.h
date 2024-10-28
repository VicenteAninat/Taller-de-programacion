#ifndef GRUPOBIDONES_H
#define GRUPOBIDONES_H

#include <string>
#include "Bidon.h"

using namespace std;

class GrupoBidones{
    public:
    // Se definen los atributos del estado
    Bidon** bidones; // Arreglo de punteros a bidones
    GrupoBidones *parent; // Puntero al padre
    string operation; // Operación realizada
    int cantidad; // Cantidad de bidones para construir arreglos

    GrupoBidones(int n); // Constructor por defecto. Necesita la cantidad de bidones

    //GrupoBidones* ClonarBidon(); // Toma un Estado y retorna un puntero a clon para ser el hijo

    // Constructor del estado
    GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad);

    // Función para imprimir los bidones de un arreglo
    string imprimirBidones(Bidon** bidones, int cantidad);

    string print(); // Imprime el estado y toda la secuencia de operaciones que lo generaron
};

#endif