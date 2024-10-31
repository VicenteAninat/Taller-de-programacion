#include "OperacionLlenar.h"

GrupoBidones OperacionLlenar::operacion(GrupoBidones grupo, int indice){
    GrupoBidones grupoAux = grupo;
    grupoAux.bidones[indice]->aguaActual = grupoAux.bidones[indice]->aguaMaxima;
    grupoAux.operation = "Llenar bidon " + to_string(indice + 1);
    return grupoAux;
}