#include <iostream>
using namespace std;

void AgregarEstudiantes(double *&codigos, double *promedios, int &n) {
    for(int i = 0; i < n; i++){
        cout << "Ingrese el codigo del estudiante " << (i + 1) << ":";
        cin >> *(codigos + i);
        cout << "Ingrese el promedio del estudiante " << (i + 1) << ":";
        cin >> *(promedios + i);
    }
}

void MostrarEstudiantes(double *codigos, double *promedios, int n) {
    for(int i = 0; i < n; i++){
        cout << "Codigo: " << *(codigos + i) << " Promedio: " << *(promedios + i) << endl;
    }
}

double* EliminarDesaprobados(double *codigos, double *promedios, int &n) {
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(*(promedios + i) >= 10){  // Cambio aquí: >= en lugar de >
            *(codigos + cont) = *(codigos + i);
            *(promedios + cont) = *(promedios + i);
            cont++;
        }
    }
    n = cont;  // Actualizar n con los aprobados
    return codigos;
}

int main(){

    int n = 5;

    double *codigos = new double[n];
    double *promedios = new double[n];

    AgregarEstudiantes(codigos, promedios, n);

    cout << "\nEstudiantes registrados:\n";
    MostrarEstudiantes(codigos, promedios, n);

    cout << "\nFiltrando estudiantes desaprobados...\n";
    EliminarDesaprobados(codigos, promedios, n);

    double *codigosAprobados = new double[n];
    double *promediosAprobados = new double[n];
    for(int i = 0; i < n; i++){
        *(codigosAprobados + i) = *(codigos + i);
        *(promediosAprobados + i) = *(promedios + i);
    }
    
    cout << "\nEstudiantes aprobados:\n";
    MostrarEstudiantes(codigos, promedios, n);

    delete[] codigos;
    delete[] promedios;

    return 0;
}

