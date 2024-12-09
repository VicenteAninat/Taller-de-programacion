#include "State.h"

class ColoringOperation {
    public:
    State *best; // mejor estado encontrado

    ColoringOperation();

    int greedyColoring(State *s);

    int backtrack(State *s);

    int branchBound(State *s);

    int newBranchBound(State *s, int lb);

    int newBranchBound2(State *s, int lb);

    int dSatur(State* s);

    int dSaturBranchBound(State* s, int lb, int ub);
};