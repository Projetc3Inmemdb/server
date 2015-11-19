/* 
 * File:   server.cpp
 * Author: ellioth
 * 
 * Created on November 12, 2015, 5:19 PM
 */

#include "server.h"

/**
 * constructor que sirve para inicializar el servidor
 * aqui mismo se crean los hilos hijos que van a 
 * interactuar con los clientes.
 * @param ServerName dato tipo char* que es el nombre del server
 * @param port dato tipo entero, este el puerto en el que vamos 
 * a crear el server.
 */
server::server(char* ServerName,int port) {
    _portno=port;
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
    fechingMSG();
    /*
    void *respon=malloc(sizeof(message));
    bzero(respon,sizeof(message));
    _n = recv(_newsockfd,respon,sizeof(message),0);
    if (_n < cero) 
        error(error6);
    if(_debug){
        message datos=*((message*)respon);
        std::cout<<datos.MSG<<std::endl;
    }
    close(_sockfd);
    free(respon);*/
}

/**
 * destructor de la clase
 */
server::~server() {
    //free(_hilo);  
}

/**
 * metodo que se encicla para recibir los mensjaes del cliente 
 * y hace la operacion pedida, devuelve lo que se le pidio, y 
 * otra vez vuelve a esperar pedido del cliente.
 */
void server::fechingMSG() {
    bool feching=true;
    void* almacenador= malloc(sizeof(message));
    while(feching){
        bzero(almacenador, sizeof(message));
        _n = read(_newsockfd,almacenador,sizeof(message));
        if (_n < cero)
            error(error6);
        almacenador=decodeMsg(almacenador);
        _n=write(_newsockfd, almacenador, sizeof(message));
        if (_n < cero) 
            error(error5);
        if((*(message*)almacenador).operation==dos)
            feching=false;
    }
    close(_newsockfd);
    close(_sockfd);
}

/**
 * metodo para decodificar el mensaje que se le pase y que 
 * haga la operacion que se le pida.
 * @param datos recibe un dato tipo void*, es es un struct con los 
 * datos de las cosas que se quiere hacer.
 * @return retorna otro struct en forma de void* que va a contener la 
 * intrucciones pedidas.
 */
void* server::decodeMsg(void * datos) {
    //decodificamos el mensaje y devolvemos lo que se nos pidio.
}


/**
 * metodo para imprimir el pantalla los errores 
 * que se presenten durante la ejecucion del servidor.
 * @param msg dato tipo "const char*" este es un string 
 * que indica el error.
 */
void server::error(const char* msg) {
    perror(msg);
    exit(uno);
}
