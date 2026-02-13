#include <iostream>
using namespace std;

void imprimir(int (*M)[5], int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<5; j++){
            cout << *(*(M+i)+j) << " ";
        }
        cout << endl;
    }
}

//es pico si es mayor/igual que sus 4 vecinos ortogonales
//es pico si es estricamente mayor que al menos uno de dichos vecinos 

void EsPico(int (*M)[5], int filas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<5; j++){
            int temp = *(*(M+i)+j);
            bool esPico = true;
            bool EsMayor = false;
            
            if(i>1){    //vecino norte
                int p = *(*(M+i-1)+j);
                if( temp < p ){
                    esPico = false;
                }
                if(temp > p){    //compara el caso concreto
                    EsMayor = true;
                }
            }

            if(i<filas-1){    //vecino sur
                int p = *(*(M+i+1)+j);
                if( temp < p ){
                    esPico = false;
                }
                if(temp > p){  
                    EsMayor = true;
                }
            }

            if(j>0){    //vecino oeste
                int p = *(*(M+i)+j-1);
                if( temp < p ){
                    esPico = false;
                }
                if(temp > p){
                    EsMayor = true;
                }
            }

            if(j<4){    //vecino este
                int p = *(*(M+i)+j+1);
                if( temp < p ){
                    esPico = false;
                }
                if(temp > p){
                    EsMayor = true;
                }
            }

            if(esPico && EsMayor){
                cout << "Pico en (" << i << "," << j << "): " << temp << endl;  //imprima la coordenada y el valor
            
        }
    }
}
}

int main(){

    int matriz[4][5]={
        {3,3,3,3,3},
        {3,4,4,2,3},
        {3,4,5,4,3},
        {3,3,3,3,3}
    };

    cout << "Matriz:" << endl;
    imprimir(matriz, 4);

    cout << "Elementos pico:" << endl;
    EsPico(matriz, 4);

    return 0;
}