#include "OperacionTrasvasijar.h"

int main() {
    GrupoBidones grupo = GrupoBidones(2);
    grupo.bidones[0] = new Bidon(4, 4, 2);
    grupo.bidones[1] = new Bidon(3, 3, 1);

    cout << grupo.print() << endl;
    cout << "\nSe procederá a trasvasijar el bidon 1 al 2\n" << endl;
    GrupoBidones grupoSucesor = OperacionTrasvasijar().operacionTrasvasijar(grupo, 0, 1);

    cout << grupoSucesor.print() << endl;

    return 0;
}