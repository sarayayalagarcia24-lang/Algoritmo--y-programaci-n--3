#include <iostream>
using namespace std;

class PolF2 {
private:
    int Vec[50];

public:

    PolF2() {
        Vec[0] = 0;
    }

    void insertar(int exp, int coe) {

        Vec[0] = Vec[0] + 1;

        Vec[Vec[0] * 2 - 1] = exp;
        Vec[Vec[0] * 2] = coe;
    }

    void mostrar() {

        int i = 1;

        while (i <= Vec[0] * 2) {

            cout << Vec[i + 1];

            if (Vec[i] > 0)
                cout << "x";

            if (Vec[i] > 1)
                cout << "^" << Vec[i];

            if (i < Vec[0] * 2)
                cout << " + ";

            i = i + 2;
        }

        cout << endl;
    }
};

int main() {

    PolF2 A;

    

    A.insertar(4, 61);
    A.insertar(3, -62);
    A.insertar(0, -76);

    cout << "Polinomio original: ";
    A.mostrar();


    A.insertar(2, 5);

    cout << "Despues de insertar 5x^2: ";
    A.mostrar();

    return 0;
}