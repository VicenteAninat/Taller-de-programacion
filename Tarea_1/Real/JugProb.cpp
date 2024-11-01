// Archivo de implementación de la clase JugProb.h
#include "JugProb.h"

// Método para crear un código hash
int crearCodigoHash(GrupoBidones grupo, int numeroEstados){
    int codigoHash = 0;
    for (int i = 0; i < grupo.cantidad; i++){
        codigoHash += (grupo.bidones[i]->aguaActual)*(i+1);
    }
    codigoHash = codigoHash % numeroEstados;
    return codigoHash;
}

// Método para insertar un estado en una tabla hash
void insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice){
    bool insertado = false;
    while (!insertado){
        if (tablaHash[indice].bidones != nullptr){
            indice++;
        }
        else{
            tablaHash[indice] = estado;
            insertado = true;
        }
    }

    return;
}

// Método para verificar si un estado ya ha sido calculado
bool buscarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    bool encontrado = false;
    while (!encontrado && (indice < capacidad - 1)){
        if (tablaHash[indice].bidones == nullptr){
            break;
        }
        else{
            if (tablaHash[indice].bidones == estado.bidones){
                encontrado = true;
                break;
            }
            else{
                indice++;
            }
        }
    }

    return encontrado;
}

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
                        GrupoBidones estadoLlenado = OperacionLlenar::operacion(noVisitados[i], j);
                        int codigoHash = crearCodigoHash(estadoLlenado, capacidad);
                        if (!buscarEstadoHash(estadoLlenado, all, codigoHash, capacidad)){
                            insertarEstadoHash(estadoLlenado, all, codigoHash);
                            noVisitadosAux[indiceAux] = estadoLlenado;
                            indiceAux++;
                        }
                        
                    }

                    // Si el bidon no está vacío, se puede vaciar
                    if (noVisitados[i].bidones[j]->aguaActual != 0){
                        GrupoBidones estadoVaciado = OperacionVaciar::operacion(noVisitados[i], j);
                        int codigoHash = crearCodigoHash(estadoVaciado, capacidad);
                        if (!buscarEstadoHash(estadoVaciado, all, codigoHash, capacidad)){
                            insertarEstadoHash(estadoVaciado, all, codigoHash);
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
                            GrupoBidones estadoTrasvasijado = OperacionTrasvasijar::operacion(noVisitados[i], j, k);
                            int codigoHash = crearCodigoHash(estadoTrasvasijado, capacidad);
                            if (!buscarEstadoHash(estadoTrasvasijado, all, codigoHash, capacidad)){
                                insertarEstadoHash(estadoTrasvasijado, all, codigoHash);
                                noVisitadosAux[indiceAux] = estadoTrasvasijado;
                                indiceAux++;
                            }
                        }
                    }
                }

                // Comprobar cuanta memoria le queda a los arreglos
                // Si no hay memoria, se aumenta la capacidad de los arreglos
            }
        }

        // Se actualiza el arreglo de noVisitados con los nuevos estados de noVisitadosAux
    }

    return;
}