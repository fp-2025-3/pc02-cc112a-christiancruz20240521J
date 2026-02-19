#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    char* descripcion;
    int cantidad;
    double PrecioUnitario;
};

struct Pedido{
    int NumPedido;
    char* nomCliente;
    Item* items;
    int cantItems;
};

Item CrearItem(const char* descripcion, int cantidad, double precio){
    Item it;

    it.cantidad = cantidad;
    it.PrecioUnitario = precio;

    it.descripcion = new char[strlen(descripcion) + 1];
    strcpy(it.descripcion, descripcion);

    return it;
}

Pedido* crearPedido(int numero, const char* cliente, int cantItems){
   Pedido* p = new Pedido;

   p->NumPedido = numero;
   p->cantItems = cantItems;

   p->nomCliente = new char[strlen(cliente) + 1];
   strcpy(p->nomCliente, cliente);

   p->items = new Item[cantItems];

   return p;
}

double CalcularTotal(const Pedido* p){
    double total = 0;

    for(int i = 0; i < p->cantItems; i++){
        total += (p->items + i)->cantidad * (p->items + i)->PrecioUnitario;
    }

    return total;
}

Item* itemMasCaro(Pedido *p){
    Item* mayor = &p->items[0];

    for(int i = 1; i < p->cantItems; i++){
        if((p->items + i)->PrecioUnitario > mayor->PrecioUnitario){
            mayor = &p->items[i];
        }
    }

    return mayor;
}

void liberarPedido(Pedido* p){
    for(int i = 0; i < p->cantItems; i++){
        delete[] (p->items + i)->descripcion;
    }

    delete[] p->items;
    delete[] p->nomCliente;
    delete p;
}

int main(){
    int n = 3;

    Pedido* pedido = crearPedido(101, "Carlos Perez", n);

    pedido->items[0] = CrearItem("laptop", 1, 100);
    pedido->items[1] = CrearItem("mouse", 2, 200);
    pedido->items[2] = CrearItem("teclado", 3, 300);

    cout << "Pedido N°: " << pedido->NumPedido << endl;
    cout << "Cliente: " << pedido->nomCliente << endl;

    cout << "\nItems:\n";
    for(int i = 0; i < pedido->cantItems; i++){
        cout << (pedido->items + i)->descripcion << " | "
             << "Cant: " << (pedido->items + i)->cantidad << " | "
             << "Precio: " << (pedido->items + i)->PrecioUnitario << endl;
    }

    double total = CalcularTotal(pedido);
    cout << "\nTotal: " << total << endl;

    Item* caro = itemMasCaro(pedido);
    cout  << "Item mas caro: " << caro->descripcion << " | "
          << "Precio: " << caro->PrecioUnitario << endl;

    liberarPedido(pedido);

    return 0;
}