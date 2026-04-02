#ifndef TOCTET_H
#define TOCTET_H

#include <iostream>

using namespace std;

class tOctet
{
private:
    unsigned char valeur;

public:
    tOctet();

    void set_valeur(unsigned char valeur);
    void show_valeur();
    int get_bit(unsigned char position);
    void set_bit(unsigned char position, bool state);
};

#endif // TOCTET_H
