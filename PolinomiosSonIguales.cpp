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
        coefs[exp] = coefs[exp] + coe;
    }

    void mostrar() const {
        bool primero = true;
        int i = grado;

        while (i >= 0) {

            if (coefs[i] != 0) {

                if (!primero)
                    cout << (coefs[i] > 0 ? " + " : " - ");
                else if (coefs[i] < 0)
                    cout << "-";

                cout << fabs(coefs[i]);

                if (i > 0)
                    cout << "x";

                if (i > 1)
                    cout << "^" << i;

                primero = false;
            }

            i = i - 1;
        }

        if (primero)
            cout << "0";

        cout << endl;
    }

    bool sonIguales(const PolF1& Y) const {

        if (grado != Y.grado)
            return false;

        int i = 0;

        while (i <= grado) {

            if (coefs[i] != Y.coefs[i])
                return false;

            i = i + 1;
        }

        return true;
    }
};

int main() {

    PolF1 X(5);

    X.insertar(5, 3);
    X.insertar(3, 5);
    X.insertar(1, -4);
    X.insertar(0, -50);

    PolF1 Y(4);

    Y.insertar(4, 3);
    Y.insertar(3, 2);
    Y.insertar(2, -5);
    Y.insertar(0, 4);

    cout << "Polinomio X: ";
    X.mostrar();

    cout << "Polinomio Y: ";
    Y.mostrar();

    if (X.sonIguales(Y))
        cout << "Los polinomios son iguales." << endl;
    else
        cout << "Los polinomios son diferentes." << endl;

    return 0;
}