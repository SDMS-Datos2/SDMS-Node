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
#include "Constantes.h"

class Thread_listen :public Constantes{
public:
    Thread_listen(int sockfd);
    virtual ~Thread_listen();
    void enviarMsg(const char* msg);
private:
    int _newsockfd;
    char _buffer[DosCientaSeis];
    int _n;
    void interactuar();
    void error(const char* msg);
};

#endif	/* THREAD_LISTEN_H */

