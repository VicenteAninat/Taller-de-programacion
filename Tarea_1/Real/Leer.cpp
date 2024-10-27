#include "Leer.h"


int getMCD(int a, int b) {
    if(b == 0) return a;
    return getMCD(b, a%b);
}

GrupoBidones* Leer::leerArchivo(string nombreArchivo) {
    // Abiendo el archivo
    ifstream archivo(nombreArchivo);
    // Se comprueba la existencia del archivo
    if (!archivo) {
        cerr << "Archivo no encontrado." << endl;
        return nullptr;
    }
    else {
        // Se lee el contenido del archivo
        string lineaCapacidades; // Inicializacion de la variable receptora de la primera linea
        string lineaObjetivos; // Inicializacion de la variable receptora de la segunda linea
        getline(archivo, lineaCapacidades); // Se lee la primera linea del archivo
        getline(archivo, lineaObjetivos); // Se lee la segunda linea del archivo

        if (lineaCapacidades.length() != lineaObjetivos.length()){
            cerr << "Error en el archivo, las especificaciones de los bidones no coinciden." << endl;
            return nullptr;
        }
        else{
            // Se inicializa la linea de capacidades para ser separada
            istringstream capacidades (lineaCapacidades);
            // Se inicializa la linea de objetivos para ser separada
            istringstream objetivos (lineaObjetivos);

            int contador = 0;
            istringstream capacidades2 (lineaCapacidades);

            while (capacidades2) {
                string capacidad;
                capacidades2 >> capacidad;
                if (capacidad.find_first_not_of("0123456789") != string::npos){
                    cerr << "Error en el archivo, se espera un numero." << endl;
                    return nullptr;
                }
                else{
                    contador++;
                }
            }

            // Se crea un arreglo de punteros a objetos de la clase Bidon
            Bidon** bidones = new Bidon*[contador];

            int arrCapacidades[contador];

            int index = 0; // Se inicializa el indice de los bidones

            while (capacidades && objetivos){
                string capacidad; // Se inicializa la variable receptora de la capacidad
                string objetivo; // Se inicializa la variable receptora del objetivo
                capacidades >> capacidad; // Se lee la capacidad
                objetivos >> objetivo; // Se lee el objetivo

                // Se comprueba que la capacidad y el objetivo sean numeros
                if (capacidad.find_first_not_of("0123456789") != string::npos || objetivo.find_first_not_of("0123456789") != string::npos){
                    cerr << "Error en el archivo, se espera un numero." << endl;
                    return nullptr;
                }
                else{
                    // Se convierten las capacidades y objetivos a enteros
                    int capacidadInt = stoi(capacidad);
                    int objetivoInt = stoi(objetivo);

                    // Se crea un puntero a un objeto de la clase Bidon
                    Bidon* bidon = new Bidon(0, capacidadInt, objetivoInt);

                    // Se almacena el puntero en el arreglo de punteros
                    bidones[index] = bidon;
                    arrCapacidades[index] = capacidadInt;
                    index++;

                    // Se imprime el estado inicial= capacidades
                    bidon->print();
                    contador++;
                }
            }

            // Se comprueba que las capacidades sean coprimas
            int mcd = 0;
            for (int i = 0; i < contador; i++){
                if (i == 0){
                    mcd = getMCD(arrCapacidades[0], arrCapacidades[1]);
                } else {
                    mcd = getMCD(mcd, arrCapacidades[i]);
                }
                i++;
            }
            if (mcd != 1){
                cerr << "Error en el archivo, las capacidades no son coprimas." << endl;
                // El archivo se cierra una vez leido
                archivo.close();
                return nullptr;
            } else {
                cout << "Archivo valido.\n" << endl;
                GrupoBidones* grupoBidones = new GrupoBidones(bidones, nullptr, "Estado inicial");
                // El archivo se cierra una vez leido
                archivo.close();
                return grupoBidones;
            }
        }
    }
}