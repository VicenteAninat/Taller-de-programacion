#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "GrupoBidones.h"

using namespace std;

class Leer {
    public:

    // Metodo auxiliar para obtener el MCD de dos numeros
    int getMCD(int a, int b);
    
    // Metodo para leer un archivo y retornar un puntero a GrupoBidones
    GrupoBidones leerArchivo(string nombreArchivo);
};