#ifndef HASH_H
#define HASH_H

#include "GrupoBidones.h"
#include <cstring>

class Hash{
    public:

    int crearCodigoHash(GrupoBidones grupo, int numeroEstados);
    void insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);
    bool encontrarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);
    int calcularAcumulacion(GrupoBidones grupo, GrupoBidones* tablaHash, int indice, int capacidad);
    bool buscarCompararMemoria(GrupoBidones grupo1, GrupoBidones* tablaHash, int cantidad);
};

#endif