#include <iostream>
using namespace std;

struct polinomio{
    int grado;
    int* coef;
};

void mostrar(polinomio &p){
    for(int i = p.grado; i >= 0; i--){
        if(i >= 0 && i < p.grado){
            cout << " + ";
        }
        cout << p.coef[i] << "x^" << i;
    }

    cout << endl;
}

polinomio sumar(polinomio &a, polinomio &b){
    int maxG = 0;

    if(a.grado > b.grado){
        maxG = a.grado;
    } else {
        maxG = b.grado;
    }

    polinomio s;
    s.grado = maxG;
    s.coef = new int[maxG + 1];

    for(int i = 0; i <= maxG; i++){
        int coefA = 0;
        if(i <= a.grado){
            coefA = a.coef[i];
        }

        int coefB = 0;
        if(i <= b.grado){
            coefB = b.coef[i];
        }

        s.coef[i] = coefA + coefB;
    }

    return s;
}

polinomio multiplicar(polinomio &a, polinomio &b){
    polinomio m;

    m.grado = a.grado + b.grado;
    m.coef = new int[m.grado + 1];

    for(int i = 0; i <= m.grado; i++){
        m.coef[i] = 0;
    }

    for(int i = 0; i <= a.grado; i++){
        for(int j = 0; j <= b.grado; j++){
            m.coef[i + j] += a.coef[i]*b.coef[j]; 
        }
    }

    return m;
}

int main(){

    int grad1 = 2;
    int grad2 = 1;
    int grad3 = 2;

    polinomio p1, p2, p3;

    p1.grado = grad1;
    p2.grado = grad2;
    p3.grado = grad3;

    p1.coef = new int[grad1 + 1]{3,0,1};
    p2.coef = new int[grad2 + 1]{5, -4};
    p3.coef = new int[grad3 + 1]{1,0,3};

    cout << "Polinomio 1: ";
    mostrar(p1);
    cout << "Polinomio 2: ";
    mostrar(p2);
    cout << "Polinomio 3: ";
    mostrar(p3);

    polinomio sumaM = sumar(p1,p2);
    polinomio sumaF = sumar(sumaM,p3);

    cout << "\nSuma de los tres polinomios: ";
    mostrar(sumaF);

    polinomio prodM = multiplicar(p1,p2);
    polinomio prodF = multiplicar(prodM, p3);

    cout << "\nProducto de los tres polinomios: ";
    mostrar(prodF);
    
    delete[] p1.coef;
    delete[] p2.coef;
    delete[] p3.coef;
    delete[] sumaM.coef; //arrays que no libere y que valgrind detecto donde hay fuga de memoria
    delete[] sumaF.coef; //lo corrijo haciendo delete[] a cada uno
    delete[] prodM.coef;
    delete[] prodF.coef;

    return 0;
}