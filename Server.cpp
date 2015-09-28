/* 
 * File:   Server.cpp
 * Author: osboxes
 * 
 * Created on 12 September 2015, 22:56
 */


#include "Server.h"
using namespace std;

/**
 * constructor que sirve para inicializar el servidor
 * aqui mismo se crean los hilos hijos que van a 
 * interactuar con los clientes.
 * @param port dato del tipo entero, este el puerto 
 * por medio del cual nos queremos crear nuestro servidor
 * tcp/ip.
 */
Server::Server(char* ServerName) {
    _id=ServerName;
    //aqui se inicializa el socket
    _sockfd = socket(AF_INET, SOCK_STREAM, cero);
    //resivision de si la conexion del socket 
    // fue positiva o fallida.
    if (_sockfd <cero)
        error(error1);
    //se escibe 0s en la variables puesta.
    //esto garantiza que no se use memoria sucia.
    bzero((char *) &_serv_addr, sizeof(_serv_addr));
    //establecemos los datos que se van a utilizar 
    //en el socket.
    _portno = puerto;
    _serv_addr.sin_family = AF_INET;
    _serv_addr.sin_addr.s_addr = INADDR_ANY;
    _serv_addr.sin_port = htons(_portno);
    if (bind(_sockfd, (struct sockaddr *) &_serv_addr, sizeof(_serv_addr))<cero)
        error(error2);
    //se pone a escuchar en el socket si hay nuevas conexiones.
    listen(_sockfd,cinco);
    _clilen = sizeof(_cli_addr);
    _newsockfd = accept(_sockfd, (struct sockaddr*) &_cli_addr, &_clilen);
    if (_newsockfd < cero)
        error(error3);
    if(_debug)
        printf("server: got connection from %s port %d\n",
                inet_ntoa(_cli_addr.sin_addr), ntohs(_cli_addr.sin_port));
    //nos envia al metodo que va a interactuar contra el cliente.
    _hilo=new MemHandler(_sockfd);
    _hilo->interactuar();
    //cierra las conexiones para que no quede nada abierto.
    close(_newsockfd);
    close(_sockfd);
}

/**
 * destructor de la clase
 */
Server::~Server() {
    free(_hilo);
    
}

/**
 * metodo que funciona con los hilos, este tiene
 * las operaciones a realizarse para comunicarse 
 * con el cliente.
 * @param newsockfd dato del tipo entero, este dato 
 * solo lo puede ingresar y operar el servidor.
 */
void Server::interact(int newsockfd) {
    int n;
    char Buffer[DosCientaSeis];
    //bucle que interactua con el cliente.
    n=send(newsockfd, &_id, getLenght(_id), cero);
    if (n < cero) 
            error(error6);
    while(true){
        bzero(Buffer,DosCientaSeis);
        //linea para leer mensajes.
        n = read(newsockfd,Buffer,DosCientaSeis-uno);
        if (n < cero) 
            error(error5);
        //decodeMsg(atoi(Buffer),Buffer);
        if(_debug)
            printf("Here is the message: %s",Buffer);
        //linea para enviar datos.
        n=send(newsockfd, &_codigos,sizeof(int), cero);
        if (n < cero) 
            error(error6);
    }
}

/**
 * metodo para imprimir el pantalla los errores 
 * que se presenten durante la ejecucion del servidor.
 * @param msg dato tipo "const char*" este es un string 
 * que indica el error.
 */
void Server::error(const char* msg) {
    perror(msg);
    exit(uno);
}
