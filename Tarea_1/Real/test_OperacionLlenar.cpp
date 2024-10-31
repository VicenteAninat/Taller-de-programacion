#include "OperacionLlenar.h"

int main() {
    GrupoBidones grupo = GrupoBidones(2);
    grupo.bidones[0] = new Bidon(0, 4, 2);
    grupo.bidones[1] = new Bidon(0, 3, 1);

    cout << grupo.print() << endl;
    cout << "\nSe procederá a llenar el bidon 1\n" << endl;
    GrupoBidones grupoSucesor = OperacionLlenar().operacion(grupo, 0);

    cout << grupoSucesor.print() << endl;

    return 0;
}