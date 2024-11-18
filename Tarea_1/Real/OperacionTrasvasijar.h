#ifndef OPERACIONTRASVASIJAR_H
#define OPERACIONTRASVASIJAR_H

#include "Operacion.h"

class OperacionTrasvasijar : public Operacion {
    public:

    // Sobrecarga de la operación de trasvasijar
    GrupoBidones operacionTrasvasijar(GrupoBidones grupo, int indice1, int indice2) override;
};

#endif