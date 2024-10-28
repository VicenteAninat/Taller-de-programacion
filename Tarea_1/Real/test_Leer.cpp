#include <iostream>
#include "Leer.h"

int main() {
    Leer leer;
    GrupoBidones grupo = leer.leerArchivo("ejemplo_1.txt");

    cout << grupo.print() << endl;
    return 0;
}