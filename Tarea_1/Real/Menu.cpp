#include "Menu.h"
#include "Leer.h"

void Menu::mostrarMenu(){
    // Se da la bienvenida al usuario
    cout << "Bienvenido al programa de resolucion de problemas de bidones.\n" << endl;
    string nombreArchivo; // Se inicializa la variable receptora del nombre del archivo
    cout << "Por favor ingrese el nombre del archivo: "; // Se solicita el nombre
    cin >> nombreArchivo; // Aquí se ingresa el nombre
    nombreArchivo = nombreArchivo + ".txt"; // Se concatena la extension del archivo

    Leer leer; // Se crea un objeto de la clase Leer
    if (!leer.leerArchivo(nombreArchivo)){ // Se llama al metodo leerArchivo
        return;
    }
    else {
        // Operacion
    }
    return;
}