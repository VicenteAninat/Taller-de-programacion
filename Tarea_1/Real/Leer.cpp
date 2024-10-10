#include "Leer.h"
#include "Bidon.h"

bool Leer::leerArchivo(string nombreArchivo) {
    // Abiendo el archivo
    ifstream archivo(nombreArchivo);
    // Se comprueba la existencia del archivo
    if (!archivo) {
        cerr << "Archivo no encontrado." << endl;
        return false;
    }
    else {
        // Se lee el contenido del archivo
        string lineaCapacidades; // Inicializacion de la variable receptora de la primera linea
        string lineaObjetivos; // Inicializacion de la variable receptora de la segunda linea
        getline(archivo, lineaCapacidades); // Se lee la primera linea del archivo
        getline(archivo, lineaObjetivos); // Se lee la segunda linea del archivo

        if (lineaCapacidades.length() != lineaObjetivos.length()){
            cerr << "Error en el archivo, las especificaciones de los bidones no coinciden." << endl;
            return false;
        }
        else{
            // Se inicializa la linea de capacidades para ser separada
            istringstream capacidades (lineaCapacidades);
            // Se inicializa la linea de objetivos para ser separada
            istringstream objetivos (lineaObjetivos);

            int contador = 0;

            while (capacidades && objetivos){
                string capacidad; // Se inicializa la variable receptora de la capacidad
                string objetivo; // Se inicializa la variable receptora del objetivo
                capacidades >> capacidad; // Se lee la capacidad
                objetivos >> objetivo; // Se lee el objetivo

                // Se comprueba que la capacidad y el objetivo sean numeros
                if (capacidad.find_first_not_of("0123456789") != string::npos || objetivo.find_first_not_of("0123456789") != string::npos){
                    cerr << "Error en el archivo, se espera un numero." << endl;
                    return false;
                }
                else{
                    // Se convierten las capacidades y objetivos a enteros
                    int capacidadInt = stoi(capacidad);
                    int objetivoInt = stoi(objetivo);

                    // Se crea un objeto de la clase Bidon
                    Bidon bidon(0, capacidadInt, objetivoInt);
                    // Se imprime el estado inicial
                    bidon.print();
                    contador++;
                }
            }

            // El archivo se cierra una vez leido
            archivo.close();
        }
    };
}