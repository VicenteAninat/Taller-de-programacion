#ifndef PLANO_H
#define PLANO_H

#include <list>
#include <set>
#include "Punto.h"

using namespace std;

class Plano {
    public:
    // Atributos
    list<Punto> puntos;
    set<Punto> envoltura;

    // Métodos
    Plano();

    Plano(list <Punto> puntos);

    void agregarPunto(Punto punto);

    void agregarPuntos(list <Punto> puntos);

    void eliminarPunto(Punto punto);

    int calcularDistancia(Punto punto1, Punto punto2);
};

#endif