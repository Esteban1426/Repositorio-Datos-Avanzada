#include <iostream>
#include <conio.h>

using namespace std;

int Busqueda(int arreglo[], int tamaño, int valor) 
{
    int principio = 0;
    int final = tamaño - 1;

    while (principio <= final) {
        int centro = principio + (final - principio) / 2;
        
        if (arreglo[centro] == valor) {
            return centro;
        } else if (arreglo[centro] < valor) {
            principio = centro + 1;
        } else {
            final = centro - 1;
        }
    }
    
    return -1;
}

int main() 
{
    int numeroUsuario; 
    cout<<"Ingrese el numero que desees del 1 al  30 : ";
    cin>>numeroUsuario;

    if(numeroUsuario >= 1 && numeroUsuario <= 30)
    {
        int array1[]= {1,2,3,4,5,6,7,8,9,10};
        int array2[]= {11,12,13,14,15,16,17,18,19,20};
        int array3[]= {21,22,23,24,25,26,27,28,29,30};
        int tamañoArray1= sizeof(array1) / sizeof(array1[0]);
        int tamañoArray2= sizeof(array2) / sizeof(array2[0]);
        int tamañoArray3= sizeof(array3) / sizeof(array3[0]);

        int posicionA1 = Busqueda(array1, tamañoArray1,numeroUsuario);
        int posicionA2 = Busqueda(array2, tamañoArray2,numeroUsuario);
        int posicionA3 = Busqueda(array3, tamañoArray3,numeroUsuario);

        if (posicionA1 != -1) 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " Ha sido encontrado en el array 1 en la posicion " << posicionA1 <<endl;
            cout<< "El espacio en la memoria reservado para el numero es: "<< &posicionA1 <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        } 
        else 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " no encontrado en el array 1" <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        }

        if (posicionA2 != -1) 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " Ha sido encontrado en el array 2 en la posicion " << posicionA2 <<endl;
            cout<< "El espacio en la memoria reservado para el numero es: "<< &posicionA2 <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        } 
        else 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " no encontrado en el array 2" <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        }   

        if (posicionA3 != -1) 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " Ha sido encontrado en el array 3 en la posicion " << posicionA3 <<endl;
            cout<< "El espacio en la memoria reservado para el numero es: "<< &posicionA3 <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        } 
        else 
        {
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
            cout<< "El numero: " << numeroUsuario << " no encontrado en el array 3" <<endl;
            cout<< "--------------------------------------------------------------------------------------------------"<<endl;
        }
            
    }  
    else
    {
        cout<< "El numero: " << numeroUsuario << " No esta dentro de la cantidad especificada al inicio"<<endl;
    }
    getch();
    system("pause");
    return 0;
    
}
