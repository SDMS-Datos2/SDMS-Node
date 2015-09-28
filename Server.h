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
#include "MemHandler.h"
#include "Constantes.h"

class Server :public Constantes{
public:
    Server(char* ServerName);
    virtual ~Server();
private:
    int _sockfd, _newsockfd, _portno, _n, _codigos;
    socklen_t _clilen;
    char _buffer[DosCientaSeis];
    char* _id;
    MemHandler *_hilo;
    struct sockaddr_in _serv_addr, _cli_addr;
    void interact(int newsockfd);
    void error(const char* msg);
    int decodeMsg(int dato);
};

#endif	/* SERVER_H */

