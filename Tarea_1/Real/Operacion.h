// Clase sobrecargadora de operaciones

#include "GrupoBidones.h"

class Operacion{
    public:
    
    Operacion();

    GrupoBidones virtual operacion(GrupoBidones grupo, int indice);
};