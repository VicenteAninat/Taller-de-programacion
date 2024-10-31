// Clase sobrecargadora de operaciones
#ifndef OPERACION_H
#define OPERACION_H

#include "GrupoBidones.h"

class Operacion{
    public:
    
    Operacion();

    GrupoBidones virtual operacion(GrupoBidones grupo, int indice);

    GrupoBidones virtual operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2);
};

#endif