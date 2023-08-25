#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo 
{
    int dato;
    Nodo* siguiente;
};

int main() 
{
    int num;
    int contador = 1;
    cout<< "Ingresa el numero de nodos que deseas ver entre 1 y 5: "<<endl;
    cin >> num;


    Nodo * nodo_uno = new Nodo;
    Nodo * nodo_dos = new Nodo;
    Nodo * nodo_tres = new Nodo;
    Nodo * nodo_cuatro = new Nodo;
    Nodo * nodo_cinco = new Nodo;

    nodo_uno->dato= 2;
    nodo_uno->siguiente = nodo_dos;

    nodo_dos->dato= 4;
    nodo_dos->siguiente = nodo_tres;

    nodo_tres->dato= 6;
    nodo_tres->siguiente = nodo_cuatro;

    nodo_cuatro->dato= 8;
    nodo_cuatro->siguiente = nodo_cinco;

    nodo_cinco->dato= 10;
    nodo_cinco->siguiente = nodo_uno;


    Nodo * actual = nodo_uno;   

    do
    {
        cout << "Nodo "<< contador << " Valor: "<< actual->dato << " "<<endl;
        actual = actual->siguiente;
        contador++;
    }
    while (actual != nodo_uno && contador <= num);

    getch();
    system("pause");
    return 0;

}