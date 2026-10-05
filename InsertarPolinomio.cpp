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
};

int main() {

    PolF1 X(5);

    X.insertar(5, 3);
    X.insertar(3, 5);
    X.insertar(1, -4);
    X.insertar(0, -50);

    cout << "Polinomio antes de insertar: ";
    X.mostrar();

    X.insertar(4, 7);

    cout << "Polinomio despues de insertar 7x^4: ";
    X.mostrar();

    return 0;
}