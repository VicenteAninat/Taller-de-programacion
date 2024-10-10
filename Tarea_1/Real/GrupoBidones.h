#include <iostream>
#include "Bidon.h"
#include <string>

using namespace std;

class GrupoBidones{
    public:
    // Se definen los atributos del estado
    Bidon **bidon;
    GrupoBidones *parent;
    string operation;

    // Constructor del estado
    GrupoBidones(Bidon *bidones[], GrupoBidones *parent, string operation);

    string imprimirBidones(Bidon *bidones[]);

    void print(); // Imprime el estado y toda la secuencia de operaciones que lo generaron
};