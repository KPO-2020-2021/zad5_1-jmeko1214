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

    vector[0] = srodek[0] - (wysokosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] + (dlugosc/2);
    wierzcholki.push_back(vector);
    
    vector[0] = srodek[0] - (wysokosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] - (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (wysokosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] + (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (wysokosc/2);
    vector[1] = srodek[1] + (szerokosc/2);
    vector[2] = srodek[2] - (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (wysokosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] + (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] + (wysokosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] - (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - (wysokosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] + (dlugosc/2);
    wierzcholki.push_back(vector);

    vector[0] = srodek[0] - (wysokosc/2);
    vector[1] = srodek[1] - (szerokosc/2);
    vector[2] = srodek[2] - (dlugosc/2);
    wierzcholki.push_back(vector);
    
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Prostopadloscian do pliku                   |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne wierzch|
 |     Pr - przechowuje wspolrzedne wierzcholkow, ktore maja byc zapisane     |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::Zapis_do_pliku()
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        StrmPlikowy << wierzcholki[i] << std::endl;
        if(i%2==1)
        {
            StrmPlikowy << std::endl;
        }
    }
    StrmPlikowy << wierzcholki[0] << std::endl;
    StrmPlikowy << wierzcholki[1] << std::endl;
    
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |                                               
 |  Argumenty:                                                                |
 |     strm - strumien wyjsciowy                                              |
 |     prosty - zmienna pomocnicza do operacji na prostopadloscianie          |
 |  Zwraca:                                                                   |
 |     Strumien wyjsciowy                                                     |
 */
std::ostream & operator << (std::ostream &strm, const Prostopadloscian &prosty)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << prosty[i] << std::endl;
        if(i%2==1)
        {
            strm << std::endl;
        }
    }
    strm << prosty[0] << std::endl;
    strm << prosty[1] << std::endl;
    
    return strm;
}


Prostopadloscian::~Prostopadloscian()
{
    delete wymiary;
}




