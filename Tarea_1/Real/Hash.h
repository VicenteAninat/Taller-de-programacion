#ifndef HASH_H
#define HASH_H

#include "GrupoBidones.h"
#include <cstring>

class Hash{
    public:

    // Método creador del codigo hash
    int crearCodigoHash(GrupoBidones grupo, int numeroEstados);

    // Método para insertar un estado en la tabla hash
    void insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);

    // Método para encontrar un estado en la tabla hash entre el indice y el final
    bool encontrarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);

    // Método para encontrar un estado en la tabla hash entre el inicio y el indice
    bool encontrarEstadoHashAux(GrupoBidones estado, GrupoBidones* tablaHash, int indice);

    // Método para calcular el desface de la posición de un estado en la tabla hash
    int calcularAcumulacion(GrupoBidones grupo, GrupoBidones* tablaHash, int indice, int capacidad);

    // Método para buscar y comparar la memoria de un estado en la tabla hash
    bool buscarCompararMemoria(GrupoBidones grupo1, GrupoBidones* tablaHash, int cantidad);
};

#endif