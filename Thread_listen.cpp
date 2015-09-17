/* 
 * File:   Thread_listen.cpp
 * Author: osboxes
 * 
 * Created on 12 September 2015, 22:56
 */

#include "Thread_listen.h"

using namespace std;

/**
 * contructor que inicializa la clase, establece el 
 * sockfd por donde se comunica con el cliente, y 
 * pasa al metodo de interaccion contra el cliente, 
 * para empezar a escuchar los mensajes.
 * @param sockfd dato tipo entero, es el dato del
 * identificador del cliente.
 */
Thread_listen::Thread_listen(int sockfd) {
    this->_newsockfd= sockfd;
    this->_n=cero;
    interactuar();
}

/**
 * destutor de la clase
 */
Thread_listen::~Thread_listen() {
    
}

/**
 * intrectua para escuchar los mensajes del cliente y atender
 * sus pedidos.
 */
void Thread_listen::interactuar() {
    while(true){
        bzero(_buffer,DosCientaSeis);
        //linea para leer mensajes.
        _n = read(_newsockfd,_buffer,DosCientaSeis-uno);
        if(_buffer==salir)
            break;
        if (_n < cero) 
            error(error5);
        if(_debug)
            printf("Here is the message: %s",_buffer);
        if(_buffer)
            _n=send(_newsockfd, "Hello, world!", getLenght("Hello, world!"), cero);
        //linea para enviar datos.
        if (_n < cero) 
            error(error6);
    }
    close(_newsockfd);
}

/**
 * recibe un mensaje para hacerle un pedido al cliente.
 * @param msg dato tipo char* que es el mensaje que se
 * le envia al cliente.
 */
void Thread_listen::enviarMsg(const char* msg) {
    _n=send(_newsockfd, msg,getLenght(msg), cero);
}

/**
 * metodo para imprimir el pantalla los errores 
 * que se presenten durante la ejecucion del servidor.
 * @param msg dato tipo "const char*" este es un string 
 * que indica el error.
 */
void Thread_listen::error(const char* msg) {
    perror(msg);
    exit(uno);
}
