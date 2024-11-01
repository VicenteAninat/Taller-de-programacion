// Clase de resolución del problema
#include "GrupoBidones.h"
#include "OperacionLlenar.h"
#include "OperacionVaciar.h"
#include "OperacionTrasvasijar.h"
#include <random>

class JugProb{
    public:

    int crearCodigoHash(GrupoBidones grupo, int numeroEstados);
    int insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice);
    bool buscarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad);

    void resolver(GrupoBidones grupo);
};