#include "State.h"

class ColoringOperation {
    public:
    State *best; // mejor estado encontrado

    ColoringOperation();

    int greedyColoring(State *s);

    int backtrack(State *s);

    int branchBound(State *s);
};