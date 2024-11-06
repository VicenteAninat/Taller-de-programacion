#include <iostream>
#include "GrupoBidones.h"

class Queue {
public:
    struct Node {
        GrupoBidones data;
        Node* next;
        Node(GrupoBidones val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(GrupoBidones val);

    void dequeue();

    GrupoBidones getFront();

    bool isEmpty();

    int getSize();
};