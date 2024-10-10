// Archivo de implementación
#include "Bidon.h"

// Constructor de la clase Bidon
Bidon::Bidon() {
    aguaActual = 0;
    aguaMaxima = 0;
    aguaObjetivo = 0;
}

Bidon::Bidon(int aguaActual, int aguaMaxima, int aguaObjetivo) {
    this->aguaActual = aguaActual;
    this->aguaMaxima = aguaMaxima;
    this->aguaObjetivo = aguaObjetivo;
}

string Bidon::print() {
    string salida = "Agua actual: " + std::to_string(aguaActual) + "\n" + "Agua maxima: " + std::to_string(aguaMaxima) + "\n" + "Agua objetivo: " + std::to_string(aguaObjetivo);
}