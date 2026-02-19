#include <iostream>
using namespace std;

void Imprimir(int (*M)[5], int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<5; j++){
            cout << *(*(M+i)+j) << " ";
        }
        cout << endl;
    }
}

//recibe un puntero al inicio de la matriz, sus dimensiones y coordenadas de la submatriz
int SumaSubmatriz(int *M, int filas, int columnas, int fi, int ci, int ff, int cf){
    int suma = 0;
    for(int i=fi; i<=ff; i++){
        for(int j=ci; j<=cf; j++){
            suma += *(M + i*columnas + j);
        }
    }

    return suma;   //OBS: no usa filas, pero las manda la funcion Submatriz, por eso las dejo
}

void MaxSubmatriz(int *M, int filas, int columnas){
    int maxsuma = SumaSubmatriz(M, filas, columnas, 0, 0, 0, 0);
    int maxfi = 0, maxci = 0, maxff = 0, maxcf = 0;  //variables para guardar las coordenadas

    for (int fi = 0; fi < filas; fi++){
        for(int ci = 0; ci < columnas; ci++){
            for(int ff = fi; ff < filas; ff++){          //usa varios for para recorrer
                for(int cf = ci; cf < columnas; cf++){

                    int suma = SumaSubmatriz(M, filas, columnas, fi, ci, ff, cf);
                    //suma la submatriz actual
                    if(suma > maxsuma){
                        maxsuma = suma;
                        maxfi = fi; 
                        maxci = ci;
                        maxff = ff;
                        maxcf = cf;
                   }  
                }
            }
        }
    }

    cout << "Esquina superior izquierda: (" << maxfi << ", " << maxci << ")" << endl;
    cout << "Esquina inferior derecha: (" << maxff << ", " << maxcf << ")" << endl;
    cout << "Suma maxima: " << maxsuma << endl;
}

int main(){

    int matriz[4][5] = {
        {-2, 1, -3, 4,-1},
        {2, 3, -2, 1, -5},
        {-1, 4, 2, -3, 2},
        {1, -2, 3, 4, -1}
    };

    Imprimir(matriz, 4);

    cout << "Submatriz de suma maxima: " <<endl;
    MaxSubmatriz((int*)matriz, 4, 5);

    return 0;
}