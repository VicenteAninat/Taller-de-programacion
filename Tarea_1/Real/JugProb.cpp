// Archivo de implementación de la clase JugProb.h
#include "JugProb.h"

int JugProb::calcularDistancia(GrupoBidones estado){
    int distancia = 0;
    for (int i = 0; i < estado.cantidad; i++){
        distancia += abs(estado.bidones[i]->aguaActual - estado.bidones[i]->aguaObjetivo);
    }
    return distancia;
}

void JugProb::resolver(GrupoBidones nodo){
    int capacidad = 1000;
    Queue colaNoVisitados;
    Queue colaPorVisitar;

    colaNoVisitados.enqueue(nodo);

    GrupoBidones* all = new GrupoBidones[capacidad];
    all[0] = nodo;

    bool solucionEncontrada = false;

    int indiceAux;
    bool esSolucion;

    while (!solucionEncontrada) {
        GrupoBidones estadoActual = colaNoVisitados.getFront();
        colaNoVisitados.dequeue();

        // Se comprueba si el estado actual es solución
        esSolucion = true;

        for (int i = 0; i < estadoActual.cantidad; i++){
            if (estadoActual.bidones[i]->aguaActual != estadoActual.bidones[i]->aguaObjetivo){
                esSolucion = false;
            }
        }
            
        // Si el estado actual es solución, se termina el ciclo
        if (esSolucion){
            solucionEncontrada = true;
            cout << "Solucion encontrada: \n" << estadoActual.print() << endl;
            break;
        }

        for (int i = 0; i < estadoActual.cantidad; i++) {
            // Llenado
            if (estadoActual.bidones[i]->aguaActual != estadoActual.bidones[i]->aguaMaxima) {
                GrupoBidones estadoLlenado = OperacionLlenar().operacion(estadoActual, i);

                int codigoHash = Hash().crearCodigoHash(estadoLlenado, capacidad);

                if (!Hash().buscarCompararMemoria(estadoLlenado, all, capacidad)) {
                    Hash().insertarEstadoHash(estadoLlenado, all, codigoHash, capacidad);
                    colaNoVisitados.enqueue(estadoLlenado);
                }
            }

            // Vaciado
            if (estadoActual.bidones[i]->aguaActual != 0) {
                GrupoBidones estadoVaciado = OperacionVaciar().operacion(estadoActual, i);

                int codigoHash = Hash().crearCodigoHash(estadoVaciado, capacidad);

                if (!Hash().buscarCompararMemoria(estadoVaciado, all, capacidad)) {
                    Hash().insertarEstadoHash(estadoVaciado, all, codigoHash, capacidad);
                    colaNoVisitados.enqueue(estadoVaciado);
                }
            }

            // Trasvasado
            for (int j = 0; j < estadoActual.cantidad; j++) {
                if (i != j && estadoActual.bidones[i]->aguaActual > 0 && estadoActual.bidones[j]->aguaActual < estadoActual.bidones[j]->aguaMaxima){
                    GrupoBidones estadoTrasvasado = OperacionTrasvasijar().operacionTrasvasijar(estadoActual, i, j);

                    int codigoHash = Hash().crearCodigoHash(estadoTrasvasado, capacidad);

                    if (!Hash().buscarCompararMemoria(estadoTrasvasado, all, capacidad)) {
                        Hash().insertarEstadoHash(estadoTrasvasado, all, codigoHash, capacidad);
                        colaNoVisitados.enqueue(estadoTrasvasado);
                    }
                }
            }
        }

        
    }
    return;
}