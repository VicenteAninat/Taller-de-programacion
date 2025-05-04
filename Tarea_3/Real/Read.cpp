#include "Read.h"

Read::Read() {
}

int Read::contarVertices(string nombreArchivo, int cantidadVertices) {
    // Definición de las variables a utilizar
    nombreArchivo = "Graphs/" + nombreArchivo + ".txt";
    ifstream archivo(nombreArchivo);
    set<int> listaVertices;

    // Se comprueba la existencia del archivo
    if(!archivo) {
        cerr << "Archivo no encontrado." << endl;
        return 0;
    }
    // Si el archivo existe, se lee su contenido
    else {
        getline(archivo, nombreArchivo);
        getline(archivo, nombreArchivo);
        // Se inicializan las variables para el conteo de Vertices
        int cantidadVertices = 0;

        // Se leen las aristas
        int n, m, c;
        while (!archivo.eof()) {
            // Se extraen los datos de las aristas
            archivo >> n >> m >> c;

            listaVertices.insert(n);
            listaVertices.insert(m);

            /*
            if (listaVertices.empty()) {
                listaVertices.push_back(n);
                listaVertices.push_back(m);
                cantidadVertices += 2;
            }

            // Se verifica si los vertices ya se encuentran en la lista de vertices
            for (int vertice : listaVertices) {
                if (find(listaVertices.begin(), listaVertices.end(), n) != listaVertices.end()) {
                    // No hace nada
                }
                else {
                    listaVertices.push_back(n);
                    cantidadVertices++;
                }

            }

            for (int vertice : listaVertices) {
                if (find(listaVertices.begin(), listaVertices.end(), m) != listaVertices.end()) {
                    // No hace nada
                }
                else {
                    listaVertices.push_back(m);
                    cantidadVertices++;
                }
            }
            */
        }
        
        cantidadVertices = listaVertices.size();

        cantidadVertices += 2;

        return cantidadVertices;
    }
}

Dinic* Read::readDinic(string nombreArchivo, int cantidad) {
    // Definición de las variables a utilizar
    nombreArchivo = "Graphs/" + nombreArchivo + ".txt";
    Dinic* dinic = new Dinic(cantidad);
    ifstream archivo(nombreArchivo);
    vector<int> listaFuentes;
    vector<int> listaSumideros;

    cout << "Flag 1" << endl;

    // Se comprueba la existencia del archivo
    if(!archivo) {
        cerr << "Archivo no encontrado." << endl;
        return nullptr;
    }
    // Si el archivo existe, se lee su contenido
    else {

        cout << "Flag 2" << endl;

        // Se extraen las lineas de fuentes y sumideros
        string lineaFuentes;
        string lineaSumideros;
        getline(archivo, lineaFuentes);
        getline(archivo, lineaSumideros);

        // Contar la cantidad de fuentes
        int largoFuentes = 1;
        for (int i = 0; i < lineaFuentes.length(); i++){
            if (lineaFuentes[i] == ' '){
                largoFuentes++;
            }
        }

        cout << "Flag 3" << endl;

        // Contar la cantidad de sumideros
        int largoSumideros = 1;
        for (int i = 0; i < lineaSumideros.length(); i++){
            if (lineaSumideros[i] == ' '){
                largoSumideros++;
            }
        }

        cout << "Flag 4" << endl;

        // Se extraen los id de las fuentes y sumideros
        istringstream fuentes (lineaFuentes);
        istringstream sumideros (lineaSumideros);
        string fuente;
        string sumidero;
        fuentes >> fuente;
        sumideros >> sumidero;

        // Indice para recorrer las fuentes y sumideros
        int index = 0;

        // Se consiguen las fuentes
        while (index < largoFuentes){
            int id = stoi(fuente);
            listaFuentes.push_back(id);
            index++;
            fuentes >> fuente;
        }

        cout << "Flag 5" << endl;

        // Reinicio del indice
        index = 0;

        // Se consiguen los sumideros
        while (index < largoSumideros){
            int id = stoi(sumidero);
            listaSumideros.push_back(id);
            index++;
            sumideros >> sumidero;
        }

        cout << "Flag 6" << endl;

        // Se inicializan las variables para el conteo de Vertices
        int cantidadVertices = 0;
        vector<int> listaVertices;

        // Se leen las aristas
        int n, m, c;
        while (!archivo.eof()) {
            // Se extraen los datos de las aristas
            archivo >> n >> m >> c;
            dinic->addEdge(n, m, c);

            // Se verifica si los vertices ya se encuentran en la lista de vertices
            for (int vertice : listaVertices) {
                if (find(listaFuentes.begin(), listaFuentes.end(), n) != listaFuentes.end()) {
                    // No hace nada
                }
                else {
                    listaVertices.push_back(n);
                    cantidadVertices++;
                }
            }

            for (int vertice : listaVertices) {
                if (find(listaSumideros.begin(), listaSumideros.end(), m) != listaSumideros.end()) {
                    // No hace nada
                }
                else {
                    listaVertices.push_back(m);
                    cantidadVertices++;
                }
            }
        }

        int cv = cantidad - 2;

        for (int id : listaFuentes) {
            dinic->addEdge(cv, id, dinic->INF);
        }

        dinic->s = cv;

        cv++;

        for (int id : listaSumideros) {
            dinic->addEdge(id, cv, dinic->INF);
        }

        dinic->t = cv;

        /*

        // Se inicializan las variables para la inserción de los super fuentes y sumideros
        int nuevaCantidad = cantidadVertices;
        nuevaCantidad++;

        // Se agregan los super fuentes y super sumideros
        for (int id : listaFuentes) {
            dinic->addEdge(nuevaCantidad, id, dinic->INF);

        }

        // Se verifica si la cantidad de vertices no ha cambiado
        if (nuevaCantidad == cantidadVertices) {
            nuevaCantidad++;
            cantidadVertices = nuevaCantidad;
        }

        dinic->s = nuevaCantidad;

        for (int id : listaSumideros) {
            dinic->addEdge(id, nuevaCantidad, dinic->INF);
        }

        if (nuevaCantidad == cantidadVertices) {
            nuevaCantidad++;
        }

        dinic->t = nuevaCantidad;

        dinic->n = nuevaCantidad++;

        dinic->printGraph();

        */

        dinic->maxFlow = 0;

        cout << "maxFlow: " << dinic->maxFlow << endl;
            
        return dinic;
    }
}
