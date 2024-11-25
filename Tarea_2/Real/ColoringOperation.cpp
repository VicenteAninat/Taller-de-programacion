#include "ColoringOperation.h"

ColoringOperation::ColoringOperation() {
    best = nullptr;
}

int ColoringOperation::greedyColoring(State *s) {
    while (!s->isAllColored()) {
            // seleccionamos un vertice y lo coloreamos
            int vertex = s->getVertex(); // necesitamos obtener un vértice no coloreado
            // encuentro el primer color disponible que sea factible (no igual al un color de vecinos)
            for (int color : s->availableColors) {
                if (s->graph.canColor(vertex, color)) {
                    s->pushColorSelectVertex(vertex, color);
                    break; // ya encontramos un color y actualizamos el estado
                }
            }
            // consulto si no se pudo colorear el vertice vertex
            if (!s->isVertexColored(vertex)) { // entonces debo colorearlo con un nuevo color
                int c = s->graph.getNumberOfColors();
                s->pushColorSelectVertex(vertex, c);
                s->availableColors.insert(c);
            }
            // s->printColor();
        }
        best = s; // el mejor estado es el estado actual
        return s->graph.getNumberOfColors(); // retornamos el numero de colores
}

int ColoringOperation::backtrack (State *s) {
        // caso base
        if (s->isAllColored()) { // este estado es una hoja del algortimo
            if (best == nullptr || 
                s->graph.getNumberOfColors() < best->graph.getNumberOfColors()) {
                best = s;
            }
            return best->graph.getNumberOfColors();
        } else {    
            // caso recursivo
            int vertex = s->getVertex(); // se puede porque aun existen vertices sin colorear
            s->incrementColor(); // incrementamos el numero de colores
            for(int color : s->availableColors) {
                if (s->graph.canColor(vertex, color)) {
                    State *s1 = new State(*s);
                    s1->pushColorSelectVertex(vertex, color);

                    // if (condicion relativa a LB) si se cumple -> bactrack sino se salta  

                    backtrack(s1);
                }

            }
            return best->graph.getNumberOfColors();
        }
    }

int ColoringOperation::branchBound(State *s) {
    while (!s->isAllColored()) {
        // seleccionamos un vertice y lo coloreamos
        int vertex = s->getVertex(); // necesitamos obtener un vértice no coloreado
        // encuentro el primer color disponible que sea factible (no igual a un color de vecinos)
        for (int color : s->availableColors) {
            if (s->graph.canColor(vertex, color)) {
                s->pushColorSelectVertex(vertex, color);
                break; // ya encontramos un color y actualizamos el estado
            }
        }
        // consulto si no se pudo colorear el vertice vertex
        if (!s->isVertexColored(vertex)) { // entonces debo colorearlo con un nuevo color
            int c = s->graph.getNumberOfColors();
            s->pushColorSelectVertex(vertex, c);
            s->availableColors.insert(c);
        }
        s->printColor();

    }
    best = s; // el mejor estado es el estado actual
    return s->graph.getNumberOfColors(); // retornamos el numero de colores
}