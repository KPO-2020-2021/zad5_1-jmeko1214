#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#define WIERZCHOLKI 8

#include "BrylaGeometryczna.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

/*!
 *  \brief Definicja klasy Prostopadloscian.
 *
 * Klasa reprezentuje prostopadloscian, obiekt skladajacy 
 * sie z 8 wierzcholkow. Prostopadloscian mozna przesuwac,
 * obracac, wyswietlac jego wierzcholki oraz sprawdzac, czy
 * po tych operacjach boki sa rowne.
 */
class Prostopadloscian: public BrylaGeometryczna {

  public:
    Prostopadloscian();
    Prostopadloscian( Wektor3D srodek, double wysokosc, double szerokosc, double dlugosc, std::string sNazwaPliku);                                                                                                                                                                                                                                                                      

    
    ~Prostopadloscian();
};
  

#endif


