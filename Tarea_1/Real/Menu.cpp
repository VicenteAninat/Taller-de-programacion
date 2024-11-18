#include "Menu.h"

void Menu::mostrarMenu(){
    // Se da la bienvenida al usuario
    cout << "Bienvenido al programa de resolucion de problemas de bidones.\n" << endl;
    string nombreArchivo; // Se inicializa la variable receptora del nombre del archivo
    cout << "Por favor ingrese el nombre del archivo: "; // Se solicita el nombre
    cin >> nombreArchivo; // Aquí se ingresa el nombre
    nombreArchivo = nombreArchivo + ".txt"; // Se concatena la extension del archivo

    Leer leer; // Se crea un objeto de la clase Leer
    GrupoBidones caso = leer.leerArchivo(nombreArchivo);
    if (caso.cantidad == 0){ // Se llama al metodo leerArchivo
        printf("No se pudo leer el archivo");
        return;
    } 
    else {
        auto start = chrono::high_resolution_clock::now(); // Se inicia el cronometro
        JugProb().resolver(caso); // Se llama al metodo resolver
        auto end = chrono::high_resolution_clock::now(); // Se finaliza el cronometro
        chrono::duration<double> tiempo = end - start; // Se calcula el tiempo de ejecucion
        cout << "El tiempo de ejecucion fue de: " << tiempo.count() << " segundos" << endl;
        return;
    }
}

void Menu::mostrarMenuTest(){
    // Se da la bienvenida al usuario
    cout << "Bienvenido al programa de resolucion de problemas de bidones.\n" << endl;
    string nombreArchivo; // Se inicializa la variable receptora del nombre del archivo
    cout << "Por favor ingrese el nombre del archivo: "; // Se solicita el nombre
    cin >> nombreArchivo; // Aquí se ingresa el nombre
    nombreArchivo = nombreArchivo + ".txt"; // Se concatena la extension del archivo

    cout << "Su archivo sera leido" << endl;
    return;
}