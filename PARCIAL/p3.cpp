#include <iostream>
using namespace std;

const int N = 4;

bool esFilaDominanteEstricta(int (*M)[N], int f){
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(i != f){
                if(*(*(M + f) + j) <= *(*(M + i) + j)){ 
                    return false;
                }
            }
        }
    }
    return true;
}

bool esFilaFuertementeDominante(int (*M)[N], int f){
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(i != f){
                if(*(*(M + f) + j) < *(*(M + i) + j)){
                    return false;
                }
            }
        }
    }

    int sumaFila = 0;
    for(int j = 0; j < N; j++){
        sumaFila += *(*(M + f) + j);
    }

    for(int i = 0; i < N; i++){

        if(i == f) continue;
        int sumaI = 0;

        for(int j = 0; j < N; j++){
            sumaI += *(*(M + i) + j);
        }
        if(sumaFila <= sumaI) {
            return false;
        }
    }

    return true;
}

void MostrarMatriz(int (*M)[N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << *(*(M + i) + j) << " ";
        }
        cout << endl;
    }
}

int main(){
    
    int M[N][N] = {
        {2, 3, 1, 4},
        {1, 2, 3, 2},
        {5, 6, 7, 8},
        {0, 1, 2, 1}
    };

    cout << "Matriz:" << endl;
    MostrarMatriz(M);

    cout << endl;

    cout << " Fila   Dominante Estricta     Fuertemente Dominante  " << endl;
    cout << "------------------------------------------------------" << endl;

    for(int f = 0; f < N; f++){
        bool dominanteEstricta = esFilaDominanteEstricta(M, f);
        bool fuertementeDominante = esFilaFuertementeDominante(M, f);
        
        cout << "  " << f << "      ";
        
        if(dominanteEstricta){
            cout << "SÍ";
        } else {
            cout << "NO";
        }

        cout << "                    ";
        
        if(fuertementeDominante){
            cout << "SÍ";
        } else {
            cout << "NO";
        }
        
        cout << "                 " << endl;
    }

    return 0;
}