#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "lacze_do_gnuplota.hh"
#include <string.h>
#include <unistd.h>

#define ROTORY 4
#define CZEKAJ 10000

class Dron {
    PzG::LaczeDoGNUPlota Lacze;
    Prostopadloscian *korpus;
    Prostopadloscian korpus_kopia;
    Graniastoslup6 *rotor[4];
    Graniastoslup6 rotor_kopia[4];
    Wektor3D droga;
    Macierz3x3 obrot;
    double kat;
    double id;
    char os;

    public:
    /*!
    * \brief Konstruktory klasy Dron
    */
    Dron();
    Dron(int id, Wektor3D polozenie);

    /*!
    * \brief Metody klasy Dron
    */
    void Lot_w_gore();
    void Lot_w_dol();
    void Obrot(double kat);
    void Przesuniecie(double przesun);
    void Steruj_dronem();
    //void Trasa(double droga);
    void Zapisz_do_pliku(); 
};



#endif

