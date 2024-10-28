#include "OperacionTrasvasijar.h"

Bidon OperacionTrasvasijar::operacionTrasvasijar(Bidon bidon1, Bidon bidon2){
    Bidon bidonAux1 = bidon1;
    Bidon bidonAux2 = bidon2;
    int aguaTrasvasijada = bidonAux1.aguaActual;
    if(bidonAux2.aguaActual + bidonAux1.aguaActual > bidonAux2.aguaMaxima){
        bidonAux1.aguaActual = bidonAux1.aguaActual - (bidonAux2.aguaMaxima - bidonAux2.aguaActual);
        bidonAux2.aguaActual = bidonAux2.aguaMaxima;
    } else {
        bidonAux2.aguaActual = bidonAux2.aguaActual + bidonAux1.aguaActual;
        bidonAux1.aguaActual = 0;
    }
    return bidonAux2;
}