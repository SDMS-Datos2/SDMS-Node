/* 
 * File:   lista.h
 * Author: osboxes
 *
 * Created on 23 July 2015, 11:32
 */

#ifndef LISTA_H
#define	LISTA_H
#include "nodo.h"
#include "Constantes.h"
/**
 * clase para crear listas simples, por ahortia solo 
 * funciona con ints
 */
class lista :public Constantes{
    public:
        lista();
        virtual ~lista();
        void insert(int pDato);
        void borrar(int pDato);
        int getLenght();
        nodo* getHead();
        nodo* getTail();
        nodo* find(int pDato);
        void print();
    private:
        nodo* _head;
        nodo* _tail;
        int _largo;
};

#endif	/* LISTA_H */

