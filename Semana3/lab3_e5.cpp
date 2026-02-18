#include <iostream>
#include <cstdlib>  //para atoi y atof
using namespace std;

bool EntenderRaw(char* persona, char* nombre, char* direccion, char* telefono, int& edad, float& estatura){
    char* p = persona;
    char temp[50];
    
    //nombre
    int i = 0;
    while(*p != ',' && *p != '\0'){
        nombre[i] = *p;
        i++;
        p++;
    }
    if(*p == '\0'){
        return false;
    }
    nombre[i] = '\0';
    p++; //saltar la coma
    
    //direccion
    i = 0;
    while(*p != ',' && *p != '\0'){
        direccion[i] = *p;
        i++;
        p++;
    }
    if(*p == '\0'){
        return false;
    }
    direccion[i] = '\0';
    p++; //saltar la coma

    //telefono
    i = 0;
    while(*p != ',' && *p != '\0'){
        telefono[i] = *p;
        i++;
        p++;
    }
    if(*p == '\0'){
        return false;
    }
    telefono[i] = '\0';
    p++; //saltar la coma

    //edad
    i = 0;
    while(*p != ',' && *p != '\0'){
        temp[i] = *p;
        i++;
        p++;
    }
    if(*p == '\0'){
        return false;
    }
    temp[i] = '\0';
    edad = atoi(temp);   //seleccionar atoi para int
    p++; //saltar la coma
    
    //estatura
    i = 0;
    while(*p != '\0'){
        temp[i] = *p;
        i++;
        p++;
    }
    temp[i] = '\0';
    estatura = atof(temp); //seleccionar atof para float
    return true;
}


int main(){

    char persona1[100] = "Juan Torres, Honorio Delgado 123, 987654321, 24, 1.49";
    char persona2[100] = "Ana Perez, Los Alamos 456, 123456789, 30, 1.65";
    char persona3[100] = "Luis Gomez, Miraflores 789, 456123789, 28, 1.75";

    char nombre[20];
    char direccion[50];
    char telefono[10];
    int edad;
    float estatura;

    for(int i=0; i<3; i++){
        char* persona;
        if(i == 0){
            persona = persona1;
        } else if(i == 1){
            persona = persona2;
        } else {
            persona = persona3;
        }

        if(EntenderRaw(persona, nombre, direccion, telefono, edad, estatura)){
            cout << "Nombre: " << nombre << endl;
            cout << "Direccion: " << direccion << endl;
            cout << "Telefono: " << telefono << endl;
            cout << "Edad: " << edad << endl;
            cout << "Estatura: " << estatura << endl;
            cout << "------------------------" << endl;
        } else {
            cout << "Error al entender los datos de la persona." << endl;
        }
    }

    return 0;
}