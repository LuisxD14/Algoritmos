#ifndef funciones
#define funciones

//Librerias
#include <ios>
#include <iostream>
#include <fstream> // Manejo de archivo (Cerrar, abrir)
#include <vector> // Vector para almacenar productos
#include <string> // Leer archivo,
#include <iomanip> // Dar formato al imprimir
#include <sstream>
using namespace std;

// Struct del producto
struct Producto {
    int    id;
    string nombre;
    double precio;
    int    cantidad;
    string unidad;
};

// Constantes
const string ARCHIVO = "inventario.csv";
const string SEPARADOR = ",";

// Funciones manejoArchivo.cpp
void guardarArchivo(const vector<Producto>& inv);
vector<Producto> cargarArchivo();

// Funciones crearBuscarId.cpp
int buscarPorID(const vector<Producto>& inv, int id);
int nuevoID(const vector<Producto>& inv);
void buscarPorNombre(const vector<Producto>& inv);

// Funciones operacionesArchivo.cpp
void alta(vector<Producto>& inv);
void baja(vector<Producto>& inv);
void cambio(vector<Producto>& inv);

// Funcion reporte.cpp
void reporte(const vector<Producto>& inv);

// Funciones entradaSalidaP
void entrada(vector<Producto>& inv);
void salida(vector<Producto>& inv);

// Funciones Auxiliares.cpp
string aMinusculas(const string& s);
void imprimir(const string& texto, int ancho);
string intAStr(int n);
string doubleAStr(double val);
#endif
