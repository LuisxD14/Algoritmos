#include "funciones.h"

void reporte(const vector<Producto>& inv) {
    cout << "\n── REPORTE DE INVENTARIO ---" << endl;
    if (inv.empty()) {
        cout << "  El inventario está vacío.\n";
        return;
    }

    cout << left
         << setw(6)  << "ID"
         << setw(22) << "Nombre"
         << setw(10) << "Precio"
         << setw(10) << "Cantidad"
         << setw(10) << "Unidad"
         << "\n";
    cout << string(60, '-') << "\n";

    double total = 0;
    for (const auto& p : inv) {
        cout << left
        << setw(6)  << p.id
        << setw(22) << p.nombre
        << "$" << setw(9) << fixed << setprecision(2) << p.precio
        << setw(10) << p.cantidad
        << setw(10) << p.unidad
        << "\n";
        total += p.precio * p.cantidad;
    }

    cout << string(60, '-') << "\n";
    cout << "  Total de productos : " << inv.size() << "\n";
    cout << "  Valor del inventario: $" << fixed << setprecision(2) << total << "\n";
}
