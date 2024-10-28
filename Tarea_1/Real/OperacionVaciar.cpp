#include "OperacionVaciar.h"

Bidon OperacionVaciar::operacion(Bidon bidon){
    Bidon bidonAux = bidon;
    bidonAux.aguaActual = 0;
    return bidonAux;
}