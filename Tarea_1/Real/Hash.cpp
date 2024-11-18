#include "Hash.h"

// Método para crear un código hash
int Hash::crearCodigoHash(GrupoBidones grupo, int numeroEstados){
    int codigoHash = 0;
    // Sumar el producto de la cantidad de agua en cada bidón por su posición
    for (int i = 0; i < grupo.cantidad; i++){
        codigoHash += (grupo.bidones[i]->aguaActual)*(i+1);
    }
    // Tomar el módulo del código hash con el número de estados
    codigoHash = codigoHash % numeroEstados;
    return codigoHash;
}

bool Hash::encontrarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    // Si el estado actual es nulo, no está en la tabla
    if (tablaHash[indice].bidones == nullptr){
        return false;
    }
    // Si el estado actual no es nulo, puede que sea el estado buscado
    else {
        bool encontrado = true;
        for (int i = 0; i < estado.cantidad; i++){
            // Si alguno de los bidones no es igual, el estado no es igual
            if (tablaHash[indice].bidones[i]->aguaActual != estado.bidones[i]->aguaActual){
                encontrado = false;
                break;
            }
        }
        if (encontrado){
            return true;
        }

        // Si aun queda espacio en la tabla, buscar en el resto de la tabla
        if (indice < capacidad){
            // Llamada recursiva
            return encontrarEstadoHash(estado, tablaHash, indice + 1, capacidad);
        }
        return false;
    }
}

bool Hash::encontrarEstadoHashAux(GrupoBidones estado, GrupoBidones* tablaHash, int indice){
    bool encontrado = true;
    // Se busca el estado en la tabla hash desde el inicio hasta el indice
    for (int i = 0; i < indice - 1; i++){
        // Si el estado actual es nulo, no está en la tabla
        if (tablaHash[i].bidones == nullptr){
            return false;
        }

        for (int j = 0; j < estado.cantidad; j++){
            // Si alguno de los bidones no es igual, el estado no es igual
            if(tablaHash[i].bidones[j]->aguaActual != estado.bidones[j]->aguaActual){
                encontrado = false;
            }
        }
        // Si se encontró el estado, se retorna verdadero
        if (encontrado){
            return true;
        }
        // Reinicio de la variable encontrado para la siguiente iteración
        encontrado = true;
    }
    // Si no se encontró el estado, se retorna falso
    return false;
}

void Hash::insertarEstadoHash(GrupoBidones estado, GrupoBidones* tablaHash, int indice, int capacidad){
    // Si el estado actual es nulo, se inserta el estado
    if (tablaHash[indice].bidones == nullptr){
        tablaHash[indice] = estado;
    }
    // Si el estado actual no es nulo, se busca un espacio vacío en la tabla
    else{
        bool insetado = false;
        for (int i = indice; i < capacidad; i++){
            // Si se encuentra un espacio vacío, se inserta el estado
            if (tablaHash[i].bidones == nullptr){
                tablaHash[i] = estado;
                insetado = true;
                break;
            }
        }
        // Si no se encontró un espacio vacío, se busca desde el inicio hasta el indice
        for (int i = 0; i < indice; i++){
            // Si se encuentra un espacio vacío, se inserta el estado
            if (tablaHash[i].bidones == nullptr){
                tablaHash[i] = estado;
                insetado = true;
                break;
            }
        }
        // Si no se insertó el estado, se imprime un mensaje de error
        if (!insetado){
            cerr << "Error al insertar el estado en la tabla hash." << endl;
        }
        return;
    }
}

int Hash::calcularAcumulacion(GrupoBidones grupo, GrupoBidones* tablaHash, int indice, int capacidad){
    bool sonIguales = true;
    // Se verifica que el estado actual sea igual al estado en la tabla hash
    for (int i = 0; i < grupo.cantidad; i++){
        if(grupo.bidones[i]->aguaActual != tablaHash[indice].bidones[i]->aguaActual){
            sonIguales = false;
            break;
        }
    }
    // Si los estados son iguales, se retorna 0
    if (sonIguales){
        return 0;
    }
    // Si los estados no son iguales, se retorna 1 más la llamada recursiva
    else{
        // Llamada recursiva
        return 1 + calcularAcumulacion(grupo, tablaHash, indice + 1, capacidad);
    }
}

bool Hash::buscarCompararMemoria(GrupoBidones grupo1, GrupoBidones* tablaHash, int cantidad){
    for (int i = 0; i < cantidad; i++){
        // Si la memoria de los bidones no es igual, se retorna falso
        if (memcmp(tablaHash[i].bidones, grupo1.bidones[i], grupo1.cantidad*sizeof(int)) != 0){
            return false;
        }
    }
    // Si la memoria de los bidones es igual, se retorna verdadero
    return true;
}