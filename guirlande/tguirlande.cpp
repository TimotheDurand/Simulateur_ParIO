#include "tguirlande.h"

tGuirlande::tGuirlande()
{
    NumeroProgramme = 0;
}



void tGuirlande::ExecuterPrg1()
{
    unsigned char Leds[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80} ;

    MonParIO.Ecrire(0x00);

    for(int i = 0 ; i < 8; i++)
    {
        MonParIO.Ecrire(Leds[i]) ;
        sleep(1) ;
    }
}



void tGuirlande::ExecuterPrg2()
{
    MonParIO.Ecrire(0x00);

    MonParIO.Ecrire(0xff) ;
    sleep(1);

    MonParIO.Ecrire(0x00);
    sleep(1);
}



void tGuirlande::ExecuterPrg3()
{
    unsigned char Leds[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80} ;

    MonParIO.Ecrire(0x00);

    for (int i = 0 ; i < 4 ; i++) {
        MonParIO.Ecrire(Leds[i * 2]);
    }
    sleep(1);

    MonParIO.Ecrire(0x00);
    for (int i = 0 ; i < 4 ; i++) {
        MonParIO.Ecrire(Leds[(i * 2 + 1)]);
    }
    sleep(1);
}



void tGuirlande::ExecuterPrg4()
{
    unsigned char Leds[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80} ;

    MonParIO.Ecrire(0x00);

    for (int i = 0 ; i < 4 ; i++) {
        MonParIO.Ecrire(Leds[i] + Leds[7 - i]);
        sleep(1);
        MonParIO.Ecrire(0x00);
    }
}



void tGuirlande::LireEntrees()
{
    ValeurEntrees = MonParIO.Lire();
    MesOctet.set_valeur(ValeurEntrees);
}



void tGuirlande::IdentifierNumProg()
{
    unsigned char val = (ValeurEntrees >> 4);

    if (val != 0) {
        NumeroProgramme = val;
    }
}



void tGuirlande::IdentifierBoucle()
{
    ModeBoucle = 1 & (ValeurEntrees >> 1);
}



void tGuirlande::IdentifierArret()
{
    ModeArret = 1 & (ValeurEntrees >> 3);

    if (ModeArret) {
        MonParIO.Ecrire(0x00);
        exit(1);
    }
}



void IdentifierInversion()
{
    ModeInversion = 1 & ValeurEntrees;
}



void tGuirlande::ExecuterProg()
{
    switch (NumeroProgramme)
    {
        case 1:
            ExecuterPrg1();
            break;
        case 2:
            ExecuterPrg2();
            break;
        case 4:
            ExecuterPrg3();
            break;
        case 8:
            ExecuterPrg4();
            break;
    }
}



void tGuirlande::AfficherBits()
{
    cout << "Bits de l'octet :" << endl;

    for (int i = 7; i >= 0; i--) {
        int bit = MesOctet.get_bit(i);

        if (bit == -1)
            continue;

        cout << "Bit " << i << " : " << bit << endl;
    }
}



void tGuirlande::Piloter()
{
    sleep(1);
    MonParIO.UtiliserSimulateur((char*)"172.16.190.139");

    while (true) {
        do {
            LireEntrees();
            IdentifierNumProg();
            IdentifierBoucle();
            IdentifierArret();
            ExecuterProg();
            if (!ModeBoucle)
                NumeroProgramme = 0;
        } while (ModeBoucle);
    }
}
