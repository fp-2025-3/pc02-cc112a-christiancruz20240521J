#include <iostream>
#include <cstring>
using namespace std;

struct producto {
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

producto CrearProducto(int codigo, const char* nombre, double precio, int stock){
    producto p;

    p.codigo = codigo;
    p.precio = precio;
    p.stock = stock;

    p.nombre = new char[strlen(nombre) + 1];
    strcpy(p.nombre, nombre);

    return p;
}

producto* CrearInventario(int n){

    producto* inventario = new producto[n];

    return inventario;

}

producto* BuscarProducto(producto* inventario, int n, int codBuscado){
    for(int i = 0; i < n; i++){
        if((inventario + i)->codigo == codBuscado){
            return (inventario + i);
        }
    }

    return nullptr;
}

void liberarInventario(producto* inventario, int n){

    for(int i = 0; i < n; i++){
        delete[] (inventario + i)->nombre;
    }

    delete[] inventario;
}

void mostrar(producto* inventario, int n){
    for(int i = 0; i < n; i++){
        cout << "Codigo: " << (inventario + i)->codigo << " | "
             << "Nombre: " << (inventario + i)->nombre << " | "
             << "Precio: " << (inventario + i)->precio << " | "
             << "Stock: " << (inventario + i)->stock << endl;
    }

}

int main(){

    int n = 5;

    producto* inventario = CrearInventario(n);

    inventario[0] = CrearProducto(100, "teclado", 10.5, 5);
    inventario[1] = CrearProducto(101, "mouse", 21, 10);
    inventario[2] = CrearProducto(102, "monitor", 31.5, 15);
    inventario[3] = CrearProducto(103, "laptop", 42, 20);
    inventario[4] = CrearProducto(104, "impresora", 52.5, 25);

    cout << "========== INVENTARIO ===========\n";
    mostrar(inventario, n); 

    cout << "\nBuscando producto con codigo 102 ...\n";
    
    producto* p = BuscarProducto(inventario, n, 102);

    if(p != nullptr){
        cout << "Producto encontrado: " << p->nombre << " | "
             << "Precio " << p->precio << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    liberarInventario(inventario, n);

    return 0;
}