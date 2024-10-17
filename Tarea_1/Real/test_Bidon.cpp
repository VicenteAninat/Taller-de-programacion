#include "Bidon.h"

Bidon bidon1 = Bidon(0, 2, 0);
Bidon bidon2 = Bidon(0, 4, 3);

string print1 = bidon1.print();
string print2 = bidon2.print();

int main(){
    cout << "Bidon 1" << endl;
    cout << print1 << endl;
    cout << "\nBidon 2" << endl;
    cout << print2 << endl;
    return 0;
}