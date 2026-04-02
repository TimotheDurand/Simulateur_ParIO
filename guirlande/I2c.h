#ifndef I2C_H
#define I2C_H
//---------------------------------------------------------------------------
// Déclaration de la classe de gestion du bus I2C
//---------------------------------------------------------------------------
class tI2c
    {
    private:
        unsigned long CompteurBoucle ;
        unsigned char InportB (unsigned short AdrPort) ;
        void OutportB (unsigned short AdrPort, unsigned char Valeur) ;
        void Delai(unsigned long del) ;
        void InitDelay(void) ;
    protected:

    public:
        unsigned short I2cPort ;    /* Adresse du port parallèle
                                            - 0X378 par défautv     */

        tI2c (void) ;
        void I2c_Init(void) ;	    /* INITIALISATION DU BUS */
        void I2c_Start(void) ;	    /* START */
        void I2c_Stop(void) ;		/* STOP */
        int I2c_Out(char oct) ;		/* ENVOI D'UN OCTET */
        char I2c_In_A (void) ; 		/* RECEPTION D'UN OCTET AVEC ACK */
        char I2c_In (void) ; 		/* RECEPTION D'UN OCTET SANS ACK */
    } ;

//---------------------------------------------------------------------------
#endif

