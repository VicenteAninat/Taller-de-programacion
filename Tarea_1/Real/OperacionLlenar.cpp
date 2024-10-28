#include "OperacionLlenar.h"

Bidon OperacionLlenar::operacion(Bidon bidon){
    Bidon bidonAux = bidon;
    bidonAux.aguaActual = bidonAux.aguaMaxima;
    return bidonAux;
}