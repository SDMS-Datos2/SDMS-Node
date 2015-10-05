/* 
 * File:   lista.cpp
 * Author: osboxes
 * 
 * Created on 23 July 2015, 11:32
 */

#include <stddef.h>
#include "lista.h"
#include "nodo.h"
#include <iostream>
using namespace std;

/**
 * contructor vacio que inicializa el valor de las 
 * variables utilizadas en la lista.
 */
lista::lista() {
    _head=_tail=NULL;
    _largo=cero;
}

/**
 * destructor
 */
lista::~lista() {
    if(_head==NULL){
        delete _head;
        delete _tail;
        _largo=cero;
    }
    else{
        nodo* tmp;
        for(int i=0; i<_largo;i++){
            tmp=_head->getNext();
            delete _head;
            _head=tmp;
        }
        delete _tail;

    }
}

/**
 * metodo para insertar datos a una lista simple
 * @param pDato recibe un dato tipo entero.
 */
void lista::insert(int pDato) {
    if(_head==NULL){
        _head=new nodo(pDato);
        _tail=_head;
    }
    else{
        nodo* tmp= _tail;
        _tail= new nodo(pDato);
        tmp->setNext(_tail);
    }
    _largo++;
}

/**
 * metodo para borrar un elemento de la lista
 * @param pDato recibe un entero del dato que se quiere
 * eliminar de la lista.
 */
void lista::borrar(int pDato) {
    nodo* tmp =_head;
    nodo* tmp2=tmp;
    int i=cero;
    for(; i<_largo;i++){
        if(tmp->getSize()==pDato)
            break;
        tmp2=tmp;
        tmp=tmp->getNext();
    }
    if(i==_largo)
        cout<<"no_encontrado"<<endl;
    else if (tmp2==tmp){
        _head=_head->getNext();
        delete tmp;
    }
    else{
        tmp2->setNext(tmp->getNext());
        delete tmp;
    }
}

/**
 * metodo para devolver la cabeza de la lista 
 * para realizar recorridos.
 * @return retorna un dato tipo nodo, este sera 
 * el puntero del nodo.
 */
nodo* lista::getHead() {
    return _head;
}

/**
 * metodo para devolver la cola de la lista 
 * para realizar recorridos.
 * @return retorna un dato tipo nodo, este sera 
 * el puntero del nodo.
 */
nodo* lista::getTail() {
    return _tail;
}

/**
 * metodo para realizar busquedas en una lista.
 * @param pDato recibe un dato tipo entero.
 * @return retorna un dato booleano confirmando
 * la existencia un dato.
 */
nodo* lista::find(int pDato) {
    nodo* tmp= _head;
    int i=cero;
    for(; i<_largo||tmp->getSize()==pDato; i++)
        tmp=tmp->getNext();
    if(i>_largo)
        return NULL;
    return tmp;
}

/**
 * metodo para devolver el largo de la lista.
 */
int lista::getLenght() {
    return _largo;
}

/**
 * metodo para imprimir todos los datos de la lista.
 */
void lista::print() {
    nodo* tmp=_head;
    for(int i =cero; i<_largo;i++){
        cout<<tmp->getSpace()<<endl;
        tmp=tmp->getNext();
    }
}




