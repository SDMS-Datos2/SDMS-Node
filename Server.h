/* 
 * File:   Server.h
 * Author: osboxes
 *
 * Created on 12 September 2015, 22:55
 */

#ifndef SERVER_H
#define	SERVER_H
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <arpa/inet.h>
#include "Thread_listen.h"
#include "Constantes.h"

class Server :public Constantes{
public:
    Server(int port);
    virtual ~Server();
private:
    int _sockfd, _newsockfd, _portno, _n, _pid;
    socklen_t _clilen;
    char _buffer[DosCientaSeis];
    struct sockaddr_in _serv_addr, _cli_addr;
    int _lenght;
    Thread_listen* _hilos;
    void interact(int newsockfd);
    void error(const char* msg);
    void growarray(int pActualLenght, Thread_listen* pHilos);
};

#endif	/* SERVER_H */

