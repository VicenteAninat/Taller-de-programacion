#ifndef JUGPROB_H
#define JUGPROB_H

// Clase de resolución del problema
#include "GrupoBidones.h"
#include "OperacionLlenar.h"
#include "OperacionVaciar.h"
#include "OperacionTrasvasijar.h"
#include "Hash.h"
#include "Queue.h"
#include <random>

class JugProb{
    public:

    // Método para calcular la distancia de un estado al objetivo
    int calcularDistancia(GrupoBidones estado);

    
    void resolver(GrupoBidones grupo);
};

#endif