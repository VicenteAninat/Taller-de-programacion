// Archivo de implementación
#include "GrupoBidones.h"

GrupoBidones::GrupoBidones(Bidon *bidones[], GrupoBidones *parent, string operation) {
    this->bidon = bidones;
    this->parent = parent;
    this->operation = operation;
}

string GrupoBidones::imprimirBidones(Bidon *bidones[]){
    string imprimir = "";
    for (int i = 0; i < sizeof(bidones); i++) {
        imprimir = imprimir + "Bidon " + to_string(i) + ": " + bidones[i]->print() + "\n";
    }
    return imprimir;
}

void GrupoBidones::print(){
    if (parent != nullptr) {
        parent->print();
    }

    cout << "Imprimir bidones" << "Operacion: " << operation << endl;
}