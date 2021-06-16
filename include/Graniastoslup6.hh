#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#define GRANIA_SIZE 12

#include "BrylaGeometryczna.hh"


class Graniastoslup6: public BrylaGeometryczna {
    public:
    Graniastoslup6();
    Graniastoslup6(Wektor3D srodek, double promien, std::string sNazwaPliku);
    
    bool Zapis_do_pliku();
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow Graniastoslupa.
 */
//wyswietla wspolrzedne wierzcholkow Graniastoslupa 
std::ostream& operator << ( std::ostream &Strm, const Graniastoslup6 &Grania); 





#endif

