/* 
 * File:   Thread_listen.h
 * Author: osboxes
 *
 * Created on 12 September 2015, 22:56
 */

#ifndef THREAD_LISTEN_H
#define	THREAD_LISTEN_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "dataBase.h"
#include "Constantes.h"

/**
 * clase que va a controla la memoria en terminos de recibir y devolver 
 * los datos que se le pidan o las operaciones que se le pidan realizar.
 */
class MemHandler :public Constantes{
public:
    MemHandler(int sockfd);
    virtual ~MemHandler();
    void interactuar();
private:
    int _sockfd,_codigos;
    char _buffer[DosCientaSeis];
    int _n;
    dataBase *_heap;
    int decodeMsg(int dato);
    int _calloc();
    void* _get();
    void _set();
    int _free();
    void error(const char* msg);
};

#endif	/* THREAD_LISTEN_H */

