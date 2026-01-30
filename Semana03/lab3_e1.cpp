#include <iostream>
using namespace std;

void MySwap(char v1[], char v2[]){
    char* temp = v1;
    v1 = v2;
    v2 = temp;
}

int separar_palabras(char* texto, char* palabras[]){
    char *p = texto;
    int i = 0; //contador
    while(*p != '\0'){
        if((p == texto && *p != ' ') || (*(p-1) == ' ' && *p != ' ')){
            palabras[i] = p;
            i++;
        }
        p++;
    }

    return i;
}

int longitud_palabra(const char* p){
    int longitud = 0;

    while (*p != ' ' && *p != '\0'){
        longitud++;
        p++;
    }
    
    return longitud;
}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl){
    //recorrer el arreglo de punteros
    //clasificar segun longitud

    int indLargas = 0, indCortas = 0;

    for(int i=0; i<n; i++){
        int longitud = longitud_palabra(palabras[i]);
        if(longitud <= 3){
            cortas[indCortas] = palabras[i];
            indCortas++;
            nc++;
        } else {
            largas[indLargas] = palabras[i];
            indLargas++;
            nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b){
    int i=0;

    while(a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0'){
        if(a[i] != b[i]){
            return a[i] - b[i];
        }
        i++;
    }

    if(a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0'){
        return 0;
    }

    if(b[i] == ' ' || b[i] == '\0'){
        return 1;
    } else {
        return -1;
    }
}

void ordenar(char* v[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j < n - i- 1; j++){
            if(comparar_palabras(v[j], v[j+1]) < 0){
                MySwap(v[j], v[j+1]);
            }
        }
    }

}

void imprimir_grupo(const char* titulo, char* v[], int n){
    cout << "Palabras " << titulo << ": " << endl;
    for(int i=0; i<n; i++){
        char* p = v[i];
        while(*p != ' ' && *p != '\0'){
            cout << *p;
            p++;
        }
        cout << endl;
    }
}

int main(){

    char texto[] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];

    int n = separar_palabras(texto, palabras);
    int nc = 0, nl = 0;
    clasificar(palabras, n, cortas, nc, largas, nl);
    ordenar(cortas, nc);
    ordenar(largas, nl);
    imprimir_grupo("cortas", cortas, nc);
    imprimir_grupo("largas", largas, nl);

    return 0;
}