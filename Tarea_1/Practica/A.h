#ifndef A_H
#define A_H

#include <iostream>

/*
  * Esta es la clase Madre de la cual hereredan varias otras
  * la idea es que despuesse genere un arreglo de punteros a A
  * y se itere llamando a "operate" para cada uno de los elementos
  * del arreglo de manera generica.
*/
class A {
    public:
    A(int a); // Constructor que llena a
    A(); // Constructor vacio
    ~A(); // Destructor

    int a;

    // virtual indica que se va a sobre escribir este metodo
    int virtual operate(int b); // Funcion que suma a y b    
};

#endif
