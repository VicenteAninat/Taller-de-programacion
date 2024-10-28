// Archivo de implementación
#include "Bidon.h"

// Constructor por defecto de la clase Bidon
Bidon::Bidon() {
    // Se inicializan valores invalidos para el constructor por defecto
    this->aguaActual = -1;
    this->aguaMaxima = -1;
    this->aguaObjetivo = -1;
}

// Constructor de la clase Bidon
Bidon::Bidon(int aguaActual, int aguaMaxima, int aguaObjetivo) {
    this->aguaActual = aguaActual;
    this->aguaMaxima = aguaMaxima;
    this->aguaObjetivo = aguaObjetivo;
}

string Bidon::print() {
    // String con la informacion del bidon en cuestion
    string salida = "Agua actual: " + to_string(aguaActual) + "\n" + "Agua maxima: " 
    + to_string(aguaMaxima) + "\n" + "Agua objetivo: " + to_string(aguaObjetivo);
    return salida;
}