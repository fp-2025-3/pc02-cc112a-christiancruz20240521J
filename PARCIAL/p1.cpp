#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void LlenarArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
        *(arr + i) = rand() % 100;
    }
}

void MostrarArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main(){

    srand(time(NULL));

    int n;
    cout << "digite tamaño del arreglo: ";
    cin >> n;

    int *arr = new int[n];

    LlenarArreglo(arr, n);
    cout << "A: ";
    MostrarArreglo(arr, n);


    return 0;
}