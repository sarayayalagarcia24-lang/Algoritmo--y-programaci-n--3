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

        int i = 1;

        while (i <= Vec[0] * 2) {

            if (Vec[i] == exp) {

                Vec[i + 1] =
                    Vec[i + 1] + coe;

                return;
            }

            i = i + 2;
        }

        Vec[0] = Vec[0] + 1;

        Vec[Vec[0] * 2 - 1] = exp;
        Vec[Vec[0] * 2] = coe;
    }


    // PolF2::sonIguales(PolF2 b)

    bool sonIguales(const PolF2& b) {

        // Primero compara cantidad de términos

        if (Vec[0] != b.Vec[0])
            return false;


        // Compara exponentes y coeficientes

        int i = 1;

        while (i <= Vec[0] * 2) {

            int exp = Vec[i];

            int coe = Vec[i + 1];

            bool encontrado = false;

            int j = 1;

            while (j <= b.Vec[0] * 2) {

                if (b.Vec[j] == exp &&
                    b.Vec[j + 1] == coe) {

                    encontrado = true;
                }

                j = j + 2;
            }

            if (!encontrado)
                return false;

            i = i + 2;
        }

        return true;
    }
};


int main() {

    PolF2 A;
    PolF2 B;

    // A = 61x^4 - 62x^3 - 76

    A.insertar(4, 61);
    A.insertar(3, -62);
    A.insertar(0, -76);


    // B = 3x^2 + 2x - 5

    B.insertar(2, 3);
    B.insertar(1, 2);
    B.insertar(0, -5);


    if (A.sonIguales(B)) {

        cout << "Los polinomios son iguales.";

    }
    else {

        cout << "Los polinomios son diferentes.";
    }


    return 0;
}