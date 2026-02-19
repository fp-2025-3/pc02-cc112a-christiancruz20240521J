#include <iostream>
using namespace std;

void AgregarEstudiantes(double *&codigos, double *&promedios, int &cantidad, int &capacidad) {

    if(cantidad == capacidad){
        capacidad *= 2;

        double *Ncodigos = new double[capacidad];
        double *Npromedios = new double[capacidad];

        for(int i = 0; i< cantidad; i++){
            *(Ncodigos + i) = *(codigos + i);
            *(Npromedios + i) = *(promedios + i);
        }

        delete[] codigos;
        delete[] promedios;

        codigos = Ncodigos;
        promedios = Npromedios;
    }

    cout << "Ingrese el codigo del estudiante " << (cantidad + 1) << ":";
    cin >> *(codigos + cantidad);
    cout << "Ingrese el promedio del estudiante " << (cantidad + 1) << ":";
    cin >> *(promedios + cantidad);

    cantidad++;

}

void MostrarEstudiantes(double *codigos, double *promedios, int n) {
    for(int i = 0; i < n; i++){
        cout << "Codigo: " << *(codigos + i) << " Promedio: " << *(promedios + i) << endl;
    }
}

void EliminarDesaprobados(double *&codigos, double *&promedios, int &n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (promedios[i] >= 10) {
            codigos[cont] = codigos[i];
            promedios[cont] = promedios[i];
            cont++;
        }
    }

    double *codigosN = new double[cont];
    double *promediosN = new double[cont];

    for (int i = 0; i < cont; i++) {
        codigosN[i] = codigos[i];
        promediosN[i] = promedios[i];
    }
    
    delete[] codigos;
    delete[] promedios;

    codigos = codigosN;
    promedios = promediosN;
    n = cont;
}

int main(){

    int capacidadI = 3;
    int cantidad = 0;

    double *codigos = new double[capacidadI];
    double *promedios = new double[capacidadI];

    int capacidad = capacidadI;

    for(int i=0; i<5; i++){
        AgregarEstudiantes(codigos, promedios, cantidad, capacidad);
    }

    cout << "\nEstudiantes registrados:\n";
    MostrarEstudiantes(codigos, promedios, cantidad);

    cout << "\nFiltrando estudiantes desaprobados...\n";
    EliminarDesaprobados(codigos, promedios, cantidad);
    
    cout << "\nEstudiantes aprobados:\n";
    MostrarEstudiantes(codigos, promedios, cantidad);

    delete[] codigos;
    delete[] promedios;

    return 0;
}

