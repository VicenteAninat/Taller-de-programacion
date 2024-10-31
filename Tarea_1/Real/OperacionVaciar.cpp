#include "OperacionVaciar.h"

GrupoBidones OperacionVaciar::operacion(GrupoBidones grupo, int indice){
    GrupoBidones grupoAux = grupo;
    grupoAux.bidones[indice]->aguaActual = 0;
    grupoAux.operation = "Vaciar bidon " + to_string(indice + 1);
    return grupoAux;
}