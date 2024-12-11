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
    } 
    else {    
        // caso recursivo
        int vertex = s->getVertex(); // se puede porque aun existen vertices sin colorear
        s->incrementColor(); // incrementamos el numero de colores
        for(int color : s->availableColors) {
            if (s->graph.canColor(vertex, color)) {
                State *s1 = new State(*s);
                s1->pushColorSelectVertex(vertex, color);
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

int ColoringOperation::dSatur(State* s) {
    while (!s->isAllColored()) {
        // Elección del vertice más saturado
        auto vertex = s->getVertex();
        int maxSaturation = 0;
        set <int> colors;
        for (auto vertexCandidate : s->uncoloredVertices) {
            int saturation = 0;
            for (auto neighbor : s->graph.vertexNeighbors[vertexCandidate]) {
                if (s->isVertexColored(neighbor)) {
                    if (colors.find(s->graph.vertexColor[neighbor]) != colors.end()) {
                        // No hace nada
                    }
                    else {
                        saturation++;
                        colors.insert(s->graph.vertexColor[neighbor]);
                    }
                }

                if (saturation > maxSaturation) {
                    maxSaturation = saturation;
                    vertex = vertexCandidate;
                }
            }
        }

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

int ColoringOperation::dSaturBranchBound(State* s, int lb, int ub) {
    // caso base
    if (s->isAllColored()) { // este estado es una hoja del algortimo
        if (best == nullptr || s->graph.getNumberOfColors() < ub) {
            best = s;
            ub = best->graph.getNumberOfColors();
        }
        return best->graph.getNumberOfColors();
    }
    else {
        if (max(s->graph.getNumberOfColors(), lb) < ub) { // Esta es la poda del BnB
            // Elección del vertice más saturado
            auto vertex = s->getVertex();
            int maxSaturation = 0;
            set <int> colors;
            for (auto vertexCandidate : s->uncoloredVertices) {
                int saturation = 0;
                for (auto neighbor : s->graph.vertexNeighbors[vertexCandidate]) {
                    if (s->isVertexColored(neighbor)) {
                        if (colors.find(s->graph.vertexColor[neighbor]) != colors.end()) {
                            // No hace nada
                        }
                        else {
                            saturation++;
                            colors.insert(s->graph.vertexColor[neighbor]);
                        }
                    }

                    if (saturation > maxSaturation) {
                        maxSaturation = saturation;
                        vertex = vertexCandidate;
                    }
                }
            }
            
            // encuentro el primer color disponible que sea factible (no igual al un color de vecinos)
            s->incrementColor();
            for (auto color : s->availableColors) {
                if (s->graph.canColor(vertex, color)) {
                    State* s1 = new State(*s);
                    s1->pushColorSelectVertex(vertex, color);
                    lb = dSatur(s1);
                    dSaturBranchBound(s1, lb, ub); // Llamado recursivo
                }
            }

            // consulto si no se pudo colorear el vertice vertex
            if (!s->isVertexColored(vertex)) { 
                State* s1 = new State(*s);
                int c = s->graph.getNumberOfColors();
                s1->pushColorSelectVertex(vertex, c);
                s1->availableColors.insert(c);
                lb = dSatur(s1);
                dSaturBranchBound(s1, lb, ub); // Llamado recursivo
            }
        }
        return best->graph.getNumberOfColors();
    }
}
