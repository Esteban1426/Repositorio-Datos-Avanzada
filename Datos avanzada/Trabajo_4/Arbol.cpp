#include <iostream>

using namespace std;

struct nodo
{
    int numero;
    nodo * dere;
    nodo * izq;
};


nodo * insercion(nodo * raiz,int valor)
{
    if (raiz == nullptr)
    {
        nodo * nuevoNodo = new nodo;
        nuevoNodo -> numero = valor;
        nuevoNodo -> izq = nullptr;
        nuevoNodo -> dere = nullptr;
        return nuevoNodo;
    }
    
    if(valor < raiz -> numero)
    {
        raiz -> izq = insercion(raiz -> izq,valor);
    }
    else if (valor > raiz -> numero)
    {
        raiz -> dere = insercion(raiz -> dere,valor);
    }

    return raiz;
}


int main()
{
    int opcion;
    char continuar;
    nodo* raiz = nullptr;
    
    do
    {
        cout << " Ingresa el numero correspondiente a la opcion que desees: "<<endl;
        cout << " 1. Ingresar valores "<<endl << " 2. Salir programa "<< endl;
        cout << " Respuesta: "; 
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                int valor;

                do
                {
                    cout << "Ingrese un numero /*Nota: Si quieres salir ingresa numero 0*/ : "<< endl; 
                    cin >> valor;
                    
                    if(valor != 0)
                    {
                        raiz = insercion(raiz,valor);
                    }

                } while (valor != 0);

                cout << "Numeros Insertados correctamente. " << endl;

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;
         
                break;
            }
            case 2: 
            {
                continuar = 'n';
                cout << " Vale, Saliendo... " << endl;
                break;
            }

            default:
            {
                cout <<"Opcion no valida";
                break;
            }
        }
    }while(continuar != 'n' && opcion != 3);
}