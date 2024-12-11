#include <fstream>
#include "State.h"

class Read {
    public:
    // Sin atributos

    // Metodos

    Read(); // Constructor

    // Descripción: Lee un archivo de texto que contiene un grafo y 
    // crea un estado inicial con el grafo leído
    // Entrada: Nombre del archivo (string fileName)
    // Salida: Puntero a un objeto State que contiene el grafo leído, 
    // o nullptr si no se pudo abrir el archivo
    State* readFile(string fileName);
};