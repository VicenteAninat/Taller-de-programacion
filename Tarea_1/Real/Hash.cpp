#include "Hash.h"

// Método para crear un código hash
int Hash::crearCodigoHash(GrupoBidones grupo, int numeroEstados){
    int codigoHash = 0;
    for (int i = 0; i < grupo.cantidad; i++){
        codigoHash += (grupo.bidones[i]->aguaActual)*(i+1);
    }
    codigoHash = codigoHash % numeroEstados;
    return codigoHash;
}

// Método para insertar un estado en una tabla hash
void Hash::insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice){
    bool insertado = false;
    while (!insertado){
        if (tablaHash[indice].bidones != nullptr){
            indice++;
        }
        else{
            tablaHash[indice] = estado;
            insertado = true;
        }
    }

    return;
}

// Método para verificar si un estado ya ha sido calculado
bool Hash::buscarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    bool encontrado = false;
    while (!encontrado && (indice < capacidad - 1)){
        if (tablaHash[indice].bidones == nullptr){
            break;
        }
        else{
            if (tablaHash[indice].bidones == estado.bidones){
                encontrado = true;
                break;
            }
            else{
                indice++;
            }
        }
    }

    return encontrado;
}