#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "BrylaGeometryczna.hh"


/*!
 * \brief  Klasa opisuje Plaszczyzne.
 *
 *  Tutaj znajduje sie definicja klasy Plaszczyzna.
 *  Tworzy powierzchnie Marsa
 */
class Plaszczyzna {
    protected:
    std::vector<Wektor3D> siatka;
    std::string sNazwaPliku;
    int ilosc;

    public:
    Plaszczyzna(double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku);
    bool Zapisz_do_pliku();
};


#endif

