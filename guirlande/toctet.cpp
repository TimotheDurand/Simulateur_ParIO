#include "toctet.h"

tOctet::tOctet() {}

void tOctet::set_valeur(unsigned char valeur)
{
    this->valeur = valeur;
}

void tOctet::show_valeur() {
    cout << "Valeur (decimal) : " << (int)valeur << endl;

    cout << "valeur (binaire) : ";
    for (int i = 7; i >= 0; i--) {
        cout << (((unsigned int)valeur >> i) & 1);
    }
    cout << endl;
}

int tOctet::get_bit(unsigned char position) {
    if (position > 7)
        return -1;
    return ((int)valeur >> position) & 1;
}


void tOctet::set_bit(unsigned char position, bool state) {
    if (position > 7)
        return;

    if (state)
        valeur = valeur | (1 << position);
    else
        valeur = valeur & ~(1 << position);
}
