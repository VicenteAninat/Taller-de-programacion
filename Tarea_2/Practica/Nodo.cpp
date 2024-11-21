#include <vector>
#include <set>

using namespace std;

class Nodo {
public:
    int id;
    int color;
    Nodo** vecinos;
    set<int> vecinosColoreados;

    Nodo() {
        this->id = -1; // -1 significa que no tiene id asignado
        this->color = 0; // 0 significa que no tiene color asignado, esta en blanco
        this->vecinos = nullptr; // no tiene vecinos
        this->vecinosColoreados = set<int>(); // inicializamos el conjunto de vecinos coloreados
    }

    void agregarVecinosColoreados(){
        for (int i = 0; i < sizeof(vecinos); i++){
            if (vecinos[i]->color != 0){
                vecinosColoreados.insert(vecinos[i]->id);
            }
        }
        return;
    }
};