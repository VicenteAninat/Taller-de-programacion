#include "A.h"

A::A(int a) {
    this->a = a;
}

A::A() {
    this->a = 0;
}

A::~A() {
    std::cout << "Destructor de A" << std::endl;
}

// notar que virtual va en el .h
int A::operate(int b) {
    return a + b;
}