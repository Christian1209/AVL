#include "Arbol.h"
#include "Nodo.h"
#include <iostream>
using namespace std;

void Arbol::rotacionder(Nodo *actual){
        Nodo *b = new Nodo();
        b=actual->izq;
    if((b->peso)==-1){
        //Se hace rotación simple hacia derecha
        //cout<<"Rotación simple derecha"<<endl;
        //necesitamos saber si el nodo que vamos a mover tiene un nodo padre.
        if(actual->padre->padre!=nullptr){
                //cout<<actual->dato<<endl;
                //ahora necesitamos saber si es hijo por la parte derecha o izquierda
            if((actual->padre->dato)>(actual->dato)){
                //aqui, el padre es mayor por lo tanto es hijo izquierdo
                b->padre=actual->padre;
                actual->padre->izq=b;
            }
            else{
                //aqui, padre es menor por lo tanto es hijo por derecha.
                b->padre=actual->padre;
                actual->padre->der=b;
            }
        }
        else{
               //si el nodo no tiene pade, es raiz y hay qeu moverla.
            b->padre=actual->padre;
            raiz=b;
        }
        if(b->der!=nullptr){
               //si B osea el hijo del nodo que va a rotar, tiene hijo derecho hay que pasarlo a la parte izquierda del nodo a rotar.
            //cout<<"b si tenia algo en su parte derecha.";
            b->der->padre=actual;
            actual->izq=b->der;
            actual->peso=0;
        }
        else{
            actual->izq=nullptr;
        //si no, el nodo a rotar es nulo.
            actual->peso=1;
        }
        b->der=actual;
        //Equilibrio de pesos.
        b->peso=0;
    }
    else if(b->peso=1){
        //Se hace rotacion doble a derecha.s
        Nodo *c = new Nodo();
        c=b->der;
        if(c->der==nullptr){
            //cout<<"LLEGUE!"<<endl;
            actual->izq=c;
            c->izq=b;
            b->izq=nullptr;
            b->der=nullptr;
            b->peso=0;
            c->peso=-1;
            actual->peso=-2;
            b->padre=c;
            c->padre=actual;

            rotacionder(actual);
        }
        else{
            //cout<<"C si tiene hijo!!!"<<endl;
            actual->izq=c;
            c->padre=actual;
            c->izq=b;
            b->padre=c;
            b->der=nullptr;
            c->peso=-1;
            b->peso=-1;
            actual->peso=-2;
            rotacionder(actual);
        }
        //cout<<"rotacion doble a derecha"<<endl;
    }

}

void Arbol::rotacionizq(Nodo *actual){
        Nodo *b = new Nodo();
        b=actual->der;
    if((b->peso)==(1)){
        //Se hace rotación simple hacia izq
        //cout<<"Rotación simple hacia izq"<<endl;
        //necesitamos saber si el nodo que vamos a mover tiene un nodo padre.
        if(actual->padre->padre!=nullptr){
                //cout<<"Entre aqui!";
                //cout<<actual->dato<<endl;
                //ahora necesitamos saber si es hijo por la parte derecha o izquierda
            if((actual->padre->dato)>(actual->dato)){
                //aqui, el padre es mayor por lo tanto es hijo izquierdo
                //cout<<"aqui";
                b->padre=actual->padre;
                actual->padre->izq=b;
            }
            else{
                //aqui, padre es menor por lo tanto es hijo por derecha.
                b->padre=actual->padre;
                actual->padre->der=b;
            }
        }
        else{
               //si el nodo no tiene pade, es raiz y hay qeu moverla.
            b->padre=actual->padre;
            raiz=b;
        }
        if(b->izq!=nullptr){
               //si B osea el hijo del nodo que va a rotar, tiene hijo izquierdo hay que pasarlo a la parte izquierda del nodo a rotar.
            //cout<<"b si tenia algo en su parte izquierda.";
            b->izq->padre=actual;
            actual->der=b->izq;
            //si habia algo, queda con peso 0.
            actual->peso=0;
        }
        else{
            actual->der=nullptr;
            actual->peso=-1;
        //si no, el nodo a rotar es nulo.
        }
        b->izq=actual;
        //Equilibrio de pesos.
        b->peso=0;
        }
    else if((b->peso)==(-1)){
        //cout<<"LLEGUE";
        //Se hace rotacion doble hacia izquierda.
        Nodo *c = new Nodo();
        c=b->izq;
        if(c->izq==nullptr){
            //cout<<"C no tiene hijo"<<endl;
            //se hace rotacion simple y no hay nodos que reubicar.
            actual->der=c;
            c->der=b;
            b->der=nullptr;
            b->izq=nullptr;
            b->peso=0;
            c->peso=1;
            actual->peso=2;
            b->padre=c;
            c->padre=actual;
            rotacionizq(actual);
        }
        else{
            //cout<<"C si tiene hijo!!!"<<endl;
            actual->der=c;
            c->padre=actual;
            c->der=b;
            b->padre=c;
            b->izq=nullptr;
            c->peso=1;
            b->peso=1;
            actual->peso=2;
            rotacionizq(actual);
        }
        cout<<"rotacion doble a derecha"<<endl;
    }
}

void Arbol::insertar(Nodo *&actual,Nodo *&papa,int e){
    if(actual==nullptr){
        if(papa->izq!=nullptr||papa->der!=nullptr){
            //cout<<"ESE NIVEL YA EXISTIA, ESTAMOS AÑADIENDO UN HERMANO."<<endl;
            Nodo *aux = new Nodo();
            aux=papa->padre;;
            while (aux){
                    //cout<<"Dato a evaluar: "<<aux->dato<<endl;
                if((aux->dato)>(e)){
                    aux->peso=aux->peso+1;
                }
                else{
                    aux->peso=aux->peso-1;
                }
                aux=aux->padre;
            }
        }
        Nodo *tmp = new Nodo();
        tmp->dato=e;
        actual=tmp;
        actual->padre=papa;
        if(raiz==nullptr){
            raiz=actual;
        }
        return;
    }
    else{
        int vraiz=actual->dato;
        if(e<vraiz){
            actual->peso=(actual->peso-1);
            insertar(actual->izq,actual,e);
        }
        else{
            actual->peso=(actual->peso+1);
            insertar(actual->der,actual,e);
        }
    }
    if(actual->peso==2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a la derecha."<<endl;
        rotacionizq(actual);
        //ajuste de Nodos.
        while (aux){
            //cout<<"Dato a evaluar: "<<aux->dato<<endl;
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
    if(actual->peso==-2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a izquierda."<<endl;
        rotacionder(actual);
        //si hay rotacion, ajustamos nodos
        while (aux){
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
}

void Arbol::mostrar(Nodo *actual,int cont){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        mostrar(actual->der,cont+1);{
            for(int i=0;i<cont;i++){
                cout<<"   ";
            }
            cout<<actual->dato<<endl;
            mostrar(actual->izq,cont+1);
        }
    }
 }

void Arbol::inorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        inorden(actual->izq);
        cout<<"  "<<actual->dato<<")";
        inorden(actual->der);
    }
 }

void Arbol::preorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        cout<<actual->dato<<")";
        preorden(actual->izq);
        preorden(actual->der);
    }
 }

 void Arbol::postorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        postorden(actual->izq);
        postorden   (actual->der);
        cout<<actual->dato<<")";
    }
 }


Arbol::Arbol()
{
    raiz=nullptr;
}
