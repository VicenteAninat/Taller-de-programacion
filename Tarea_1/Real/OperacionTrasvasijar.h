#ifndef OPERACIONTRASVASIJAR_H
#define OPERACIONTRASVASIJAR_H

#include "Operacion.h"

class OperacionTrasvasijar : public Operacion {
    public:

    GrupoBidones operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2) override;
};

#endif