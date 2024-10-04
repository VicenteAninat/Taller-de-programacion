#include <iostream>
#include <fstream> //Libreria necesaria para leer archivos
#include <string> //Libreria necesaria para el manejo de strings

using namespace std;

int main() {
    // Se da la bienvenida al usuario
    cout << "Bienvenido al programa de resolucion de problemas de bidones.\n" << endl;
    string nombreArchivo; // Se inicializa la variable receptora del nombre del archivo
    cout << "Por favor ingrese el nombre del archivo: "; // Se solicita el nombre
    cin >> nombreArchivo; // Aquí se ingresa el nombre
    nombreArchivo = nombreArchivo + ".txt"; // Se concatena la extension del archivo

    // Abiendo el archivo
    ifstream archivo(nombreArchivo);
    // Se comprueba la existencia del archivo
    if (!archivo) {
        cerr << "Archivo no encontrado. Terminando ejecucion..." << endl;
        return 1;
    }

    // Se lee el contenido del archivo
    string linea; // Inicializacion de la variable receptora de las lineas del archivo
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    // El archivo se cierra una vez leido
    archivo.close();


    return 0;
}