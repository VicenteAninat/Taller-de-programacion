#include "OperacionTrasvasijar.h"

int main() {
    GrupoBidones grupo = GrupoBidones(2);
    grupo.bidones[0] = new Bidon(2, 3, 0);
    grupo.bidones[1] = new Bidon(5, 5, 4);
    grupo.cantidad = 2;
    grupo.operation = "Estado inicial\n";

    cout << grupo.print() << endl;
    cout << "\nSe procederá a trasvasijar el bidon 2 al 1\n" << endl;
    GrupoBidones grupoSucesor = OperacionTrasvasijar().operacionTrasvasijar(grupo, 1, 0);

    cout << grupoSucesor.print() << endl;

    return 0;
}