#include <iostream>
using namespace std;

class PolF2 {

private:
    int N;
    double Vec[50];

public:

    PolF2() {
        N = 0;
    }

    void insertar(int exp, double coe) {

        int i = 1;

        while (i <= N * 2) {

            if (Vec[i] == exp) {
                Vec[i + 1] = Vec[i + 1] + coe;
                return;
            }

            i = i + 2;
        }

        N = N + 1;

        Vec[N * 2 - 1] = exp;
        Vec[N * 2] = coe;
    }

    void mostrar() {

        int i = 1;
        bool primero = true;

        while (i <= N * 2) {

            int exp = Vec[i];
            double coe = Vec[i + 1];

            if (coe != 0) {

                if (!primero) {

                    if (coe > 0)
                        cout << " + ";
                    else
                        cout << " - ";

                } else if (coe < 0) {

                    cout << "-";
                }

                if (coe < 0)
                    coe = -coe;

                cout << coe;

                if (exp > 0)
                    cout << "x";

                if (exp > 1)
                    cout << "^" << exp;

                primero = false;
            }

            i = i + 2;
        }

        cout << endl;
    }

    PolF2 multiplicar(const PolF2& b) {

        PolF2 R;

        int i = 1;

        while (i <= N * 2) {

            int j = 1;

            while (j <= b.N * 2) {

                int exp = Vec[i] + b.Vec[j];

                double coe =
                    Vec[i + 1] * b.Vec[j + 1];

                R.insertar(exp, coe);

                j = j + 2;
            }

            i = i + 2;
        }

        return R;
    }
};


int main() {

    // A = 61x^4 - 62x^3 - 76

    PolF2 A;

    A.insertar(4, 61);
    A.insertar(3, -62);
    A.insertar(0, -76);


    // B = 3x^2 + 2x - 5

    PolF2 B;

    B.insertar(2, 3);
    B.insertar(1, 2);
    B.insertar(0, -5);


    cout << "Polinomio A: ";
    A.mostrar();

    cout << "Polinomio B: ";
    B.mostrar();


    PolF2 R = A.multiplicar(B);

    cout << "Resultado de A * B: ";
    R.mostrar();


    return 0;
}