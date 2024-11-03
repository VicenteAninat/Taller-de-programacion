// Archivo de implementación de la clase JugProb.h
#include "JugProb.h"

void JugProb::resolver(GrupoBidones nodo){
    std::mt19937 gen(123);
    int capacidad = 100;

    int cantidad = nodo.cantidad;

    // crear no visitados (arreglo de aumento de memoria)
    GrupoBidones* noVisitados = new GrupoBidones[capacidad];
    GrupoBidones* noVisitadosAux = new GrupoBidones[capacidad];
    // crear all (arreglo de aumento de memoria)
    GrupoBidones* all = new GrupoBidones[capacidad];

    noVisitados[0] = nodo;
    all[0] = nodo;
    
    bool solucionEncontrada = false;
    int frecuenciaDeSaltos = 0; // Variable para controlar la frecuencia de saltos de fe

    while(!solucionEncontrada) { // El ciclo continua hasta que se encuentre una solución
        for (int i = 0; i < capacidad - 1; i++){ // Iteracion por el arreglo de noVisitados
            int indiceAux = 0;
            if (noVisitados[i].bidones == nullptr) { 
                // Si el arreglo de noVisitados en la posición i es nulo, se termina el ciclo
                break;
            }
            else{
                // Se comprueba si el estado actual es solución
                bool esSolucion = true;
                for (int j = 0; j < noVisitados[i].cantidad - 1; j++){
                    if (noVisitados[i].bidones[j]->aguaActual != noVisitados[i].bidones[j]->aguaObjetivo){
                        esSolucion = false;
                        break;
                    }
                }
            
                // Si el estado actual es solución, se termina el ciclo
                if (esSolucion){
                    solucionEncontrada = true;
                    cout << "Solucion encontrada: \n" << noVisitados[i].print() << endl;
                    break;
                }

                // Se opera el estado actual
                for (int j = 0; j < noVisitados[i].cantidad; j++) {
                    // Si el bidon no está lleno, se puede llenar
                    if (noVisitados[i].bidones[j]->aguaActual != noVisitados[i].bidones[j]->aguaMaxima){
                        GrupoBidones estadoLlenado = OperacionLlenar().operacion(noVisitados[i], j);
                        int codigoHash = Hash().crearCodigoHash(estadoLlenado, capacidad);
                        if (!Hash().buscarEstadoHash(estadoLlenado, all, codigoHash, capacidad)){
                            Hash().insertarEstadoHash(estadoLlenado, all, codigoHash);
                            noVisitadosAux[indiceAux] = estadoLlenado;
                            indiceAux++;
                        }
                        
                    }
                    
                    // Si el bidon no está vacío, se puede vaciar
                    if (noVisitados[i].bidones[j]->aguaActual != 0){
                        GrupoBidones estadoVaciado = OperacionVaciar().operacion(noVisitados[i], j);
                        int codigoHash = Hash().crearCodigoHash(estadoVaciado, capacidad);
                        if (!Hash().buscarEstadoHash(estadoVaciado, all, codigoHash, capacidad)){
                            Hash().insertarEstadoHash(estadoVaciado, all, codigoHash);
                            noVisitadosAux[indiceAux] = estadoVaciado;
                            indiceAux++;
                        }
                    }
                    // Si los bidones no están llenos y no está vacíos, se pueden trasvasijar
                    for (int k = 0; k < noVisitados[i].cantidad; k++){
                        if (j != k && !(
                            (noVisitados[i].bidones[j]->aguaActual != 0 && noVisitados[i].bidones[k]->aguaActual != 0) || 
                            (noVisitados[i].bidones[j]->aguaActual != noVisitados[i].bidones[j]->aguaMaxima && noVisitados[i].bidones[k]->aguaActual != noVisitados[i].bidones[k]->aguaMaxima)
                            )){
                            GrupoBidones estadoTrasvasijado = OperacionTrasvasijar().operacionTrasvasijar(noVisitados[i], j, k);
                            int codigoHash = Hash().crearCodigoHash(estadoTrasvasijado, capacidad);
                            if (!Hash().buscarEstadoHash(estadoTrasvasijado, all, codigoHash, capacidad)){
                                Hash().insertarEstadoHash(estadoTrasvasijado, all, codigoHash);
                                noVisitadosAux[indiceAux] = estadoTrasvasijado;
                                indiceAux++;
                            }
                        }
                    }
                }

                // Comprobar cuanta memoria le queda a los arreglos
                // Si no hay memoria, se aumenta la capacidad de los arreglos
                if (indiceAux >= (capacidad * 3 / 4)){
                    capacidad *= 10;
                    GrupoBidones* noVisitadosAux2 = new GrupoBidones[capacidad];
                    GrupoBidones* allAux = new GrupoBidones[capacidad];
                    for (int i = 0; i < capacidad - 1; i++){
                        noVisitadosAux2[i] = noVisitadosAux[i];
                        allAux[i] = all[i];
                    }
                    noVisitadosAux = noVisitadosAux2;
                    all = allAux;
                }
            }
        }

        // Se actualiza el arreglo de noVisitados con los nuevos estados de noVisitadosAux
        GrupoBidones* noVisitadosAux2 = new GrupoBidones[capacidad];
        for (int i = 0; i < capacidad - 1; i++){
            noVisitadosAux2[i] = noVisitadosAux[i];
        }
        noVisitados = noVisitadosAux2; // Se actualiza el arreglo de noVisitados
        noVisitadosAux = new GrupoBidones[capacidad]; // Se limpia el arreglo de noVisitadosAux
    }

    return;
}