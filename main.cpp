#include <iostream>
#include "Nodo.h"
#include "Arbol.h"

using namespace std;

int main()
{
    int op,e;
    Arbol *uno = new Arbol();
    do {
    cout<<"Bienvenido a Arbol binario de Busqueda" <<endl<<"Elige una opcion!"<<endl;
    cout<<"1.-)Insertar elementos\n2.-)Mostrar arbol\n3.-)Mostrar Inorden\n4.-)Mostrar preorden.\n5.-Mostrar postorden\n10.-)salir"<<endl;
    cin>>op;
    switch(op){
        case 1:{
                    system("cls");
            cout<<"Escogiste insertar!, ingresa el elemento a insertar"<<endl;
            cin>>e;
            Nodo *pa = new Nodo();
            //MANDO UN NODO NULL PARA QUE SEA EL PADRE DE LA RAIZ.
            uno->insertar(uno->raiz,pa,e);
            break;
            }
        case 2:{
                    system("cls");
            cout<<"Escogiste Mostrar!, Mostrando arbol..."<<endl;
            int c=0;
            uno->mostrar(uno->raiz,c);
            break;
                }
        case 3:
                    system("cls");
            cout<<"Escogiste Inorden!, Mostrando..."<<endl;
            uno->inorden(uno->raiz);
            break;
        case 4:
                    system("cls");
            cout<<"Escogiste Preorden!, Mostrando..."<<endl;
            uno->preorden(uno->raiz);
            break;
        case 5:
                    system("cls");
            cout<<"Escogiste Post!, Mostrando..."<<endl;
            uno->postorden(uno->raiz);
            break;
               }
    }while(op!=10);

}
