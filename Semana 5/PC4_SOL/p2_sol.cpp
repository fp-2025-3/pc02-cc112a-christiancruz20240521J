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
    for(int k = 0; k < 5; k++){
        (equipo + k)->gf = 0;
        (equipo + k)->gc = 0;

        int gf, gc;

        for(int i = 0; i < (equipo + k)->pg; i++){
        do{
            gf = rand()% 6;
            gc = rand()% 6;
        } while(gf <= gc);

        (equipo + k)->gf += gf;
        (equipo + k)->gc += gc;
        }

        for(int i = 0; i < (equipo + k)->pe; i++){
        gf = rand()% 6;
        gc = gf;

        (equipo + k)->gf += gf;
        (equipo + k)->gc += gc;
        }

        for(int i = 0; i < (equipo + k)->pp; i++){
        do{
            gf = rand()% 6;
            gc = rand()% 6;
        } while(gf >= gc);

        (equipo + k)->gf += gf;
        (equipo + k)->gc += gc;
        }
    }
}

void llenarPuntaje(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        (equipo + i)->puntaje = (3 * (equipo + i)->pg) + (equipo + i)->pe;
    }
}


void rendimiento(seleccion *equipo){
    for (int i = 0; i < 5; i++){
        (equipo + i)->rend = (((equipo + i)->puntaje) / 300.0) * 100;
    }
}

void ordenar(seleccion *equipo){
    seleccion aux;

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            int df_i = (equipo + i)->gf - (equipo + i)->gc;
            int df_j = (equipo + i)->gf - (equipo + j)->gc;

            if((equipo + j)->puntaje > (equipo + i)->puntaje ||
               ((equipo + j)->puntaje == (equipo + i)->puntaje && df_j > df_i)){
                aux = *(equipo + i);
                *(equipo + i) = *(equipo + j);
                *(equipo + j) = aux;
            }
        }
    }

    cout << "\n================TABLA DE POSICIONES=================\n";
    cout << "\nSeleccion\tPG\tPE\tPP\tGF\tGC\tDG\tPts\tRend(%)\n";
    cout << "-------------------------------------------------------------------------------\n";

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

}

void campeon(seleccion *equipo){

    cout << "\nCAMPEON: " << equipo[0].nombre << " | "
         << "Puntaje: " << equipo[0].puntaje << " | "
         << "DG: " << equipo[0].gf - equipo[0].gc << " | "
         << "Rendimiento: " << equipo[0].rend << "%" << endl; 
}

int main(){

    srand(time(NULL));

    seleccion *equipo = new seleccion[5];

    llenarNombre(equipo);
    llenarPartidos(equipo);
    llenarGoles(equipo);
    llenarPuntaje(equipo);
    rendimiento(equipo);

    ordenar(equipo);

    campeon(equipo);

    delete[] equipo;

    return 0;
}