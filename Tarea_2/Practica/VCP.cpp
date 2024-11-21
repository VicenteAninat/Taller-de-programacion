#include "Estado.cpp"

class VCP {
public:
    int resolverGreedy(Estado* estado){
        // Hace algo
    }

    void resolverVCP(Estado* estado, int numeroCromaticoPropuesto) {
        // Variables globales
        int cantidadNodos = sizeof(estado->grafo->nodos) / sizeof(estado->grafo->nodos[0]);
        Estado* mejorEstado = new Estado();

        /*
        Algoritmo de backtracking para resolver el problema de coloreo de vértices
        Caso base:
        - Si todos los vértices están coloreados, se procede a revisar su numero cromatico (coloresUsados)
        - Si el numero cromatico es menor al numero cromatico propuesto, se actualiza el numero cromatico propuesto 
          y el estado actual se guarda como el mejor estado
        
        Caso recursivo:
        - Se selecciona un nodo no coloreado segun el id arbol de nodos
        - Se incrementa el numero de colores disponibles
        - Para cada color disponible, se verifica si es factible colorear el nodo con ese color
        - Si es factible, se crea un nuevo estado con el nodo coloreado y se llama recursivamente a la funcion
        - Si no es factible, se prueba con otro color

        Al finalizar el algoritmo, se retorna el numero cromatico propuesto y se imprime el mejor estado encontrado
        */

       // Caso base
        if(cantidadNodos == estado->grafo->grafoColoreado.size()) {
            if(estado->grafo->coloresUsados < numeroCromaticoPropuesto) {
                numeroCromaticoPropuesto = estado->grafo->coloresUsados;
                mejorEstado = estado;
            }
        } else {
            // Caso recursivo
            for (int i = 0; i < cantidadNodos; i++){
                int IDNodo = estado->grafo->grafoNoColoreado[i];
                estado->grafo->coloresAsignados++;
                Nodo* nodoActual = estado->grafo->nodos[IDNodo];
                for (int j = 1; j <= estado->grafo->coloresAsignados; j++){
                    bool factible = true;
                    for (int k = )
                }
            }
            
        }
    }
};