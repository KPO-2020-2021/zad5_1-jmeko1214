#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "BrylaGeometryczna.hh"


/*!
 * \brief  Klasa opisuje Powierzchnie.
 *
 *  Tutaj znajduje sie definicja klasy Powierzchnia.
 *  Tworzy powierzchnie Marsa
 */
class Powierzchnia {
    protected:
    std::vector<Wektor3D> siatka;
    std::string sNazwaPliku;
    int ilosc;

    public:
    Powierzchnia(double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);
    bool Zapisz_do_pliku();
};


#endif

