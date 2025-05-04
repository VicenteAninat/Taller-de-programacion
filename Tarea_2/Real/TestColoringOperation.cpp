#include "ColoringOperation.h"

int main () {
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4},
        {1, 2}, {1, 5}, {1, 6},
        {2, 3}, {2, 6}, {2, 7},
        {3, 4}, {3, 7}, {3, 8},
        {4, 8}, {4, 9},
        {5, 6}, {6, 7}, {7, 8}, {8, 9},
        {5, 10}, {6, 10}, {7, 11}, {8, 11},
        {10, 11}, {10, 12}, {11, 12} };
    Graph graph(edges);
    
    graph.printGraph();
    cout << "\n" << endl; 
    State g(graph);
    State* s = &g;

    ColoringOperation co;

    int coloresGreedy = co.greedyColoring(s);
    cout << "Numero de colores Greedy: " << coloresGreedy << endl;

    int coloresDSatur = co.dSatur(s);
    cout << "Numero de colores DSatur: " << coloresDSatur << endl;

    int coloresBacktrack = co.backtrack(s);
    cout << "Numero de colores Backtrack: " << coloresBacktrack << endl;

    int ub = co.greedyColoring(s);
    int colores = co.dSaturBranchBound(s, 0, ub);
    cout << "Numero de colores Branch and Bound (con DSatur): " << colores << endl;
}