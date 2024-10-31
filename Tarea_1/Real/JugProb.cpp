// Archivo de implementación de la clase JugProb.h
#include "JugProb.h"

void JugProb::resolver(GrupoBidones nodo){
    std::mt19937 gen(123);
    int capacidad = 100;

    int cantidad = nodo.cantidad;

    // crear no visitados (arreglo de aumento de memoria)
    GrupoBidones* noVisitados = new GrupoBidones[capacidad];
    // crear all (arreglo de aumento de memoria)
    GrupoBidones* all = new GrupoBidones[capacidad];

    noVisitados[0] = nodo;
    
    bool solucionEncontrada = false;

    while(!solucionEncontrada) {
        // Si no hay nodos en noVisitados, no hay solución
        if(cantidad == 0){
            std::cout << "No hay solucion" << std::endl;
            return;
        }

        // Tomar el primer nodo de noVisitados
        GrupoBidones nodoActual = noVisitados[0];

        // Si el nodo actual es solución, terminar
        if(nodoActual.bidones[0]->aguaActual == 2 || nodoActual.bidones[1]->aguaActual == 2){
            std::cout << nodoActual.print() << std::endl;
            solucionEncontrada = true;
            return;
        }

        // Eliminar el nodo actual de noVisitados
        for(int i = 0; i < cantidad - 1; i++){
            noVisitados[i] = noVisitados[i + 1];
        }

        cantidad--;

        // Agregar el nodo actual a all
        all[cantidad] = nodoActual;

        // Generar los sucesores del nodo actual
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    GrupoBidones nodoSucesor = nodoActual;
                    if(i == 0){
                        nodoSucesor = OperacionLlenar().operacion(nodoSucesor, j);
                    }else if(i == 1){
                        nodoSucesor = OperacionVaciar().operacion(nodoSucesor, j);
                    }else{
                        nodoSucesor = OperacionTrasvasijar().operacion(nodoSucesor, j, (j + 1) % 2);
                    }

                    // Si el nodo sucesor no está en all, agregarlo a noVisitados
                    bool estaEnAll = false;
                    for(int k = 0; k < cantidad; k++){
                        if(nodoSucesor.print() == all[k].print()){
                            estaEnAll = true;
                            break;
                        }
                    }

                    if(!estaEnAll){
                        noVisitados[cantidad] = nodoSucesor;
                        cantidad++;
                    }
                }
            }
        }
    }

    return;
}