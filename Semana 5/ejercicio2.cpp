#include <iostream>
#include <string>
using namespace std;

struct Estudiante{
    string nombre;
    float nota;
};

void llenarDatos(Estudiante &ests){
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin >> ws, ests.nombre);
    cout << "Ingrese nota del estudiante: ";
    cin >> ests.nota;
}

void MayorNota(Estudiante* estudiantes, int n){
    if(n == 0){
        return;
    }

    int mayor = 0;

    for(int i = 1; i < n; i++){
        if((estudiantes + i)->nota > (estudiantes + mayor)->nota){
            mayor = i;
        }
    }

    cout << (estudiantes + mayor)->nombre << endl;
    cout << "Nota: " << (estudiantes + mayor)->nota << endl;
}

int main(){

    int n;
    cout << "ingrese numero de estudiantes: ";
    cin >> n;

    Estudiante* estudiantes = new Estudiante[n];

    for(int i=0; i<n; i++){
        llenarDatos(estudiantes[i]);
    }

    cout <<"\nEl estudiante con mayor nota es: ";
    MayorNota(estudiantes, n);

    delete[] estudiantes;

    return 0;
}