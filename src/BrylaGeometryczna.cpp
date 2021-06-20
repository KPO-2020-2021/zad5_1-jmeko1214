#include "BrylaGeometryczna.hh"



/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostopadlosciana                                   |
 */
Wektor3D & BrylaGeometryczna::operator [] (unsigned int index)
{
    if(wierzcholki.size()<=index)
    {
       return wierzcholki[index];
    }
    return wierzcholki[wierzcholki.size()-1];
}

/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostopadlosciana                                   |
 */
const Wektor3D & BrylaGeometryczna::operator [] (unsigned int index) const
{
    if(wierzcholki.size()<=index)
    {
       return wierzcholki[index];
    }
    return wierzcholki[wierzcholki.size()-1];
}

/******************************************************************************
 |  Metoda zwracajaca srodek bryly geometrycznej.				              |                  
 |  Argumenty:                                                                |
 |     brak						                                         |
 |  Zwraca:                                                                   |
 |     srodek - zwaraca srodek bryly geometrycznej                            |
 */
Wektor3D BrylaGeometryczna::zwroc_srodek() const
{
    return srodek;
}

void BrylaGeometryczna::ustaw_srodek(Wektor3D srodek)
{
    this->srodek = srodek;
}

void BrylaGeometryczna::UstawNazwaPliku(std::string sNazwaPliku)
{
    this->sNazwaPliku = sNazwaPliku;
}

std::string BrylaGeometryczna::ZwrocNazwaPliku() const
{
    return sNazwaPliku;
}

/******************************************************************************
 |  Metoda klasy BrylaGeometryczna.                                           |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
void BrylaGeometryczna::Obrot(Macierz3x3 macierz)  
{
    for(int i=0; i<SIZE; i++)
    {
    	wierzcholki[i] = macierz* wierzcholki[i];
    }
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow bryly o zadany wektor     |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
void BrylaGeometryczna::Przesuniecie(Wektor3D wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        wierzcholki[i] = wierzcholki[i] + wektor;
    }
    srodek = srodek + wektor;
}

bool BrylaGeometryczna::Zapisz_do_pliku()
{
    std::ofstream StrmPlikowy;

    double wek[] = {0, 0, (*wymiary)[2]/2};
    Wektor3D przesun(wek); //przesuwa srodek
    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<(int)wierzcholki.size(); i=i+2)
    {
        StrmPlikowy <<  srodek + przesun << std::endl;
        for(int j=0; j<2; j++)
        {
            StrmPlikowy << wierzcholki[i+j] << std::endl;
        }
        StrmPlikowy << srodek - przesun << std::endl << std::endl;
    }
    StrmPlikowy << srodek + przesun << std::endl;
    for(int i=0; i<2; i++)
    {
        StrmPlikowy << wierzcholki[i] << std::endl;
    }
    StrmPlikowy << srodek - przesun << std::endl << std::endl;
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

 BrylaGeometryczna::~BrylaGeometryczna()
 {
    delete wymiary;
 }




