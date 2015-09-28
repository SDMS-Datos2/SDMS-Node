/* 
 * File:   dataBase.cpp
 * Author: osboxes
 * 
 * Created on 15 September 2015, 23:27
 */

#include <stdlib.h>
#include <stdint.h>
#include <ios>
#include "dataBase.h"
/**
 * 
 */
dataBase::dataBase(int pSize) {
    _leftMem=pSize;
    _pointer= calloc(uno,_leftMem);
    _first=_pointer;
}

/**
 * 
 */
dataBase::~dataBase() {
    free(_pointer);
}

/**
 * 
 * @param pSize
 * @return 
 */
int dataBase::d_calloc(int pSize) {
    if(pSize<=_leftMem)
        return d_status(cero);
    return d_status(uno);
}

/**
 * 
 * @param mensaje
 * @param pSize
 * @return 
 */
int dataBase::d_free(int mensaje, int pSize) {
    /**if(abs(_pointer-_leftMem)<=mensaje<=(_pointer+_leftMem)){
        //do_something;
        //return d_satus(cero);
    }*/
    return d_status(dos);
}

/**
 * 
 * @param mensaje
 * @return 
 */
int dataBase::d_status(int mensaje) {
    if(mensaje==cero)
        return cero;
    else if(mensaje==uno)
        return uno;
    return dos;
}

void* dataBase::getPointer() {
    return _pointer;
}


