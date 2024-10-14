#include "Menu.h"
#include "Leer.h"
#include "JugProb.h"

void Menu::mostrarMenu(){
    // Se da la bienvenida al usuario
    cout << "Bienvenido al programa de resolucion de problemas de bidones.\n" << endl;
    string nombreArchivo; // Se inicializa la variable receptora del nombre del archivo
    cout << "Por favor ingrese el nombre del archivo: "; // Se solicita el nombre
    cin >> nombreArchivo; // Aquí se ingresa el nombre
    nombreArchivo = nombreArchivo + ".txt"; // Se concatena la extension del archivo

    Leer leer; // Se crea un objeto de la clase Leer
    GrupoBidones* caso = leer.leerArchivo(nombreArchivo);
    if (caso == nullptr){ // Se llama al metodo leerArchivo
        printf("No se pudo leer el archivo");
        return;
    } 
    else {
        JugProb problema;
        problema.resolver(caso);
        return;
    }
}