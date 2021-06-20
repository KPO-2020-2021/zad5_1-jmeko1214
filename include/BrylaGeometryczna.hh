#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH

#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include "size.hh"
#include <fstream>
#include <vector>

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
    Wektor3D *wymiary;
    std::vector<Wektor3D> wierzcholki;
    std::string sNazwaPliku;

    public:
    Wektor3D & operator[] (unsigned int index);         //przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
    const Wektor3D & operator[] (unsigned int index) const;
    
    void ustaw_srodek(Wektor3D srodek);
    Wektor3D zwroc_srodek() const;
    void UstawNazwaPliku(std::string sNazwaPliku);
    std::string ZwrocNazwaPliku() const;
    void Obrot(Macierz3x3 macierz);
    void Przesuniecie(Wektor3D wektor);
    bool Zapisz_do_pliku();
    ~BrylaGeometryczna();

};




#endif

