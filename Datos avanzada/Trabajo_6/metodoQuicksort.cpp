#include <iostream>

using namespace std;

void quicksort (int* arreglo, int izquierda, int derecha){
    int i = izquierda; int j = derecha; /*RASTREAR POSICIONES DEL ARREGLO*/
    int temporal; 
    int pivote = arreglo[(izquierda + derecha) /2]; /*DIVIDIR ARREGLO*/

    /*CAMBIOS DE POSICION HASTA LLEGAR AL PIVOTE*/
    while (arreglo[i] < pivote) i++;
    while (arreglo[j] > pivote) j--;

        if (i <= j) {
            /*INTERCAMBIO DE POSICIONES EN CIRCULO*/
            temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
            i++; j--;
        }

        if (izquierda < j){
            quicksort (arreglo, izquierda, j); /*ORDERNAR VECES NECESARIAS SUBSECCION IZQUIERDA*/
        }
        if (i < derecha){
            quicksort (arreglo, i, derecha); /*ORDERNAR VECES NECESARIAS SUBSECCION DERECHA*/
        }  
}

int main(){
    cout<<"METODO QUICKSORT: \n";
    cout<<"LISTA ORIGINAL: \n";
    cout<<"42, 17, 8, 63, 29, 55, 12, 37, 6, 91, 50, 3, 77, 22, 14, 68, 45, 11, 90, 5\n";
    cout<<"LISTA ORDENADA: \n";
    int arr[20] = {42, 17, 8, 63, 29, 55, 12, 37, 6, 91, 50, 3, 77, 22, 14, 68, 45, 11, 90, 5};

    quicksort(arr, 0, 19);

    for (int i = 0; i < 20; i++)
    {
        cout<< arr[i] <<" ";
    }
    system("pause");
    return 0;
}