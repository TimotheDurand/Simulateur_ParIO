/****************************************************************************
* Nom du fichier.......... : pario.cpp                                      *
* TP ou projet............ : Classe d'utilisation du simulateur ParIO       *
* Auteur.................. :                                                *
* Rédigé le ...............: __/__/__                                       *
* Mise à jour .............: 25/10/2016                                     *
*****************************************************************************/
#ifndef PARIO_H
#define PARIO_H

#include "client_tcp.h"
#include "pcf8574.h"

enum tEtatParIO {EtatParIOVide, EtatParIOSimulateur, EtatParIOBoitier} ;

class tParIO
{
    private:
        tEtatParIO EtatParIO ;
        Client_TCP *client ;
        tPcf8574 * pLeds ;
        tPcf8574 * pBoutons ;

    public:
        tParIO() ;
        ~tParIO() ;
        void Ecrire(unsigned char EtatLeds) ;
        unsigned char Lire() ;
        void UtiliserSimulateur(char add_ip[20] = (char*)"172.16.185.144", unsigned short port = 5050) ;
        void DeconnecterSimulateur() ;
        void UtiliserBoitier() ;
        void DeconnecterBoitier() ;
};

#endif // PARIO_H

