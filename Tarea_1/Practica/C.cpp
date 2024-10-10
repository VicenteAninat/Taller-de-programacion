#include "C.h"

C::C(int c) {
    a=100+c;
}

int C::operate(int c){
    return(10+c+a);
}