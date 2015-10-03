/* 
 * File:   dataBase.cpp
 * Author: osboxes
 * 
 * Created on 15 September 2015, 23:27
 */

#include "dataBase.h"

/**
 * contructor que inicializa la clase, recibe la cantidad de memoria 
 * con la que se quiera inicializar la memoria.
 * @param pSize dato tipo entero, es la cantidad de memoria con la que 
 * se quiere empezar a trabajar.
 */
dataBase::dataBase(int pSize) {
    _leftMem=pSize;
    _pointer= calloc(uno,_leftMem);
    _first=_pointer;
}

/**
 * destructor de la clase.
 */
dataBase::~dataBase() {
    free(_pointer);
}

/**
 * metodo que varifica si se puede hacer un calloc. basicamente verifica si 
 * hay suficiente memoria como para alojar los datos.
 * @param pSize dato tipo entero, dato que es la cantidad de memoria queremos 
 * guardar.
 * @return retorna una d_status. un 0 si todo, esta bien y un 1 de que hay una
 * insuficiencia de memoria.
 */
int dataBase::d_calloc(int pSize) {
    if(pSize<=_leftMem)
        return d_status(cero);
    return d_status(uno);
}

/**
 * metodo que nos indica si se puedo hacer las operaciones en memoria.
 * @param mensaje dato tipo entero, es el mensaje de error u aceptacion 
 * de la operacion que hicimos.
 * @return retorna tres valores, un cero si todo esta bien, un 1 si hay 
 * insuficiencia de memoria y un 2 si se esta accediendo a memoria no permitida.
 */
int dataBase::d_status(int mensaje) {
    if(mensaje==cero)
        return cero;
    else if(mensaje==uno)
        return uno;
    return dos;
}

/**
 * metodo que retorna el puntero del espacio de memoria pedido para enviarlo
 * por medio del socket.
 * @param mensaje dato tipo entero, es el lugar en donde se ubica el mensaje
 * que queremos enviar.
 * @return retorna un void*, este el puntero de donde se encuentra el primer
 * dato que queremos.
 */
void* dataBase::d_get(int mensaje) {
    int head=(intptr_t)_first;
    int tail=(intptr_t)(_pointer+_leftMem);
    if(head<=mensaje<=tail){
        return _first+mensaje;
    }
    //return d_status(dos);
    
}

/**
 * metodo que nos retorna el puntero para poder escribir sobre este, esto 
 * solo se usa sobre el socket.
 * @return retorna un void*, este el puntero, en el ultimo lugar donde lo 
 * dejamos para que pueda escribir.
 */
void* dataBase::getPointer() {
    return _pointer;
}

/**
 * metodo que libera la memoria que se le indique.
 * @param mensaje dato tipo entero que nos indica en que posicion de 
 * la memoria se encuentra el dato que buscamos.
 * @param pSize dato tipo entero, que nos indica cuanta memoria queremos 
 * liberar.
 * @return retorna un d_status; un 0 si todo esta bien y un 2 si esta 
 * accediendo a memoria que no le pertenece.
 */
int dataBase::d_free(int mensaje, int pSize) {
    /**if(abs(_pointer-_leftMem)<=mensaje<=(_pointer+_leftMem)){
        //do_something;
        //return d_satus(cero);
    }*/
    return d_status(dos);
}

/**
 * metodo que aumenta el puntero en uno cuando se le termina de utilizar.
 */
void dataBase::sumPointer() {
    _pointer += 1;
}
