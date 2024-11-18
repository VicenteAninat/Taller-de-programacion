class Nodo {
public:
    int id;
    int color;
    Nodo** vecinos;
    Nodo** vecinosColoreados;

    Nodo() {
        this->id = -1;
        this->color = -1; // -1 significa que no tiene color asignado
        this->vecinos = nullptr;
        this->vecinosColoreados = nullptr;
    }
};