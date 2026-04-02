#ifndef TGUIRLANDE_H
#define TGUIRLANDE_H

#include "pario.h"
#include "toctet.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

class tGuirlande
{
    private:
        bool ModeBoucle;
        bool ModeArret;
        bool ModeInversion;
        int NumeroProgramme;
        unsigned char ValeurEntrees;
        tParIO MonParIO;
        tOctet MesOctet;

    public:
        tGuirlande();
        void ExecuterPrg1();
        void ExecuterPrg2();
        void ExecuterPrg3();
        void ExecuterPrg4();
        void LireEntrees();
        void IdentifierNumProg();
        void IdentifierBoucle();
        void IdentifierArret();
        void IdentifierInversion();
        void ExecuterProg();
        void AfficherBits();
        void Piloter();
};

#endif // TGUIRLANDE_H
