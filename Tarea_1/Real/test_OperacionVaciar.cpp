#include "OperacionVaciar.h"

int main() {
    GrupoBidones grupo = GrupoBidones(2);
    grupo.bidones[0] = new Bidon(0, 4, 2);
    grupo.bidones[1] = new Bidon(3, 3, 1);

    cout << grupo.print() << endl;
    cout << "\nSe procederá a vaciar el bidon 2\n" << endl;
    GrupoBidones grupoSucesor = OperacionVaciar().operacion(grupo, 1);

    cout << grupoSucesor.print() << endl;

    return 0;
}