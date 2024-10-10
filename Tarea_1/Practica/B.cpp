#include "B.h"

B::B(int a, int b) {
    this->a = a+b; 
}

int B::operate(int x) {
    return 3*a+x;
}