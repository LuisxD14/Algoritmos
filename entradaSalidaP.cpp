#include "funciones.h"

// ENTRADA – suma unidades a un producto existente (llegó mercancía)
void entrada(vector<Producto>& inv) {
    cout << "\n--- ENTRADA DE MERCANCIA ---\n";
    cout << "  ID del producto: ";
    int id; cin >> id;

    int idx = buscarPorID(inv, id);
    if (idx == -1) {
        cout << "  Producto no encontrado.\n";
        return;
    }

    cout << "  Producto  : " << inv[idx].nombre << "\n";
    cout << "  Existencia: " << inv[idx].cantidad << " " << inv[idx].unidad << "\n";
    cout << "  Cantidad a agregar: ";
    int cant; cin >> cant;

    if (cant <= 0) {
        cout << "  La cantidad debe ser mayor a 0.\n";
        return;
    }

    inv[idx].cantidad += cant;
    guardarArchivo(inv);
    //cout << "  Nueva existencia: " << inv[idx].cantidad << " " << inv[idx].unidad << "\n";
}

// SALIDA – resta unidades a un producto existente (se usó o vendió)
void salida(vector<Producto>& inv) {
    cout << "\n--- SALIDA DE MERCANCIA ----\n";
    cout << "  ID del producto: ";
    int id; cin >> id;

    int idx = buscarPorID(inv, id);
    if (idx == -1) {
        cout << "  Producto no encontrado.\n";
        return;
    }

    cout << "  Producto  : " << inv[idx].nombre << "\n";
    cout << "  Existencia: " << inv[idx].cantidad << " " << inv[idx].unidad << "\n";
    cout << "  Cantidad a retirar: ";
    int cant; cin >> cant;

    if (cant <= 0) {
        cout << "   La cantidad debe ser mayor a 0\n";
        return;
    }
    if (cant > inv[idx].cantidad) {
        cout << "   No hay suficiente existencia (tienes "
             << inv[idx].cantidad << ").\n";
        return;
    }

    inv[idx].cantidad -= cant;
    guardarArchivo(inv);
    //cout << "  Nueva existencia: " << inv[idx].cantidad << " " << inv[idx].unidad << "\n";
    if (inv[idx].cantidad == 0)
        cout << "El producto quedo en 0\n";
}
