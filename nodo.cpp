/* 
 * File:   nodo.cpp
 * Author: osboxes
 * 
 * Created on 23 July 2015, 11:32
 */

#include <stddef.h>
#include <iostream>
#include "nodo.h"
using namespace std;

/**
 * contructor vacio que inicializa el valor de las 
 * variables utilizadas en el nodo.
 */
nodo::nodo() {
    _size=0,_space=0;
    _next= NULL;
}
/**
 * constructor que establece el valor interno del nodo
 * @param pDato recibe un dato tipo entero.
 */

nodo::nodo(int pSpace) {
    this->_space=pSpace;
    this->_next=NULL;
}


/**
 * destructor.
 */
nodo::~nodo() {

}

/**
 * metodo para establecer el espacio del nodo.
 * @param pSize dato tipo entero, dato que es el tamaño del nodo.
 */
void nodo::setSize(int pSize) {
    this->_size=pSize;
}


/**
 * metodo para establecer el siguiente nodo del que estamos
 * usando 
 * @param pNodo dato tipo nodo, este va a ser el puntero del 
 * nodo.
 */
void nodo::setNext(nodo* pNodo) {
    this->_next=pNodo;
}
/**
 * metodo para devolver el dato interno del nodo.
 * @return retorna un dato tipo entero.
 */
int nodo::getSize() {
    return this->_size;
}

/**
 * metodo que retorna el espacio del dato que esta contenido en el nodo.
 * @return retorna un dato tipo entero.
 */
int nodo::getSpace() {
    return this->_space;
}

/**
 * metodo para obtener el nodo siguiente al nodo
 * con que operamos.
 * @return retorna un apuntador del nodo.
 */
nodo* nodo::getNext() {
    return _next;
}
