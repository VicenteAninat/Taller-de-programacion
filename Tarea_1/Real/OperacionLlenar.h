#ifndef OPERACION_LLENAR_H
#define OPERACION_LLENAR_H

#include "Operacion.h"

class OperacionLlenar : public Operacion {
    public:

    // Sobrecarga de la operación de llenado
    GrupoBidones operacion(GrupoBidones grupo, int indice) override;
};

#endif