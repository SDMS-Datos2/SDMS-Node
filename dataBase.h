/* 
 * File:   dataBase.h
 * Author: osboxes
 *
 * Created on 15 September 2015, 23:27
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include "Constantes.h"

class dataBase :public Constantes{
public:
    dataBase(int pSize);
    int d_calloc(int pSize);
    int d_set(void* mensaje,int pSize);
    int d_free(int mensaje,int pSize);
    int d_status(int mensaje);
    void * getPointer();
    virtual ~dataBase();
private:
    void * _pointer, *_first;
    int _leftMem;
};

#endif	/* DATABASE_H */

