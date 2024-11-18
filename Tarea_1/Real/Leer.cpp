#include "Leer.h"

// Metodo auxiliar para obtener el MCD de dos numeros
int Leer::getMCD(int a, int b){
    if (a == 0){
        return b;
    }
    return getMCD(b % a, a);
}

// Metodo para leer un archivo y retornar un puntero a GrupoBidones
GrupoBidones Leer::leerArchivo(string nombreArchivo) {
    // Abiendo el archivo
    ifstream archivo(nombreArchivo);

    // Se comprueba la existencia del archivo
    if (!archivo) {
        cerr << "Archivo no encontrado." << endl;
        return GrupoBidones(0);
    }
    else {
        // Se lee el contenido del archivo
        string lineaCapacidades; // Inicializacion de la variable receptora de la primera linea
        string lineaObjetivos; // Inicializacion de la variable receptora de la segunda linea
        getline(archivo, lineaCapacidades); // Se lee la primera linea del archivo
        getline(archivo, lineaObjetivos); // Se lee la segunda linea del archivo

        // Contar la cantidad de bidones
        int largoCapacidades = 1;
        for (int i = 0; i < lineaCapacidades.length(); i++){
            if (lineaCapacidades[i] == ' '){
                largoCapacidades++;
            }
        }
        int largoObjetivos = 1;
        for (int i = 0; i < lineaObjetivos.length(); i++){
            if (lineaObjetivos[i] == ' '){
                largoObjetivos++;
            }
        }

        // Se comprueba que las capacidades y los objetivos tengan la misma cantidad de bidones
        if (largoCapacidades != largoObjetivos){
            cerr << "Error en el archivo, las especificaciones de los bidones no coinciden." << endl;
            return GrupoBidones(0);
        }
        // Si son iguales, se inicia la lectura
        else{
            // Se inicializa la linea de capacidades para ser separada
            istringstream capacidades (lineaCapacidades);
            // Se inicializa la linea de objetivos para ser separada
            istringstream objetivos (lineaObjetivos);

            int contador = 0;
            istringstream capacidades2 (lineaCapacidades);

            // Se cuenta la cantidad de bidones
            while (capacidades2) {
                string capacidad;
                capacidades2 >> capacidad;
                // Si la capacidad no es un numero, se imprime un mensaje de error
                if (capacidad.find_first_not_of("0123456789") != string::npos){
                    cerr << "Error en el archivo, se espera un numero." << endl;
                    return GrupoBidones(0);
                }
                else{
                    contador++;
                }
            }
            contador--;

            // Se crea un arreglo de punteros a objetos de la clase Bidon
            Bidon** bidones = new Bidon*[contador];

            int arrCapacidades[contador];

            string capacidad; // Se inicializa la variable receptora de la capacidad
            string objetivo; // Se inicializa la variable receptora del objetivo
            capacidades >> capacidad; // Se lee la capacidad
            objetivos >> objetivo; // Se lee el objetivo

            // Se comprueba que la capacidad y el objetivo sean numeros
            if (capacidad.find_first_not_of("0123456789") != string::npos || objetivo.find_first_not_of("0123456789") != string::npos){
                cerr << "Error en el archivo, se espera un numero." << endl;
                return GrupoBidones(0);
            } else{
                int index = 0; // Se inicializa el indice de los bidones
                Bidon** bidones;
                bidones = new Bidon* [contador];
                // Se leen las capacidades y los objetivos
                while (index < contador){
                    // Se convierten las capacidades y objetivos a enteros
                    int capacidadInt = stoi(capacidad);
                    int objetivoInt = stoi(objetivo);

                    // Se crea un puntero a un objeto de la clase Bidon
                    Bidon* bidon = new Bidon(0, capacidadInt, objetivoInt);

                    // Se almacena el puntero en el arreglo de punteros
                    bidones[index] = bidon;
                    arrCapacidades[index] = capacidadInt;

                    index++;

                    // Se lee la siguiente capacidad
                    capacidades >> capacidad;
                    objetivos >> objetivo;
                }

                // Se calcula el MCD de los bidones
                int mcd = 0;
                for (int i = 0; i < contador; i++){
                    if (i == 0){
                        mcd = getMCD(arrCapacidades[0], arrCapacidades[1]);
                    } else {
                        mcd = getMCD(mcd, arrCapacidades[i]);
                    }
                    i++;
                }

                // Se comprueba que las capacidades sean coprimas
                if (mcd != 1){
                    cerr << "Error en el archivo, las capacidades no son coprimas." << endl;
                    // El archivo se cierra una vez leido
                    archivo.close();
                    return GrupoBidones(0);
                }
                // Si no hay errores, se imprime un mensaje de archivo valido y se retorna el estado inicial
                else {
                    cout << "Archivo valido.\n" << endl;
                    GrupoBidones grupoBidones = GrupoBidones(bidones, nullptr, "Estado inicial", contador);
                    // El archivo se cierra una vez leido
                    archivo.close();

                    return grupoBidones;
                }
            }
        }
    }
}