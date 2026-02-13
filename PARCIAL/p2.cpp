#include <iostream>
#include <cstring>
using namespace std;

void Ranking(string *nombres, double *tiempos, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(tiempos + j) > *(tiempos + j + 1)){
                swap(*(tiempos + j), *(tiempos + j + 1));
                swap(*(nombres + j), *(nombres + j + 1));
            }
        }
    }
}

void BuscarCorredor(string *nombres, double *tiempos, int n, string nombreBuscado){
    for(int i = 0; i < n; i++){
        if(*(nombres + i) == nombreBuscado){
            cout << "Corredor encontrado\n";
            cout << "Posicion: " << (i + 1) << endl;
            cout << "Tiempo: " << *(tiempos + i) << " segundos" << endl;
            return;
        }
    }
    cout << "Corredor no encontrado." << endl;
}

int main(){

    int n;
    cout << "Ingrese numero de corredores: ";
    cin >> n;

    string *nombres = new string[n];
    double *tiempos = new double[n];

    for(int i = 0; i < n; i++){
        cout << "Nombre del corredor " << (i + 1) << ": ";
        cin >> *(nombres + i);
        cout << "Tiempo del corredor " << (i + 1) << ": ";
        cin >> *(tiempos + i);
    }

    Ranking(nombres, tiempos, n);
    cout << "\nRANKING FINAL\n";
    for(int i = 0; i < n; i++){
        cout << (i + 1) << ". " << *(nombres + i) << " - Tiempo: " << *(tiempos + i) << endl;
    }

    string Buscado;
    cout << "\nIngrese nombre a buscar: ";
    cin >> Buscado;
    BuscarCorredor(nombres, tiempos, n, Buscado);

    int tmin, tmax;
    cout << "\nIngrese el tiempo minimo: ";
    cin >> tmin;
    cout << "Ingrese el tiempo maximo: ";
    cin >> tmax;

    cout << "\nCorredores en el rango [" << tmin << "," << tmax << "]:\n";
    for(int i = 0; i < n; i++){
        if(*(tiempos + i) >= tmin && *(tiempos + i) <= tmax){
            cout << *(nombres + i) << " - " << *(tiempos + i) << " segundos" << endl;
        }
    }

    delete[] nombres;
    delete[] tiempos;

    return 0;
}