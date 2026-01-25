#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for(int* i=inicio; i<fin;i++){
        if(equivale(*i, clave)){
            return i;
        }
    }

    return fin;
    
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida

bool igual(int a, int b){
    return a == b;
}

bool mismaParidad(int a, int b){
    return (a % 2) == (b % 2);
}

bool divideA(int a, int b){
    if(a == 0){
        return false; //evitar desbordamiento
    } 
    return b % a == 0;
}

int contarDigitos(int n){  //funcion auxiliar
        if(n == 0) return 1;
        int count = 0;
        if(n < 0) n = -n; // para negativos
        while(n > 0){
            n /= 10;
            count++;
        }
        return count;
    }

bool mismaCantidadDigitos(int a, int b){
    return contarDigitos(a) == contarDigitos(b);
}

bool mismoResiduoMod5(int a, int b){
    return (a % 5) == (b % 5);
}

void imprimirArreglo(int* inicio, int* fin){
    for(int* i = inicio; i < fin; i++){
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    imprimirArreglo(inicio, fin);

    // Llame a la funcion buscar para cada criterio implementado

    int* rpta1 = buscar(inicio, fin, igual, clave);
    if(rpta1 != fin){
        cout << "Igualdad exacta: " << *rpta1 << " POS: " << rpta1 << endl;
    } 

    int* rpta2 = buscar(inicio, fin, mismaParidad, clave);
    if(rpta2 != fin){
        cout << "Misma paridad: " << *rpta2 << " POS : " << rpta2 << endl;
    }

    int* rpta3 = buscar(inicio, fin, divideA, clave);
    if(rpta3 != fin){
        cout << "Divide a: " << *rpta3 << " POS: " << rpta3 << endl;
    }

    int* rpta4 = buscar(inicio, fin, mismaCantidadDigitos, clave);
    if(rpta4 != fin){
        cout << "Misma cantidad de digitos): " << *rpta4 << " POS: " << rpta4 << endl;
    }

    int* rpta5 = buscar(inicio, fin, mismoResiduoMod5, clave);
    if(rpta5 != fin){
        cout << "Mismo residuo mod 5: " << *rpta5 << " POS: " << rpta5 << endl;
    }

    return 0;
}
