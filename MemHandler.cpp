/* 
 * File:   Thread_listen.cpp
 * Author: osboxes
 * 
 * Created on 12 September 2015, 22:56
 */

#include "MemHandler.h"

using namespace std;
/**
 * contructor que inicializa la clase, establece el 
 * sockfd por donde se comunica con el cliente, y 
 * pasa al metodo de interaccion contra el cliente, 
 * para empezar a escuchar los mensajes.
 * @param sockfd dato tipo entero, es el dato del
 * identificador del cliente.
 */
MemHandler::MemHandler(int sockfd) {
    _heap= new dataBase(QuinDoce);
    this->_sockfd= sockfd;
    this->_n=cero;
    interactuar();
}

/**
 * destutor de la clase
 */
MemHandler::~MemHandler() {

}

/**
 * intrectua para escuchar los mensajes del cliente y atender
 * sus pedidos.
 */
void MemHandler::interactuar() {
    while(true){
        int datos=0;
        //linea para leer mensajes.
        _n = read(_sockfd,&datos,sizeof(int));
        if (_n < cero) 
            error(error5);
        _n= decodeMsg(datos);
        if(_debug)
            printf("Here is the message: %s",_buffer);
        _n=send(_sockfd, &_n, sizeof(int), cero);
        //linea para enviar datos.
        if (_n < cero) 
            error(error6);
    }
    close(_sockfd);
}

int MemHandler::decodeMsg(int dato) {
    if(dato==uno){
        _calloc();
    }else if(dato==dos){
        _get();
    }else if(dato==tres){
        _set();
    }else{
        _free();
    }
}

/**
 * metodo para imprimir el pantalla los errores 
 * que se presenten durante la ejecucion del servidor.
 * @param msg dato tipo "const char*" este es un string 
 * que indica el error.
 */
void MemHandler::error(const char* msg) {
    perror(msg);
    exit(uno);
}

int MemHandler::_calloc() {
    int n;
    int pSize=0;
    n = read(_sockfd,&pSize,sizeof(int));
    if (n < cero) 
        error(error5);
    _codigos=_heap->d_calloc(pSize);
    return _codigos;
}

void* MemHandler::_get() {
    int space,size,n;
    n = read(_sockfd,&space,sizeof(int));
    n = read(_sockfd,&size,sizeof(int));
    if (n < cero) 
        error(error5);
    void* pointer=(_heap->getPointer()+space);
    n=send(_sockfd, pointer,size,cero);
    if (n < cero) 
        error(error6);
    return pointer;
}

void MemHandler::_set() {
    int size,n;
    n = read(_sockfd,&size,sizeof(int));
    if (n < cero) 
        error(error5);
    n = read(_sockfd,_heap->getPointer(),size);
    if (n < cero) 
        error(error5);
}

int MemHandler::_free() {

}

