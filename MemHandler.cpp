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

/**
 * metodo que se utiliza para saber si lo que se pide un d_calloc,
 * d_get, d_set o un d_free.
 * @param dato recibe un dato entero que nos indica cual es la 
 * operacion pedida.
 * @return retorna un entero que nos indica si la operacion se pudo realizar,
 * un 0 indica que todo esta bien, 1 insuficiencia de memoria y un 2 que 
 * se esta accediendo a un lugar de memoria indevido.
 */
int MemHandler::decodeMsg(int dato) {
    int answ=0;
    if(dato==uno){
        answ=_calloc();
    }else if(dato==dos){
        answ=_get();
    }else if(dato==tres){
        _set();
    }
    answ=_free();
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

/**
 * metodo que se conecta con la dataBase e intenta crear ocupar un 
 * nuevo espacio de memoria.
 * @return 
 */
int MemHandler::_calloc() {
    int n,pSize=0;
    n = read(_sockfd,&pSize,sizeof(int));
    if (n < cero) 
        error(error5);
    _codigos=_heap->d_calloc(pSize);
    return _codigos;
}

/**
 * metodo que obtiene datos segun la posicion de que le proporcione.
 * @return 
 */
int MemHandler::_get() {
    int space=0,size=0,n;
    n = read(_sockfd,&space,sizeof(int));
    n = read(_sockfd,&size,sizeof(int));
    if (n < cero) 
        error(error5);
    void* pointer=_heap->d_get(space,size);
    n=send(_sockfd, pointer,size,cero);
    if (n < cero) 
        error(error6);
    return pointer;
}

/**
 * metodo que agarra una porcion de memoria y empieza a escribir sobre 
 * ella.
 */
void MemHandler::_set() {
    int size=0,n=0;
    n = read(_sockfd,&size,sizeof(int));
    _heap->d_set(size);
    if (n < cero) 
        error(error5);
    n = read(_sockfd,_heap->getPointer(),size);
    if (n < cero) 
        error(error5);
    _heap->sumPointer();
}

/**
 * metodo que libera la memoria que ya no se ocupe mas.retorna un cero si todo
 * se encuentra bien y un 2 si se esta tratando de acceder a memoria que no le 
 * pertenece.
 * @return retorna un dato tipo enter, un cero si todo esta bien y un 2 si 
 * se intentando entrar a memoria que no le pertenece.
 */
int MemHandler::_free() {

}

