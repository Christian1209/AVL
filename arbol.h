#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

class Arbol
{
    public:
        Arbol();
        void insertar(Nodo *&,Nodo *&,int);
        void mostrar(Nodo *,int);
        void inorden(Nodo *);
        void preorden(Nodo *);
        void postorden(Nodo *);
        void buscar(int e);
        void rotacionder(Nodo *);
        void rotacionizq(Nodo *);
        Nodo *raiz;
    private:
};

#endif // ARBOL_H
