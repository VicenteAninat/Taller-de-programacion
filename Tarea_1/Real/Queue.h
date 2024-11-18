#include <iostream>
#include "GrupoBidones.h"

class Queue {
public:
    // Estructura de un nodo
    struct Node {
        GrupoBidones data;
        Node* next;
        Node(GrupoBidones val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:

    // Constructor por defecto
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Metodo para encolar un elemento
    void enqueue(GrupoBidones val);

    // Metodo para desencolar un elemento
    void dequeue();

    // Metodo para obtener el frente de la cola
    GrupoBidones getFront();

    // Metodo para verificar si la cola esta vacia
    bool isEmpty();

    // Metodo para obtener el tamaño de la cola
    int getSize();
};