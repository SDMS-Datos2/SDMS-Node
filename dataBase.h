/* 
 * File:   dataBase.h
 * Author: osboxes
 *
 * Created on 15 September 2015, 23:27
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include <stdlib.h>
#include <stdint.h>
#include <ios>
#include "Constantes.h"
#include "lista.h"

/**
 * clase que es que la que va a controlar las operaciones en memoria y 
 * demas operaciones.
 */
class dataBase :public Constantes{
public:
    dataBase(int pSize);
    int d_calloc(int pSize);
    void d_set(int pSize);
    void* d_get(int mensaje,int pSize);
    int d_free(int mensaje,int pSize);
    void * getPointer();
    void sumPointer();
    virtual ~dataBase();
private:
    void * _pointer, *_first;
    lista * _list;
    int _leftMem;
    int d_status(int mensaje);
};

#endif	/* DATABASE_H */

