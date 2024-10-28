// Archivo de implementación
#include "GrupoBidones.h"

// Constructor por defecto de la clase GrupoBidones
GrupoBidones::GrupoBidones(int n) {
    // Inicialización del arreglo de bidones
    bidones = new Bidon*[n];
    for (int i = 0; i < n; i++) {
        bidones[i] = new Bidon();
    }

    this->bidones = bidones;
    this->parent = nullptr;
    this->operation = "";
    this->cantidad = n;
}

// Constructor de la clase GrupoBidones
GrupoBidones::GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad) {
    this->bidones = bidones;
    this->parent = parent;
    this->operation = operation;
    this->cantidad = cantidad;
}

// Función para imprimir los bidones de un arreglo
string GrupoBidones::imprimirBidones(Bidon** bidones, int cantidad){
    string imprimir = "";
    for (int i = 0; i < cantidad; i++) {
        imprimir = imprimir + "Bidon " + to_string(i + 1) + ":\n" + bidones[i]->print() + "\n";
    }
    
    return imprimir;
}

// Función para imprimir el estado y toda la secuencia de operaciones que lo generaron
string GrupoBidones::print(){
    if (parent != nullptr) {
        parent->print();
    }

    string salida = "Bidones:\n" + imprimirBidones(bidones, cantidad)+ "\n" + "Operacion: " + operation;
    return salida;
}