#include <iostream>
using namespace std;

bool EsAnagrama(char* p1, char* p2){

    int cont[256] = {0};

    while(*p1 != '\0'){
        cont[*p1 - 'a']++;
        p1++;
    }

    while(*p2 != '\0'){
        cont[*p2 - 'a']--;
        p2++;
    }

    for(int i=0; i<256; i++){
        if(cont[i] != 0){
            return false;
        }
    }

    return true;
}

int main(){

    char palabra1[10];
    char palabra2[10];

    cout << "Ingrese la primera palabra: ";
    cin >> palabra1;
    cout << "Ingrese la segunda palabra: ";
    cin >> palabra2;

    char* p1 = palabra1;
    char* p2 = palabra2;

    if(EsAnagrama(p1, p2)){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }


    return 0;
}