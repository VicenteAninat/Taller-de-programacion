// Archivo de implementación de la clase JugProb.h
#include "JugProb.h"    

void JugProb::resolver(GrupoBidones nodo){
    int capacidad = 10000;
    int contador;
    Queue colaNoVisitados;
    Queue colaNoVisitadosAux;
    Queue colaPorVisitar;

    colaNoVisitados.enqueue(nodo);

    GrupoBidones* all = new GrupoBidones[capacidad];
    GrupoBidones* allAux = new GrupoBidones[capacidad];
    all[0] = nodo;

    bool solucionEncontrada = false;

    int indiceAux;
    bool esSolucion;

    GrupoBidones estadoActual;

    while (!solucionEncontrada) {
        
        if (colaNoVisitadosAux.isEmpty()){
            estadoActual = colaNoVisitados.getFront();
            colaNoVisitados.dequeue();
        } else {
            estadoActual = colaNoVisitadosAux.getFront();
            colaNoVisitadosAux.dequeue();
        }

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

                if (!Hash().encontrarEstadoHash(estadoLlenado, all, codigoHash, capacidad) && 
                    !Hash().encontrarEstadoHashAux(estadoLlenado, all, codigoHash)) {
                    Hash().insertarEstadoHash(estadoLlenado, all, codigoHash, capacidad);
                    colaPorVisitar.enqueue(estadoLlenado);
                }
            }

            // Vaciado
            if (estadoActual.bidones[i]->aguaActual != 0) {
                GrupoBidones estadoVaciado = OperacionVaciar().operacion(estadoActual, i);

                int codigoHash = Hash().crearCodigoHash(estadoVaciado, capacidad);

                if (!Hash().encontrarEstadoHash(estadoVaciado, all, codigoHash, capacidad) &&
                    !Hash().encontrarEstadoHashAux(estadoVaciado, all, codigoHash)) {
                    Hash().insertarEstadoHash(estadoVaciado, all, codigoHash, capacidad);
                    colaPorVisitar.enqueue(estadoVaciado);
                }
            }

            // Trasvasado
            for (int j = 0; j < estadoActual.cantidad; j++) {
                if (i != j && estadoActual.bidones[i]->aguaActual > 0 && estadoActual.bidones[j]->aguaActual < estadoActual.bidones[j]->aguaMaxima){
                    GrupoBidones estadoTrasvasado = OperacionTrasvasijar().operacionTrasvasijar(estadoActual, i, j);

                    int codigoHash = Hash().crearCodigoHash(estadoTrasvasado, capacidad);

                    if (!Hash().encontrarEstadoHash(estadoTrasvasado, all, codigoHash, capacidad) &&
                        !Hash().encontrarEstadoHashAux(estadoTrasvasado, all, codigoHash)) {
                        Hash().insertarEstadoHash(estadoTrasvasado, all, codigoHash, capacidad);
                        colaPorVisitar.enqueue(estadoTrasvasado);
                    }
                }
            }

            // Ordenamiento segun distancia
            while (!colaPorVisitar.isEmpty()) {
                if (colaPorVisitar.getFront().distancia < estadoActual.distancia) {
                    colaNoVisitados.enqueue(colaPorVisitar.getFront());
                    colaPorVisitar.dequeue();
                } else {
                    colaNoVisitadosAux.enqueue(colaPorVisitar.getFront());
                    colaPorVisitar.dequeue();
                }
            }
            
            // Expansion de memoria de la tabla hash
            /*
            if (contador >= capacidad/2){
                capacidad = capacidad*10;
                allAux = new GrupoBidones[capacidad];
                for (int i = 0; i < capacidad/10; i++){
                    cout << "Intentando expandir" << endl;
                    allAux[i] = all[i];
                }
                cout << "Memoria expandida" << endl;
                all = allAux;
                allAux = nullptr;
            }
            */
        }

        
    }
    return;
}