// Se incluyen todas las librerias necesarias
#include <iostream>
#include <string>

using namespace std;

// Se define el estado para el problema de los bidones
class Bidon {
    public:
    // Se definen los atributos del estado
    int aguaActual; // Agua actual en el bidon
    int aguaMaxima; // Capacidad maxima del bidon
    int aguaObjetivo; // Capacidad a la que se quiere llegar

    Bidon(); // Constructor por defecto
    Bidon(int aguaActual, int aguaMaxima, int aguaObjetivo); // Constructor del estado

    string print(); // Imprime el estado y toda la secuencia de operaciones que lo generaron
};