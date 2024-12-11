#include "State.h"

class ColoringOperation {
    public:
    // Atributos
    State *best; // Mejor estado encontrado

    // Metodos

    // Constructor por defecto
    ColoringOperation();

    // Descripción: Solucion al VCP con algoritmo Greedy
    // Entrada: Estado inicial (State *s)
    // Salida: Numero cromatico de la solucion (int)
    int greedyColoring(State *s);

    // Descripción: Solucion al VCP con algoritmo Backtrack
    // Entrada: Estado inicial (State *s)
    // Salida: Numero cromatico de la solucion (int)
    int backtrack(State *s);

    // Descripción: Solucion al VCP con algoritmo BranchBound
    // Entrada: Estado inicial (State *s)
    // Salida: Numero cromatico de la solucion (int)
    int branchBound(State *s);

    // Descripción: Solucion al VCP con algoritmo DSatur
    // Entrada: Estado inicial (State *s)
    // Salida: Numero cromatico de la solucion (int)
    int dSatur(State* s);

    // Descripción: Solucion al VCP con algoritmo Branchbound y heurística basada en DSatur
    // Entrada: Estado inicial (State *s)
    // Salida: Numero cromatico de la solucion (int)
    int dSaturBranchBound(State* s, int lb, int ub);
};