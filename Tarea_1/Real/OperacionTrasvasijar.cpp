#include "OperacionTrasvasijar.h"

GrupoBidones OperacionTrasvasijar::operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2){
    // Creacion de los bidones trasvasijados
    Bidon* bidonAux1 = new Bidon(grupo.bidones[indice1]->aguaActual, grupo.bidones[indice1]->aguaMaxima, grupo.bidones[indice1]->aguaObjetivo);
    Bidon* bidonAux2 = new Bidon(grupo.bidones[indice2]->aguaActual, grupo.bidones[indice2]->aguaMaxima, grupo.bidones[indice2]->aguaObjetivo);

    int aguaTrasvasijada = bidonAux1->aguaActual;
    if(bidonAux2->aguaActual + aguaTrasvasijada <= bidonAux2->aguaMaxima){
        bidonAux2->aguaActual += aguaTrasvasijada;
        bidonAux1->aguaActual = 0;
    }else{
        bidonAux1->aguaActual = bidonAux1->aguaActual - (bidonAux2->aguaMaxima - bidonAux2->aguaActual);
        bidonAux2->aguaActual = bidonAux2->aguaMaxima;
    }

    // Creacion del arreglo de bidones con los bidones trasvasijados
    Bidon** bidones = new Bidon*[grupo.cantidad];
    for (int i = 0; i < grupo.cantidad; i++){
        if (i != indice1 && i != indice2){
            bidones[i] = grupo.bidones[i];
        }else if (i == indice1){
            bidones[i] = bidonAux1;
        }else{
            bidones[i] = bidonAux2;
        }
    }

    // Creacion del puntero que apunta al padre
    GrupoBidones* parent = new GrupoBidones();
    parent->bidones = grupo.bidones;
    parent->cantidad = grupo.cantidad;
    parent->operation = grupo.operation;
    parent->parent = grupo.parent;

    // Creacion del grupo de bidones con los bidones trasvasijados
    GrupoBidones grupoAux = GrupoBidones(grupo.cantidad);

    // Asignacion de los valores al grupo de bidones
    grupoAux.bidones = bidones;
    grupoAux.parent = parent;
    grupoAux.cantidad = grupo.cantidad;
    grupoAux.operation = "Trasvasijar bidon " + to_string(indice1 + 1) + " a bidon " + to_string(indice2 + 1) + "\n";

    return grupoAux;
}