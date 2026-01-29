#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
    // Escriba su codigo aqui
    gradoRes = grado - k;

    for(int i = k; i <= grado; i++){
        double factor = 1.0;

        for(int j=0; j<k; j++){
            factor *= (i-j);
        }
        *(res + (i - k)) = (*(coef + i)) * factor;
    }

}

// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
    for(int i=0; i<=grado; i++){
        cout << *(p + i);
        if(i>0){
            cout << "x^" << i;
        }
        if(i<grado){
            cout << " + ";
        }
    }
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK

    derivadaK(coef, grado, k, resultado, gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada

    cout << "Polinomio original: ";
    imprimirPolinomio(coef, grado);
    cout << endl;
    cout << "Derivada de orden " << k << ": ";
    imprimirPolinomio(resultado, gradoResultado);
    cout << endl;
    
    return 0;
}