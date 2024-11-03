#ifndef JUGPROB_H
#define JUGPROB_H

// Clase de resolución del problema
#include "GrupoBidones.h"
#include "OperacionLlenar.h"
#include "OperacionVaciar.h"
#include "OperacionTrasvasijar.h"
#include "Hash.h"
#include <random>

class JugProb{
    public:

    void resolver(GrupoBidones grupo);
};

#endif