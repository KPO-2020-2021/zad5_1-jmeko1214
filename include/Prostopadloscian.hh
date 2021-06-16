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
    Prostopadloscian(const Wektor3D &wektor, double wysokosc, double szerokosc, double dlugosc);                                                                                                                                                                                                                                                                      

    void Zapis_do_strumienia(std::ostream& StrmWy, Prostopadloscian Pr);
    bool Zapis_do_pliku(const std::string &NazwaPliku, const Prostopadloscian Pr);
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow prostopadloscianu.
 */
//wyswietla wspolrzedne wierzcholkow prostopadlosciana 
std::ostream& operator << ( std::ostream &Strm, const Prostopadloscian &Pr); 


#endif


