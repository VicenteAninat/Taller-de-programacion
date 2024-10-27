// Archivo de implementación
#include "GrupoBidones.h"

GrupoBidones::GrupoBidones(int n) {
    bidones = new Bidon*[n];
    for (int i = 0; i < n; i++) {
        bidones[i] = new Bidon();
    }
    this->bidones = bidones;
    parent = nullptr;
    operation = "";
    this->cantidad = n;
}

GrupoBidones::GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad) {
    this->bidones = bidones;
    this->parent = parent;
    this->operation = operation;
    this->cantidad = cantidad;
}

string GrupoBidones::imprimirBidones(Bidon** bidones, int cantidad){
    string imprimir = "";
    for (int i = 0; i < cantidad; i++) {
        imprimir = imprimir + "Bidon " + to_string(i + 1) + ":\n" + bidones[i]->print() + "\n";
    }
    return imprimir;
}

string GrupoBidones::print(){
    if (parent != nullptr) {
        parent->print();
    }

    string salida = "Bidones:\n" + imprimirBidones(bidones, cantidad)+ "\n" + "Operacion: " + operation;
    return salida;
}