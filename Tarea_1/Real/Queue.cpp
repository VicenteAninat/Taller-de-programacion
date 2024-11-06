#include "Queue.h"

void Queue::enqueue(GrupoBidones val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot dequeue." << std::endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    size--;
    if (isEmpty()) {
        rear = nullptr;
    }
}

GrupoBidones Queue::getFront() {
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot get front." << std::endl;
        exit(EXIT_FAILURE);
    }
    return front->data;
}

bool Queue::isEmpty() {
    return size == 0;
}

int Queue::getSize() {
    return size;
}