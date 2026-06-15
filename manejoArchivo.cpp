#include "funciones.h"

void guardarArchivo(const vector<Producto>& inv) {
    ofstream f(ARCHIVO);
    if (!f.is_open()) {
        cerr << "No se pudo abrir el archivo para guardar.\n";
        return;
    }
    f << "id,nombre,precio,cantidad,unidad\n";   // encabezado
    for (const auto& p : inv) {
        f << p.id << SEPARADOR
          << p.nombre << SEPARADOR
          << fixed << setprecision(2) << p.precio << SEPARADOR
          << p.cantidad << SEPARADOR
          << p.unidad << "\n";
    }
    f.close();
    cout << "Inventario guardado en '" << ARCHIVO << "'.\n";
}

vector<Producto> cargarArchivo() {
    vector<Producto> inv;
    ifstream f(ARCHIVO);

    if (!f.is_open()) {
        cout << "Archivo no encontrado. Se creará uno nuevo.\n";
        return inv;
    }

    string linea;
    getline(f, linea);

    while (getline(f, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        Producto p;
        string campo;

        getline(ss, campo, ','); p.id       = stoi(campo);
        getline(ss, campo, ','); p.nombre   = campo;
        getline(ss, campo, ','); p.precio   = stod(campo);
        getline(ss, campo, ','); p.cantidad = stoi(campo);
        getline(ss, campo, ','); p.unidad   = campo;

        inv.push_back(p);
    }
    f.close();
    return inv;
}
