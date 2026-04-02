#ifndef CLIENT_TCP_H
#define CLIENT_TCP_H

using namespace std;

#include <string.h>
#include <unistd.h>
#include <iostream>
#include <string>
//#include <sys/socket.h>
#include <arpa/inet.h> 	//inet_addr

class Client_TCP
{
    private:
        //elements pour construciton socket
        int socket_cl;
        string  ip_add_srv;
        unsigned short port_num;
        struct sockaddr_in server;

    public:
        Client_TCP(char *ip_add, unsigned short port);         //paramètre par défaut
        ~Client_TCP();
        bool connecter();
        void deconnecter();
        bool transmettre(char data_to_srv[]);
        char* recevoir(int size);
};

#endif // CLIENT_TCP_H
