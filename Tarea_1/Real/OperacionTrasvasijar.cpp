#include "OperacionTrasvasijar.h"

GrupoBidones OperacionTrasvasijar::operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2){
    GrupoBidones grupoAux = grupo;
    int aguaTrasvasijada = grupoAux.bidones[indice1]->aguaActual;
    if(grupoAux.bidones[indice2]->aguaActual + aguaTrasvasijada <= grupoAux.bidones[indice2]->aguaMaxima){
        grupoAux.bidones[indice2]->aguaActual += aguaTrasvasijada;
        grupoAux.bidones[indice1]->aguaActual = 0;
    }else{
        grupoAux.bidones[indice1]->aguaActual = grupoAux.bidones[indice1]->aguaActual - (grupoAux.bidones[indice2]->aguaMaxima - grupoAux.bidones[indice2]->aguaActual);
        grupoAux.bidones[indice2]->aguaActual = grupoAux.bidones[indice2]->aguaMaxima;
    }

    grupoAux.operation = "Trasvasijar bidon " + to_string(indice1 + 1) + " a bidon " + to_string(indice2 + 1);
    return grupoAux;
}