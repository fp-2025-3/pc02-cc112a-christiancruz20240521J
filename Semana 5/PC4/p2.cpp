#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct seleccion{
    string nombre;
    int pg, pe, pp;
    int gf, gc;
    double puntaje;
    double rend;
};

void llenarNombre(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        cout << "ingrese nombre del equipo " << i + 1 << ": ";
        getline(cin >> ws, (equipo + i)->nombre);
    }
}

void llenarPartidos(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        (equipo + i)->pg = rand() % 100 + 1;
        (equipo + i)->pe = rand() % (100 - (equipo + i)->pg + 1);
        (equipo + i)->pp = 100 - (equipo + i)->pg - (equipo + i)->pe;
    }
}

void llenarGoles(seleccion *equipo){
    for(int i = 0; i < 5; i++){
        (equipo + i)->gf = rand() % 500 + 1;
        (equipo + i)->gc = rand() % 500 - (equipo + i)->gf;
    }
}

void llenarPuntaje(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        (equipo + i)->puntaje = (3 * (equipo + i)->pg) + (equipo + i)->pe;
    }
}


void Rendimiento(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        (equipo + i)->rend = (((equipo + i)->puntaje) / 300.0) * 100;
    }
}

int main(){

    srand(time(NULL));

    seleccion *equipo = new seleccion[5];

    llenarNombre(equipo);
    llenarPartidos(equipo);
    llenarGoles(equipo);
    llenarPuntaje(equipo);
    Rendimiento(equipo);

    cout << "\n================TABLA DE POSICIONES=================\n";
    cout << "\nSeleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++){
        cout << (equipo + i)->nombre << "\t\t";
        cout << (equipo + i)->pg << "\t";
        cout << (equipo + i)->pe << "\t";
        cout << (equipo + i)->pp << "\t";
        cout << (equipo + i)->gf << "\t";
        cout << (equipo + i)->gc << "\t";
        cout << (equipo + i)->gf - (equipo + i)->gc << "\t";
        cout << (equipo + i)->puntaje << "\t";
        cout << (equipo + i)->rend << endl;
    }

    cout << "\nCAMPEON: ";

    delete[] equipo;

    return 0;
}