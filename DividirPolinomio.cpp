#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PolF1 {
private:
    int grado;
    vector<double> coefs;

public:

    PolF1(int n) {
        grado = n;
        coefs.assign(n + 1, 0.0);
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
        int e = grado;

        while (e >= 0) {
            double c = coefs[e];

            if (c != 0) {
                if (!primero)
                    cout << (c > 0 ? " + " : " - ");
                else if (c < 0)
                    cout << "-";

                cout << fabs(c);

                if (e > 0)
                    cout << "x";

                if (e > 1)
                    cout << "^" << e;

                primero = false;
            }

            e = e - 1;
        }

        if (primero)
            cout << "0";

        cout << endl;
    }

    PolF1 dividir(const PolF1& Y) const {

        int gradoR = grado - Y.grado;

        if (gradoR < 0)
            gradoR = 0;

        PolF1 R(gradoR);

        PolF1 residuo = *this;

        while (residuo.grado >= Y.grado &&
               residuo.coefs[residuo.grado] != 0) {

            int exp = residuo.grado - Y.grado;

            double coe =
                residuo.coefs[residuo.grado] /
                Y.coefs[Y.grado];

            R.coefs[exp] = coe;

            int i = 0;

            while (i <= Y.grado) {

                int pos = i + exp;

                residuo.coefs[pos] =
                    residuo.coefs[pos] -
                    coe * Y.coefs[i];

                i = i + 1;
            }

            while (residuo.grado > 0 &&
                   residuo.coefs[residuo.grado] == 0) {

                residuo.grado =
                    residuo.grado - 1;
            }
        }

        return R;
    }
};

int main() {

    PolF1 Y(4);

    Y.insertar(5, 3);
    Y.insertar(3, 5);
    Y.insertar(1, -4);
    Y.insertar(0, -50);

    PolF1 Z(2);

    Z.insertar(2, 1);
    Z.insertar(0, -4);

    cout << "Polinomio Y: ";
    Y.mostrar();

    cout << "Polinomio Z: ";
    Z.mostrar();

    PolF1 resultado = Y.dividir(Z);

    cout << "\nY / Z = ";
    resultado.mostrar();

    return 0;
}