/* 
 * File:   nodo.h
 * Author: osboxes
 *
 * Created on 23 July 2015, 11:32
 */

#ifndef NODO_H
#define	NODO_H

class nodo {
    public:
        nodo();
        nodo(int pSpace);
        virtual ~nodo();
        void setSize(int pSize);
        void setNext(nodo* pNodo);
        int getSize();
        int getSpace();
        nodo* getNext();
    private:
        int _space,_size;
        nodo* _next;
};

#endif	/* NODO_H */

