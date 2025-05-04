#include "QuickHull.h"

int QuickHull::encontrarLado(Punto p1, Punto p2, Punto p) {
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);

    if (val > 0) {
        return 1;
    }

    if (val < 0) {
        return -1;
    }

    return 0;
}

int QuickHull::encontrarDistancia(Punto p1, Punto p2, Punto p) {
    return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

bool QuickHull::comprobarPlano(Plano* plano) {
    if (plano->puntos.size() < 3) {
        return false;
    }
    else {
        return true;
    }
}

void QuickHull::resolver(Plano* plano, int cantidadPuntos, Punto minX, Punto maxX, int lado) {
    if (!comprobarPlano(plano)){
        cout << "El plano no tiene suficientes puntos para ser operado" << endl;
    }
    else {
        int largo = plano->puntos.size();
        Punto minX = Punto(0, 0);
        Punto maxX = Punto(0, 0);
        for (auto punto : plano->puntos) {
            if (punto.x < minX.x) {
                minX = punto;
            }
            if (punto.x > maxX.x) {
                maxX = punto;
            }
        }

        resolver();
    }
}

void QuickHull::mostrarEnvoltura(Plano* plano) {
    if (!comprobarPlano(plano)) {
        cout << "El plano no tiene suficientes puntos para ser operado" << endl;
    }
    else {
        int largo = plano->puntos.size();
        Punto minX = Punto(0, 0);
        Punto maxX = Punto(0, 0);
        for (auto punto : plano->puntos) {
            if (punto.x < minX.x) {
                minX = punto;
            }
            if (punto.x > maxX.x) {
                maxX = punto;
            }
        }

        resolver(plano, largo, minX, maxX, 1);
        resolver(plano, largo, minX, maxX, -1);

        cout << "Los puntos de la envoltura son: " << endl;
        while (!plano->envoltura.empty()) {
            cout << "(" << plano->envoltura.begin()->x << ", " << plano->envoltura.begin()->y << ")" << endl;
            plano->envoltura.erase(plano->envoltura.begin());
        }
    }
}
