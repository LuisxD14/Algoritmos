#include "funciones.h"

int main() {
    vector<Producto> inventario = cargarArchivo();

    int opcion;
    do {
        cout << endl <<"--- PANADERÍA - INVENTARIO ---\n";
        cout << "-------------------------------\n";
        cout << "  1. Alta            \n";
        cout << "  2. Baja           \n";
        cout << "  3. Cambio        \n";
        cout << "  4. Reporte                  \n";
        cout << "  0. Salir                    \n";
        cout <<endl << "  Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: alta(inventario);      break;
            case 2: baja(inventario);      break;
            case 3: cambio(inventario);    break;
            case 4: reporte(inventario);   break;
            case 0: cout << "Finalizado"; break;
            default: cout << "Opción inválida\n";
        }

    } while (opcion != 0);
    return 0;
}
