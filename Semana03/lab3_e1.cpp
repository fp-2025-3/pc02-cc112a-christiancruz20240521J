#include <iostream>
using namespace std;

// swap(v[j], v[j+1]); // EJERCICIO, implementar su propia funcion intercambio

void MySwap(char v1[], char v2[]){
    char aux[20];
    char *p = v1;
    char *q = v2;

    while (*p != '\0'){
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';

    p = v2;
    q = v1;
    while(*p!='\0'){
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';

    p = aux;
    q = v2;
    while(*p != '\0'){
        *q = *p;
        q++;
        p++;
    }
    *q = '\0';

}

int separar_palabras(char *texto, char *palabras[])
{

    int i = 0;       // contador de palabras
    char *p = texto; // almacena la dirección del primer caracter en texto

    while (*p != '\0')
    {
        if ((p == texto && *p != ' ') || (*(p - 1) == ' ' && *p != ' '))
        {
            palabras[i] = p;

            i++;
        }

        p++;
    }

    return i;
}

int longitud_palabra(const char *p)
{
    int longitud = 0;

    while (*p != ' ' && *p != '\0')
    {
        longitud++;
        p++;
    }

    return longitud;
}

void clasificar(char *palabras[], int n, char *cortas[], int &nc, char *largas[], int &nl)
{

    // recorrer el arreglo de punteros palabras
    // Clasificar segun su longitud

    int indLargas = 0, indCortas = 0;

    for (int i = 0; i < n; ++i)
    {

        int longitud = longitud_palabra(palabras[i]);

        if (longitud <= 3)
        {
            cortas[indCortas] = palabras[i];
            indCortas++;
            nc++;
        }
        else
        {
            largas[indLargas] = palabras[i];
            indLargas++;
            nl++;
        }
    }
}

int comparar_palabras(const char *a, const char *b)
{

    int i = 0;

    while (a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0')
    {

        if (a[i] != b[i])
        {
            return a[i] - b[i];
        }

        i++;
    }

    if ((a[i] == ' ' || a[i] == '\0') && (b[i] == ' ' || b[i] == '\0'))
    {
        return 0;
    }

    if ((b[i] == ' ' || b[i] == '\0'))
    {
        return 1;
    }

    return -1;
}

void ordenar(char *v[], int n)
{

    for (int i = 0; i < n - 1; ++i)
    { // numero de pasadas
        for (int j = 0; j < n - i - 1; ++j)
        { // intercambios
            if (comparar_palabras(v[j], v[j + 1]) > 0)
            {
                MySwap(v[j], v[j + 1]); // EJERCICIO, implementar su propia funcion intercambio
            }
        }
    }
}

void imprimir_grupo(const char *titulo, char *v[], int n)
{
    cout << titulo << endl;
    for (int i = 0; i < n; ++i)
    {
        char *p = v[i];

        while (*p != ' ' && *p != '\0')
        {
            cout << *p;
            p++;
        }
        cout << endl;
    }
}

int main()
{

    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char *palabras[60];

    int n = separar_palabras(texto, palabras);

    imprimir_grupo("===PALABRAS===", palabras, n);
    cout << endl;

    cout << "===CADENA ORIGINAL===\n";
    cout << texto << endl;

    return 0;
}