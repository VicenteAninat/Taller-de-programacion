// Archivo de implementación

#include "Bidon.h"

// Constructor de la clase Bidon
Bidon::Bidon(int a0, int a1, Bidon *parent, string operation){
    this->a0 = a0;
    this->a1 = a1;
    this->parent = parent;
    this->operation = operation;
}

void Bidon::print() {
    if (parent != nullptr) {
        parent->print();
    }
    cout << "a0: " << a0 << " a1: " << a1 << " parent: " << parent << " operation: " << operation << endl;
}