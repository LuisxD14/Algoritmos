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
// BUSCAR POR NOMBRE – el usuario escribe un nombre y ve el producto
void buscarPorNombre(const vector<Producto>& inv) {
    cout << "\n--- BUSCAR POR NOMBRE ---\n";
    cin.ignore();
    cout << "  Nombre (o parte): ";
    string busqueda;
    getline(cin, busqueda);
    string b = aMinusculas(busqueda);

    bool encontrado = false;
    for (int i = 0; i < (int)inv.size(); i++) {
        if (aMinusculas(inv[i].nombre).find(b) != string::npos) {
            if (!encontrado) {
                imprimir("ID", 6); imprimir("Nombre", 22);
                imprimir("Precio", 10); imprimir("Cant.", 8);
                cout << "Unidad\n";
                for (int k = 0; k < 54; k++) cout << '-';
                cout << "\n";
                encontrado = true;
            }
            imprimir(intAStr(inv[i].id),               6);
            imprimir(inv[i].nombre,                   22);
            imprimir("$" + doubleAStr(inv[i].precio), 10);
            imprimir(intAStr(inv[i].cantidad),         8);
            cout << inv[i].unidad << "\n";
        }
    }

    if (!encontrado)
        cout << "  No se encontro ningun producto con ese nombre.\n";
}
