#ifndef HASH_H
#define HASH_H

#include "GrupoBidones.h"

class Hash{
    public:

    int crearCodigoHash(GrupoBidones grupo, int numeroEstados);
    void insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice);
    bool buscarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);
};

#endif