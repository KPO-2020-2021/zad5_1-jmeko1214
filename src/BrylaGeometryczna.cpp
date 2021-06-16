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
    return wierzcholki[index];
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
    return wierzcholki[index];
}

/******************************************************************************
 |  Metoda zwracajaca srodek bryly geometrycznej.				              |                  
 |  Argumenty:                                                                |
 |     brak						                                              |
 |  Zwraca:                                                                   |
 |     srodek - zwaraca srodek bryly geometrycznej                            |
 */
Wektor3D BrylaGeometryczna::zwroc_srodek()
{
    return srodek;
}

/******************************************************************************
 |  Metoda klasy Prostopadloscian.                                            |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
Prostopadloscian BrylaGeometryczna::Obrot(Macierz3x3 macierz)  
{
    for(int i=0; i<wierzcholki; i++)
    {
    	(*this)[i] = macierz* (*this)[i];
    }
    return (*this);
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostopadlosciana o zadany wektor     |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
Prostopadloscian& BrylaGeometryczna::Przesuniecie(const Wektor3D &wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    for(int i=0; i<wierzcholki; i++)
    {
        (*this)[i] = (*this)[i] + wektor;
    }
    return (*this);
}

