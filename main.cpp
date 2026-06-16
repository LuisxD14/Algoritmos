#include "funciones.h"

int main() {
    vector<Producto> inventario = cargarArchivo();

    int opcion;
    do {
        cout << endl <<"--- PANADERÍA - INVENTARIO ---\n";
        cout << "-------------------------------\n";
        cout << "  1. Alta            \n";
        cout << "  2. Baja           \n";
        cout << "  3. Cambio (Modificar)        \n";
        cout << "  4. Reporte                  \n";
        cout << "  5. Entrada de Producto                  \n";
        cout << "  6. Salida de producto (Venta)                  \n";
        cout << "  7. Buscar por nombre                  \n";
        cout << "  0. Salir                    \n";
        cout <<endl << "  Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: alta(inventario);      break;
            case 2: baja(inventario);      break;
            case 3: cambio(inventario);    break;
            case 4: reporte(inventario);   break;
            case 5: entrada(inventario); break;
            case 6: salida(inventario); break;
            case 7: buscarPorNombre(inventario); break;
            case 0: cout << "Finalizado"; break;
            default: cout << "Opción inválida\n";
        }

    } while (opcion != 0);
    return 0;
}
