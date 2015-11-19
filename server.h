/* 
 * File:   server.h
 * Author: ellioth
 *
 * Created on November 12, 2015, 5:19 PM
 */

#ifndef SERVER_H
#define	SERVER_H
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <iostream>
#include "Constantes.h"

/**
 * struct que contiene los datos esperados en el envio 
 * o recibo de datos por medio de tcp
 */
struct message{
    void* MSG;
    int sizeMSG;
    int operation;
    int toServer;
};

/**
 * clase para crear el server.
 */
class server :public Constantes{
public:
    server(char* ServerName, int port);
    virtual ~server();
private:
    int _sockfd, _newsockfd, _portno, _n, _codigos;
    socklen_t _clilen;
    char _buffer[DosCientaSeis];
    char* _id;
    struct sockaddr_in _serv_addr, _cli_addr;
    void error(const char* msg);
    void fechingMSG();
    void* decodeMsg(void* dato);
};

#endif	/* SERVER_H */

