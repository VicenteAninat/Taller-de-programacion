#include <iostream>
#include <string>
#include "Bidon.h"

using namespace std;

class GrupoBidones{
    public:
    // Se definen los atributos del estado
    Bidon** bidones; // Arreglo de punteros a bidones
    GrupoBidones *parent; // Puntero al padre
    string operation; // Operación realizada
    int cantidad;

    GrupoBidones(int n); // Constructor por defecto

    //GrupoBidones* ClonarBidon(); // Toma un Estado y retorna un puntero a clon para ser el hijo

    // Constructor del estado
    GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad);

    string imprimirBidones(Bidon** bidones, int cantidad);

    string print(); // Imprime el estado y toda la secuencia de operaciones que lo generaron
};