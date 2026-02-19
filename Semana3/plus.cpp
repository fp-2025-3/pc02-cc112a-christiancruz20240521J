#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstddef>
using namespace std;

void RellenarMatriz(int* p, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            *(p + i * columnas + j) = rand() % 10 + 1; //números aleatorios entre 1 y 10
        }
    }
}

void imprimir(int* p, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << *(p + i * columnas + j) << " ";
        }
        cout << endl;
    }
}

int main(){

    srand((unsigned)time(NULL)); //semilla para números aleatorios

    int matriz[10][10];

    int* p = &matriz[0][0];

    RellenarMatriz(p, 10, 10);
    imprimir(p, 10, 10);

    return 0;
}