#include "Read.h"

int main () {
    string fileName;
    cout << "Ingrese el nombre del archivo: ";
    cin >> fileName;
    fileName = fileName + ".txt";
    
    Read r;
    State* s = r.readFile(fileName);
    s->graph.printGraph();
    cout << "Lectura exitosa" << endl;
}