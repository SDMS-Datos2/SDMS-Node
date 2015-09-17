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
Server::Server(int port) {
    _lenght=cuatro;
    _hilos=(Thread_listen*) malloc(_lenght*sizeof(Thread_listen));
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
    _portno = port;
    _serv_addr.sin_family = AF_INET;
    _serv_addr.sin_addr.s_addr = INADDR_ANY;
    _serv_addr.sin_port = htons(_portno);
    if (bind(_sockfd, (struct sockaddr *) &_serv_addr, sizeof(_serv_addr))<cero)
        error(error2);
    //se pone a escuchar en el socket si hay nuevas conexiones.
    listen(_sockfd,cinco);
    _clilen = sizeof(_cli_addr);
    //bucle para aceptar a toda las personas que se conecten 
    while(true){
        int i=cero;
        //acepta al cliente que se quiera conectar al servidor.
        _newsockfd = accept(_sockfd, (struct sockaddr*) &_cli_addr, &_clilen);
        if (_newsockfd < cero)
            error(error3);
        if(_debug)
            printf("server: got connection from %s port %d\n",
                    inet_ntoa(_cli_addr.sin_addr), ntohs(_cli_addr.sin_port));
        //porcion de codigo que permite que haga los hilos hijos, que 
        //van a atender los pedidos de los clientes.
        _pid= fork();
        //verificacion de si el hilo no se pudo establecer
        if (_pid < cero){
            free(_hilos);
            error(error4);
        }
        //abilita la conexion.
        if(_pid==cero){
            close(_sockfd);
            if(i==_lenght)
                growarray(i,_hilos);
            _hilos=new Thread_listen(_newsockfd);
            _hilos++;
            i++;
            //inicializa el metodo que va a interactuar con el cliente.
            //interact(_newsockfd);
            exit(cero);
        }
        else
            close(_newsockfd);
    }
    //cierra las conexiones para que no quede nada abierto.
    close(_newsockfd);
    close(_sockfd);
}

/**
 * destructor de la clase
 */
Server::~Server() {
    free(_hilos);
    
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

/**
 * metodo que realiza un crecimiento del arreglo 
 * que contiene los threads del server.
 */
void Server::growarray(int pActualLenght, Thread_listen* pHilos) {
    int newSize=_lenght+tres;
    Thread_listen* tmp= (Thread_listen*)realloc(pHilos,
            newSize*sizeof(Thread_listen));
    free(pHilos);
    _lenght= newSize;
    pHilos=tmp;
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
    while(true){
        bzero(Buffer,DosCientaSeis);
        //linea para leer mensajes.
        n = read(newsockfd,Buffer,DosCientaSeis-uno);
        if (n < cero) 
            error(error5);
        printf("Here is the message: %s",Buffer);
        //linea para enviar datos.
        n=send(newsockfd, "Hello, world!", 
                getLenght("Hello, world!"), cero);
        if (n < cero) 
            error(error6);
    }
}
