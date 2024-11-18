// Clase sobrecargadora de operaciones
#ifndef OPERACION_H
#define OPERACION_H

#include "GrupoBidones.h"

class Operacion{
    public:
    
    // Constructor por defecto
    Operacion();

    // Método virtual para realizar la operación de llenado o vaciado
    GrupoBidones virtual operacion(GrupoBidones grupo, int indice);

    // Método virtual para realizar la operación de trasvasijar
    GrupoBidones virtual operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2);
};

#endif