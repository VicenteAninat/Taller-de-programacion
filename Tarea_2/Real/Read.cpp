#include "Read.h"

Read::Read() {
}

State* Read::readFile(string fileName){
    fileName = "grafos/" + fileName;
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return nullptr;
    }

    // Mientras no se haya llegado al final del archivo
    int n, m;
    vector<vector<int>> edges;
    while (!file.eof()) {
        file >> n >> m;
        edges.push_back({n, m});
        edges.push_back({m, n});
    }

    Graph graph(edges);
    State *s = new State(graph);
    return s;
}