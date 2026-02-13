#include <iostream>
using namespace std;

int MaxCosto(int *A, int n, int i, int rango){

    cout << "accediendo: i = " << i << endl;

    if(i == n){
        return 0;
    }

    int mejor = 0;
    int producto = 1;

    for(int k = i; k < n; k++){
        producto *= *(A + k);

        int NextRes = MaxCosto(A,n, k+1,rango+1);
        int costo = producto + NextRes;

        if(costo > mejor){
            mejor = costo;
        }
    }

    cout << "Saliendo: i = " << i << " mejor: " << mejor << endl;

    return mejor;
}

int main(){

    int A[] = {2,1,3};
    int n = sizeof(A) / sizeof(A[0]);

    int rpta = MaxCosto(A,n,0,0);

    cout << "\nCosto maximo total: " << rpta << endl;

    return 0;
}