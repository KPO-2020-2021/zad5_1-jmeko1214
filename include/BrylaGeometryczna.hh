#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH

#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "size.hh"

/*!
 * \brief Klasa opisuje bryle geometryczna
 *
 * Klasa definiuje pojecie bryly geometrycznej,
 * zawiera metody potrzebne do opisu bryl, ktore
 * tworza drona: prostopadloscian i graniastoslup
 */ 
class BrylaGeometryczna{
    protected:
    Wektor3D srodek;
    Wektor3D wierzcholki;
    std::string sNazwaPliku;

    public:
    Wektor3D & operator[] (unsigned int index);         //przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
    Wektor3D zwroc_srodek();
    BrylaGeometryczna Obrot(Macierz3x3 macierz);
    BrylaGeometryczna& Przesuniecie(const Wektor3D &wektor);

};




#endif

