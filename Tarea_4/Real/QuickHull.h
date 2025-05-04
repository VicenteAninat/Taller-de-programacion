#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "Plano.h"
#include <iostream>

class QuickHull {
    public:
    // Atributos

    // Métodos
    int encontrarLado(Punto p1, Punto p2, Punto p);

    int encontrarDistancia(Punto p1, Punto p2, Punto p);

    bool comprobarPlano(Plano* plano);

    void resolver(Plano* plano, int cantidadPuntos, Punto minX, Punto maxX, int lado);

    void mostrarEnvoltura(Plano* plano);
};

#endif