#ifndef TPCF8574_H
#define TPCF8574_H

#include "I2c.h"

class tPcf8574
{
    private :
        static tI2c * pI2c;
        char Adresse;

    public:
        tPcf8574(char aAdresse);

        void Ecrire(unsigned char Valeur);
        unsigned char Lire(void);
};

#endif // TPCF8574_H
