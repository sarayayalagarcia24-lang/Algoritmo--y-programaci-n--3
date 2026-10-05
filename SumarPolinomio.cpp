#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class PolF1 {
private:
    int grado;
    vector<double> coefs;

public:
    PolF1(int n) {
        grado = n;
        coefs.resize(n + 1, 0.0);
    }

    double obtenerDato(int i) const {
        if (i >= 1 && i <= grado + 1)
            return coefs[grado + 1 - i];
        return 0;
    }

    void asignarDato(int i, double valor) {
        if (i >= 1 && i <= grado + 1)
            coefs[grado + 1 - i] = valor;
    }

    void insertar(int exp, double coe) {
        if (exp > grado) {
            grado = exp;
            coefs.resize(exp + 1, 0.0);
        }
        coefs[exp] = coe;
    }

    void mostrar() const {
        bool primero = true;
        for (int e = grado; e >= 0; e--) {
            double c = coefs[e];
            if (c == 0) continue;
            if (!primero) cout << (c > 0 ? " + " : " - ");
            else if (c < 0) cout << "-";
            cout << fabs(c);
            if (e > 0) cout << "x";
            if (e > 1) cout << "^" << e;
            primero = false;
        }
        if (primero) cout << "0";
        cout << endl;
    }

    PolF1 suma(const PolF1& Y) const {
        int may = max(grado, Y.grado); 
        PolF1 R(may);

        int i = 1; 
        int j = 1; 

        while (i <= grado + 1 || j <= Y.grado + 1) {
            int expX = -1, expY = -1;

            if (i <= grado + 1) expX = grado - (i - 1);
            if (j <= Y.grado + 1) expY = Y.grado - (j - 1);

            if (expX > expY) {
                R.coefs[expX] = obtenerDato(i);
                i++;
            }
            else if (expY > expX) {
                R.coefs[expY] = Y.obtenerDato(j);
                j++;
            }
            else {
                if (expX >= 0)
                    R.coefs[expX] = obtenerDato(i) + Y.obtenerDato(j);
                i++; j++;
            }
        }
        return R;
    }
};

int main() {
    PolF1 Y(4);
    Y.insertar(4, 3);
    Y.insertar(3, 2);
    Y.insertar(2, -5);
    Y.insertar(0, 4);

    PolF1 Z(2);
    Z.insertar(2, 1);
    Z.insertar(0, -4);

    cout << "Polinomio Y: "; Y.mostrar();
    cout << "Polinomio Z: "; Z.mostrar();

    PolF1 res = Y.suma(Z);
    cout << "\nY + Z = "; res.mostrar();

    return 0;
}