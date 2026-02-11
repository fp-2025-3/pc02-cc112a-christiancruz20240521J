#include <iostream>
#include <cmath>
using namespace std;

struct punto {
    int x;
    int y;
    int z;
};

void llenarPunto(punto &coo){

    cout << "ingrese coordenada X: ";
    cin >> coo.x;
    cout << "ingrese coordenada Y: ";
    cin >> coo.y;
    cout << "ingrese coordenada Z: ";
    cin >> coo.z;

}

void Distancia(punto a, punto b){
    double rpta = sqrt(pow(a.x - b.x, 2) + 
                          pow(a.y - b.y, 2) + 
                          pow(a.z - b.z, 2));
    
    cout << rpta << endl;

}

int main(){

    punto a;
    punto b;

    cout << "ingrese las coordenadas del primer punto:\n";
    llenarPunto(a);

    cout << "\ningrese las coordenadas del segundo punto:\n";
    llenarPunto(b);

    cout << "\nDistancia entre puntos:\n";
    Distancia(a,b);

    return 0;
}