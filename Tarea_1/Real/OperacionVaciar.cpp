#include "OperacionVaciar.h"

GrupoBidones OperacionVaciar::operacion(GrupoBidones grupo, int indice){
    // Creacion del bidon vaciado
    Bidon* bidonAux = new Bidon(0, grupo.bidones[indice]->aguaMaxima, grupo.bidones[indice]->aguaObjetivo);

    // Creacion del arreglo de bidones con el bidon vaciado
    Bidon** bidones = new Bidon*[grupo.cantidad];
    for (int i = 0; i < grupo.cantidad; i++){
        if (i != indice){
            bidones[i] = grupo.bidones[i];
        }else{
            bidones[i] = bidonAux;
        }
    }

    // Creacion del puntero que apunta al padre
    GrupoBidones* parent = new GrupoBidones();
    parent->bidones = grupo.bidones;
    parent->cantidad = grupo.cantidad;
    parent->operation = grupo.operation;
    parent->parent = grupo.parent;

    // Creacion del grupo de bidones con el bidon vaciado
    GrupoBidones grupoAux = GrupoBidones(grupo.cantidad);

    // Asignacion de los valores al grupo de bidones
    grupoAux.bidones = bidones;
    grupoAux.parent = parent;
    grupoAux.cantidad = grupo.cantidad;
    grupoAux.operation = "Vaciar bidon " + to_string(indice + 1) + "\n";

    return grupoAux;
}