// Archivo de implementación
#include "GrupoBidones.h"

GrupoBidones::GrupoBidones(){
    // Se inicializan valores invalidos para el constructor por defecto
    this->bidones = nullptr;
    this->parent = nullptr;
    this->operation = "";
    this->cantidad = -1;
}

// Constructor por defecto de la clase GrupoBidones conociendo su cantidad
GrupoBidones::GrupoBidones(int n) {
    // Inicialización del arreglo de bidones
    bidones = new Bidon*[n];
    for (int i = 0; i < n; i++) {
        bidones[i] = new Bidon();
    }

    // Se inicializan los valores del estado
    this->bidones = bidones;
    this->parent = nullptr;
    this->operation = "";
    this->cantidad = n;
}

// Constructor de la clase GrupoBidones
GrupoBidones::GrupoBidones(Bidon** bidones, GrupoBidones *parent, string operation, int cantidad) {
    // Se inicializan los valores del estado
    this->bidones = bidones;
    this->parent = parent;
    this->operation = operation;
    this->cantidad = cantidad;

    // Se calcula la distancia al punto objetivo
    int distancia = 0;
    for (int i = 0; i < cantidad; i++){
        distancia = distancia + pow((bidones[i]->aguaActual - bidones[i]->aguaObjetivo), 2);
    }
    distancia = sqrt(distancia);
    this->distancia = distancia;
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
    string padre = "";
    // Si el padre no es nulo, se imprime primero el padre
    if (parent != nullptr) {
        padre = parent->print();
    }

    // Se imprime el estado actual concatenado con el padre
    string salida = padre + "Bidones:\n" + imprimirBidones(bidones, cantidad)+ "\n" + "Operacion: " + operation + "\n";
    return salida;
}
