#include "Hash.h"

// Método para crear un código hash
int Hash::crearCodigoHash(GrupoBidones grupo, int numeroEstados){
    int codigoHash = 0;
    for (int i = 0; i < grupo.cantidad; i++){
        codigoHash += (grupo.bidones[i]->aguaActual)*(i+1);
    }
    codigoHash = codigoHash % numeroEstados;
    return codigoHash;
}

bool Hash::encontrarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    if (tablaHash[indice].bidones == nullptr){
        return false;
    }
    else {
        bool encontrado = true;
        for (int i = 0; i < estado.cantidad; i++){
            // Memcmp
            if (tablaHash[indice].bidones[i]->aguaActual != estado.bidones[i]->aguaActual){
                encontrado = false;
                break;
            }
        }
        if (encontrado){
            return true;
        }

        if (indice < capacidad){
        return encontrarEstadoHash(estado, tablaHash, indice + 1, capacidad);
        }
        return false;
    }
    /*
    if (indice < capacidad){
        return encontrarEstadoHash(estado, tablaHash, indice + 1, capacidad);
    }
    // Verificar si el estado en el índice dado es igual al estado buscado
    for (int i = 0; i < estado.cantidad; i++){
        if (tablaHash[indice].bidones[i]->aguaActual != estado.bidones[i]->aguaActual){
            encontrado = false;
        }
    }

    if (encontrado){
        return true;
    }

    encontrado = true;
    // Si no se encuentra en el índice dado, buscar en el resto de la tabla
    for (int i = (indice + 1) % capacidad; i != indice; i = (i + 1) % capacidad) {
        if (tablaHash[i].bidones == nullptr) {
            // Si encontramos un espacio vacío, el estado no está en la tabla
            return false;
        }
        for (int i = 0; i < estado.cantidad; i++){
            if (tablaHash[indice].bidones[i]->aguaActual != estado.bidones[i]->aguaActual){
                encontrado = false;
            }
        }
        if (encontrado){
            return true;
        }
        encontrado = true;
    }
    // Si hemos recorrido toda la tabla y no encontramos el estado, devolver false
    return false;
    */
}

void Hash::insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    if (tablaHash[indice].bidones == nullptr){
        tablaHash[indice] = estado;
    }
    else{
        for (int i = indice; i < capacidad; i++){
            if (tablaHash[i].bidones == nullptr){
                tablaHash[i] = estado;
                break;
            }
        }
    }
}

int Hash::calcularAcumulacion(GrupoBidones grupo, GrupoBidones* tablaHash, int indice, int capacidad){
    bool sonIguales = true;
    for (int i = 0; i < grupo.cantidad; i++){
        if(grupo.bidones[i]->aguaActual != tablaHash[indice].bidones[i]->aguaActual){
            sonIguales = false;
            break;
        }
    }
    if (sonIguales){
        return 0;
    }
    else{
        return 1 + calcularAcumulacion(grupo, tablaHash, indice + 1, capacidad);
    }
}

bool Hash::buscarCompararMemoria(GrupoBidones grupo1, GrupoBidones* tablaHash, int cantidad){
    for (int i = 0; i < cantidad; i++){
        if (memcmp(tablaHash[i].bidones, grupo1.bidones[i], grupo1.cantidad*sizeof(int)) != 0){
            return false;
        }
    }
    return true;
}