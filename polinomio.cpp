#include <iostream>
using namespace std;

struct Termino {
    float coef;
    int exp;
    Termino* sig;
};

Termino* cabeza = nullptr;

void insertar(float c, int e){
    Termino* n = new Termino{c, e, nullptr};
    if(!cabeza || e > cabeza->exp){ n->sig = cabeza; cabeza = n; return; }
    Termino *a = cabeza, *ant = nullptr;
    while(a && a->exp > e){ ant = a; a = a->sig; }
    if(a && a->exp == e){ a->coef += c; return; }
    n->sig = a;
    if(!ant) cabeza = n; else ant->sig = n;
}

void mostrar(){
    if(!cabeza){ cout << "0\n"; return; }
    Termino* a = cabeza;
    while(a){ cout << a->coef << "x^" << a->exp; if(a->sig) cout << " + "; a = a->sig; }
    cout << endl;
}

int main(){
    insertar(3,2);
    insertar(2,1);
    insertar(5,0);
    cout << "Mi Polinomio: ";
    mostrar();
    return 0;
}
Le das *Archivo > Guardar*, cierras.

Y ahora sí, compilas:
g++ polinomio.cpp -o polinomio.exe
.\polinomio.exe
Ya te tiene que salir `Mi Polinomio: 3x^2 + 2x^1 + 5x^0`

Haz eso del notepad y mándame foto del `.\polinomio.exe`.
