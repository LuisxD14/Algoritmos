#include "funciones.h"

//Funcion para convertir en minuscula
string aMinusculas(const string& s) {
    string r = s;
    for (int i = 0; i < (int)r.size(); i++)
        if (r[i] >= 'A' && r[i] <= 'Z') r[i] += 32;
    return r;
}
// Funcion para imprimir
void imprimir(const string& texto, int ancho) {
    cout << texto;
    for (int i = (int)texto.size(); i < ancho; i++) cout << ' ';
}
// Funcion para convertir de int a String
string intAStr(int n) {
    if (n == 0) return "0";
    string s = "";
    bool neg = (n < 0);
    if (neg) n = -n;
    while (n > 0) { s = char('0' + n % 10) + s; n /= 10; }
    return neg ? "-" + s : s;
}
// Funcion para convertir de double a String
string doubleAStr(double val) {
    if (val < 0) return "-" + doubleAStr(-val);
    int entero = (int)val;
    int dec    = (int)((val - entero) * 100 + 0.5);
    string s   = intAStr(entero) + ".";
    if (dec < 10) s += "0";
    s += intAStr(dec);
    return s;
}
