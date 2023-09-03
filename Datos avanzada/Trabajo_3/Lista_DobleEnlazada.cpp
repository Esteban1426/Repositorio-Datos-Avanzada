#include <iostream>

using namespace std;

int numeroNodos;

struct nodo
{
    int num;
    nodo*izq;
    nodo*dere;
};

nodo * cabeza = nullptr;
nodo * cola = nullptr;
    
    void Insertar(int valor)
    {
        nodo * nuevo = new nodo();
        nuevo -> num = valor;
        nuevo -> izq = nullptr;
        nuevo -> dere = nullptr;

        if (cabeza == nullptr)
        {
            cabeza = nuevo;
            cola = nuevo;
        }
        else
        {
            nuevo -> izq = cola;
            cola -> dere = nuevo;
            cola = nuevo;
        }
        numeroNodos++;
        
    }

    void Busqueda(int valor)
    {   
        int posicion = 1;
        bool encontrado = false;

        if(!cabeza)
        {
            cout << "La lista esta vacia tienes que ingresar priemro valores" <<endl;
            return;
        }

        nodo * actual = cabeza;
         
        do
        {
            if(actual -> num == valor)
            {
                cout<<"El numero "<< valor <<" se encuentra en el nodo "<< posicion << " y su direccion de memoria es: "<< actual <<endl;
                encontrado = true;    
            }

            actual = actual -> dere;
            posicion ++;

        }while(actual != nullptr);

        if (!encontrado)
        {
            cout << "Numero no encontrado" << endl;   
        }
        
    }

    void Actualizar (int posicion, int nuevoValor)
    {
        if (!cabeza)
        {   
            cout << "La lista esta vacia tienes que ingresar priemro valores" << endl;
            return;
        }

        nodo * actual = cabeza;
        int contador = 1;

        do
        {
            if (contador == posicion)
            {
                actual -> num = nuevoValor;
                cout << "El valor del nodo numero "<< posicion << " se actualizo a este valor: "<< nuevoValor << endl;
                return;            
            }
            actual = actual -> dere;
            contador++;
            
        }while (actual != nullptr);
        
        cout << "Posicion invalida" << endl;
        
    } 

    void Borrar(int posicion)
    {
        if(!cabeza)
        {
            cout << "La lista esta vacia tienes que ingresar priemro valores" << endl;
            return;
        }

        if (posicion == 1)
        {
            nodo * borrar = cabeza;
            cabeza = cabeza -> dere;
            if (cabeza)
            {
                cabeza -> izq = nullptr;
            }
            delete borrar;
            numeroNodos --;
            cout << "El nodo de la posicion "<< posicion << " Ha sido borrado correctamente" << endl;
            return; 
        }

        nodo * actual = cabeza;

        int contador = 1;

        do
        {
            if (contador == posicion)
            {
                nodo * borrar = actual;
                if (actual -> dere)
                {
                    actual -> dere -> izq = actual -> izq;
                }

                if (actual -> izq)
                {
                    actual -> izq -> dere = actual -> dere;
                }
                
                delete borrar;
                numeroNodos --;
                cout << "El nodo de la posicion "<< posicion << " Ha sido borrado correctamente" << endl;
                return;
            }
            actual = actual-> dere;
            contador++;

        }while(actual != nullptr);

        cout << "La posicion ingresada es invalida" << endl;
    }
    
    void mostrar()
    {
        int contador = 1;
        if(!cabeza)
        {
            cout << "La lista esta vacia tienes que ingresar priemro valores" << endl;
            return;
        }

        nodo * actual= cabeza;
        do
        {
            cout << "Nodo numero "<< contador << " :" <<actual->num << " "<< endl;
            actual = actual -> dere;
            contador++;
        } while (actual != nullptr);
        
    }

    void mostrarInversa()
    {
        int contador = numeroNodos;
        if(!cola)
        {
            cout << "La lista esta vacia tienes que ingresar priemro valores" << endl;
            return;
        }

        nodo * actual= cola;
        do
        {
            cout << "Nodo numero "<< contador << " :" <<actual->num << " "<< endl;
            actual = actual -> izq;
            contador--;
        } while (actual != nullptr);
    }

int main()
{
    int opcion;
    char continuar = 'y';
    do
    {
        cout << " Ingresa el numero correspondiente a la opcion que desees: "<<endl;
        cout << " 1. Ingresar valores a los nodos "<<endl << " 2. Busqueda de valores " <<endl << " 3. Actualizar el valor de un nodo "<< endl << " 4. Borrar un nodo "<< endl << " 5. Mostrar la lista actual y Mostrar la lista actual inversa "<< endl << " 6. Salir del programa "<< endl;
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
                        Insertar(valor);
                    }

                } while (valor != 0);

                cout << "Lista Doblemente Enlazada: " << endl;
                mostrar();
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "Lista Doblemente Enlazada Inversa: " << endl;
                mostrarInversa();

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;
         
                break;
            }

            case 2: 
            {
                int numeroBuscar;
                cout <<"Digite el valor que desea buscar: " << endl << "Respuesta: ";
                cin >> numeroBuscar;

                Busqueda(numeroBuscar);

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;

                break;
            }

            case 3: 
            {
                int posicion;
                int nuevoValor;

                cout << "Digita la posicion del nodo en la que quieres cambiar el valor: " << endl << "Respuesta: ";
                cin>> posicion;

                cout << "Digita el valor nuevo para el nodo: " << endl << "Respuesta: ";
                cin>> nuevoValor;

                Actualizar(posicion, nuevoValor);

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;
                break;
            }

            case 4: 
            {
                int posicion;
                cout << " Ingresa la posicion del nodo que quieres eliminar: " << endl << "Respuesta: ";
                cin >> posicion;

                Borrar(posicion);
                cout << "Lista Actual: " <<endl;
                mostrar();
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "Esta es la lista Actual inversa" << endl;
                mostrarInversa();

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;

                break;
            }

            case 5: 
            {
                cout << "Esta es la lista Actual: " << endl;
                mostrar();
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "Esta es la lista Actual inversa" << endl;
                mostrarInversa();

                cout << "Deseas Continuar con el programa( y / n ) en minusculas: " <<endl;
                cin >>continuar;

                break;
            }

            case 6: 
            {
                cout << " Vale, Saliendo... " << endl;
                break;
            }

            default:
            {
                cout <<"Opcion no valida";
                break;
            }
        }
    }while(continuar != 'n' && opcion != 6);

    nodo * actual = cabeza;
    while (actual != nullptr)
    {
        nodo * dere = actual -> dere;
        delete actual;
        actual = dere; 
    }
    
    cout << " Fin..";
    return 0;
}