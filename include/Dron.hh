#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "BrylaGeometryczna.hh"
#include "lacze_do_gnuplota.hh"
#include <string.h>
#include <unistd.h>

#define CZEKAJ 5000

class Dron {
    private:
    PzG::LaczeDoGNUPlota &Lacze;
    Prostopadloscian *korpus;
    Wektor3D droga;
    Macierz3x3 obrot;
    double kat;
    int id;
    char os;

    public:
    /*!
    * \brief Konstruktory klasy Dron
    */
    Dron();
    Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D polozenie);

    /*!
    * \brief Metody klasy Dron
    */
    void Lot_w_gore(double droga);
    void Lot_w_dol(double droga);
    void Obrot(double kat);
    void Przesuniecie(double przesun);
    void Steruj_dronem();
    void Trasa(double kat, double droga);
    void Zapisz_do_pliku(); 
};



#endif

