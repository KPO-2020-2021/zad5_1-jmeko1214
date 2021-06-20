#include "Prostopadloscian.hh"


/*
 *  Tutaj sa zdefiniowane metody klasy Prostopadloscian. 
 *  Metody tworza prostopadloscian i zapisuja go do pliku.
 */

 /******************************************************************************
 |  Konstruktor bezparametryczny klasy Prostopadloscian.                      |
 |  Argumenty:                                                                |
 |     brak                                                                   |
 */
Prostopadloscian::Prostopadloscian()
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            wierzcholki[i][j] = 0;
        }
    }
}

/*****************************************************************************
 |  Konstruktor parametryczny klasy Prostopadloscian.                         |
 |  Argumenty:                                                                |
 |     wektor - zmienna przechowuje dlugosc wektora przesuniecia              |
 |     wysokosc - przechowuje polozenie wierzcholka na osi Oz                 |
 |     szerokosc - przechowuje polozenie wierzcholka na osi Oy                |
 |     dlugosc - przechowuje polozenie wierzcholka na osi Ox                  |
 |  Zwraca:                                                                   |
 |     Wierzcholki prostopadloscianu przesuniete o zadany wektor              | 
 */
Prostopadloscian::Prostopadloscian(Wektor3D srodek, double wysokosc, double szerokosc, double dlugosc, std::string sNazwaPliku)
{

    this->sNazwaPliku = sNazwaPliku;
    this->srodek = srodek;
    double wym[] = {wysokosc, szerokosc, dlugosc};
    wymiary = new Wektor3D(wym);
    Wektor3D vector;

    vector[0] = srodek[0] - wysokosc/2;
    vector[1] = srodek[1] + szerokosc/2;
    vector[2] = srodek[2] + dlugosc/2;
    wierzcholki.push_back(vector);
    
    vector[0] = srodek[0] - wysokosc/2;
    vector[1] = srodek[1] + szerokosc/2;
    vector[2] = srodek[2] - dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + wysokosc/2;
    vector[1] = srodek[1] + szerokosc/2;
    vector[2] = srodek[2] + dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + wysokosc/2;
    vector[1] = srodek[1] + szerokosc/2;
    vector[2] = srodek[2] - dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + wysokosc/2;
    vector[1] = srodek[1] - szerokosc/2;
    vector[2] = srodek[2] + dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + wysokosc/2;
    vector[1] = srodek[1] - szerokosc/2;
    vector[2] = srodek[2] - dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - wysokosc/2;
    vector[1] = srodek[1] - szerokosc/2;
    vector[2] = srodek[2] + dlugosc/2;
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - wysokosc/2;
    vector[1] = srodek[1] - szerokosc/2;
    vector[2] = srodek[2] - dlugosc/2;
    wierzcholki.push_back(vector);
    
}




Prostopadloscian::~Prostopadloscian()
{
    delete wymiary;
}




