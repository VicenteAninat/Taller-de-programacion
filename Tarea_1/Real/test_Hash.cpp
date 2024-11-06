#include "Hash.h"

int main() {
    GrupoBidones grupo = GrupoBidones(2);
    grupo.bidones[0] = new Bidon(0, 4, 2);
    grupo.bidones[1] = new Bidon(2, 3, 1);
    grupo.cantidad = 2;
    grupo.operation = "Estado inicial\n";

    GrupoBidones grupo2 = GrupoBidones(2);
    grupo2.bidones[0] = new Bidon(2, 4, 2);
    grupo2.bidones[1] = new Bidon(1, 3, 1);
    grupo2.cantidad = 2;
    grupo2.operation = "Estado Secundario\n";

    GrupoBidones* tablaHash = new GrupoBidones[10];

    int indice = Hash().crearCodigoHash(grupo, 10);

    if (!Hash().encontrarEstadoHash(grupo, tablaHash, indice, 10)){
        Hash().insertarEstadoHash(grupo, tablaHash, indice, 10);
    }

    if (Hash().encontrarEstadoHash(grupo, tablaHash, indice, 10)){
        cout << grupo.print() << endl;
    }

    indice = Hash().crearCodigoHash(grupo2, 10);

    if (!Hash().encontrarEstadoHash(grupo2, tablaHash, indice, 10)){
        Hash().insertarEstadoHash(grupo2, tablaHash, indice, 10);
    }

    if (Hash().encontrarEstadoHash(grupo2, tablaHash, indice, 10)){
        cout << grupo2.print() << endl;
    }

    return 0;
}