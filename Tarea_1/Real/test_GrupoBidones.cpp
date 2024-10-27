#include "GrupoBidones.h"

int main() {
    Bidon* bidon1 = new Bidon(0, 2, 0);
    Bidon* bidon2 = new Bidon(0, 4, 3);

    Bidon** bidones;
    bidones = new Bidon* [2];

    bidones[0] = bidon1;
    bidones[1] = bidon2;

GrupoBidones grupo1 = GrupoBidones(bidones, NULL, "Inicial", 2);

    cout << grupo1.print() << endl;
    return 0;
}