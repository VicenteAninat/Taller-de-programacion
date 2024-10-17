#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Bidon.h"
#include "GrupoBidones.h"

using namespace std;

class Leer {
    public:
    GrupoBidones* leerArchivo(string nombreArchivo);
};