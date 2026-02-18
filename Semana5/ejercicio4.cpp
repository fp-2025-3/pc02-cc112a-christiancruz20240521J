#include <iostream>
#include <cmath>
using namespace std;

struct polinomio{
    int grado;
    int* coef;
};

polinomio crear(int grado){
    polinomio p;
    p.grado = grado;
    p.coef = new int[grado + 1];

    for(int i=0; i <= grado; i++){
        p.coef[i] = 0;
    }

    return p;
}


void leer(polinomio &p){
    for(int i=0; i <= p.grado; i++){
        cout << "Ingrese el coeficiente de x^" << i << ":";
        cin >> p.coef[i];
    }
}

void mostrar(polinomio &p){
    for(int i = 0; i <= p.grado; i++){
        if(i > 0){
            cout << " + ";
        }
        cout << p.coef[i] << "x^" << i;
    }
    cout << endl;
}

int evaluar(polinomio &p, int x){
    int res = 0;

    for(int i = 0; i <= p.grado; i++){
        res += p.coef[i]*pow(x,i);
    }

    return res;
}

polinomio sumar(polinomio a, polinomio b){
    int maxGrado = 0;

    if(a.grado > b.grado){
        maxGrado = a.grado;
    } else {
        maxGrado = b.grado;
    }

    polinomio r;

    r.grado = maxGrado;

    r.coef = new int[maxGrado + 1];


    for(int i = 0; i <= maxGrado; i++){
        int coefA = 0;
        if(i <= a.grado){
            coefA = a.coef[i];
        } else {
            coefA = 0;
        }

        int coefB = 0;
        if(i <= b.grado){
            coefB = b.coef[i];
        } else {
            coefB = 0;
        }

        r.coef[i] = coefA + coefB;
    }

    return r;
}

polinomio multilicar(polinomio a, polinomio b){
    polinomio r;

    r.grado = a.grado + b.grado;
    r.coef = new int[r.grado + 1];

    for(int i = 0; i <= r.grado; i++){
        r.coef[i] = 0;
    }

    for ( int i = 0; i <= a.grado; i++){
        for(int j = 0; j <= b.grado; j++){
            r.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return r;
    
}

void liberar(polinomio &p){
    delete[] p.coef;
}

int main(){

    int grad1, grad2;

    cout << "Grado del primer polinomio: ";
    cin >> grad1;

    polinomio a = crear(grad1);
    leer(a);

    cout << "\nGrado del segundo polinomio: ";
    cin >> grad2;

    polinomio b = crear(grad2);
    leer(b);

    cout << "<\nPolinomio 1:\n";
    mostrar(a);
    cout<< "\nPolionomio 2:\n";
    mostrar(b);

    polinomio s = sumar(a,b);

    cout << "\nSuma: " << endl;
    mostrar(s);

    polinomio m = multilicar(a,b);

    cout << "\nMultiplicacion: " << endl;
    mostrar(m);

    int valor; 
    cout << "Digite valor a evalular en el polinomio 1: ";
    cin >> valor;

    int rpta = evaluar(a, valor);
    cout << "rpta: " << rpta << endl;

    liberar(a);
    liberar(b);
    liberar(s);
    liberar(m);

    return 0;
}