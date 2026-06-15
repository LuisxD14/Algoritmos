#include "funciones.h"

int buscarPorID(const vector<Producto>& inv, int id) {
    int izquierda = 0;
    int derecha = inv.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (inv[medio].id == id)
            return medio;
        else if (inv[medio].id < id)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}

int nuevoID(const vector<Producto>& inv) {
    int maxID = 0;
    for (const auto& p : inv)
        if (p.id > maxID) maxID = p.id;
    return maxID + 1;
}
