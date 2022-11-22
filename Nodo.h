#ifndef NODO_H
#define NODO_H


class Nodo
{
    public:
        Nodo();
        ~Nodo();
        int dato;
        int peso;
        Nodo *padre;
        //bool hermano para que si el nodo ya tenia un hijo, el nivel no aumente.
        Nodo *izq;
        Nodo *der;
    private:
};

#endif // NODO_H

