#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void LlenarArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
        *(arr + i) = rand() % 10;
    }
}

void MostrarArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int MaxCosto(int *A, int n, int i){
    if(i == n){
        return 0;
    }

    int mejor = 0;
    int producto = 1;

    for(int k = i; k < n; k++){
        producto *= *(A + k);
        int costo = producto + MaxCosto(A, n, k + 1);
        if(costo > mejor){
            mejor = costo;
        }
    }

    return mejor;
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

    int rpta = MaxCosto(arr, n, 0);

    cout << "Costo Maximo: " << rpta << endl;

    return 0;
}