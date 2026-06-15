#include "funciones.h"

void alta(vector<Producto>& inv) {
    Producto p;
    p.id = nuevoID(inv);

    cout << "\n── ALTA DE PRODUCTO ───\n" << endl;
    cout << "  ID asignado: " << p.id << "\n";
    cin.ignore();
    cout << "  Nombre    : "; getline(cin, p.nombre);
    cout << "  Precio    : "; cin >> p.precio;
    cout << "  Cantidad  : "; cin >> p.cantidad;
    cin.ignore();
    cout << "  Unidad    : "; getline(cin, p.unidad); // kilogramos(kg), piezas, litros(L), gramos(g)

    inv.push_back(p);
    guardarArchivo(inv);
    cout << "  Producto '" << p.nombre << "' agregado correctamente.\n";
}


void baja(vector<Producto>& inv) {
    cout << "\n── BAJA DE PRODUCTO ───\n" << endl;
    cout << "  ID a eliminar: ";
    int id; cin >> id;

    int idx = buscarPorID(inv, id);
    if (idx == -1) {
        cout << "Producto con ID " << id << " no encontrado.\n";
        return;
    }

    cout << "  Eliminando '" << inv[idx].nombre << "'... ";
    inv.erase(inv.begin() + idx);
    guardarArchivo(inv);
    cout << "eliminado.\n";
}

// CAMBIO – modifica campos de un producto existente
void cambio(vector<Producto>& inv) {
    cout << "\n── CAMBIO DE PRODUCTO ──"<< endl;
    cout << "  ID a modificar: ";
    int id; cin >> id;

    int idx = buscarPorID(inv, id);
    if (idx == -1) {
        cout << "  [!] Producto con ID " << id << " no encontrado.\n";
        return;
    }

    Producto& p = inv[idx];
    cout << "  Producto: " << p.nombre << "\n";

    cin.ignore();
    string tmp;
    cout << "  Nuevo nombre (actual: " << p.nombre << "): ";
    getline(cin, tmp);
    if (!tmp.empty()) p.nombre = tmp;

    cout << "  Nuevo nombre (actual: " << p.precio << "): ";
    getline(cin, tmp);
    if (!tmp.empty()) p.precio = stod(tmp);

    cout << "  Nuevo nombre (actual: " << p.cantidad << "): ";
    getline(cin, tmp);
    if (!tmp.empty()) p.cantidad = stoi(tmp);

    cout << "  Nuevo nombre (actual: " << p.unidad << "):";
    getline(cin, tmp);
    if (!tmp.empty()) p.unidad = tmp;

    guardarArchivo(inv);
    cout << "  Inventario Actualizado";
}
