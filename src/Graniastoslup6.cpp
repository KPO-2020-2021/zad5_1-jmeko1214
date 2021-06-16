#include "Graniastoslup6.hh"


/*
 *  Tutaj sa zdefiniowane metody klasy Graniastoslup6. 
 *  Metody tworza graniastoslup i zapisuja go do pliku.
 */

 /******************************************************************************
 |  Konstruktor bezparametryczny klasy graniastoslup.                         |
 |  Argumenty:                                                                |
 |     brak                                                                   |
 */
Graniastoslup6::Graniastoslup6()
{
    for(int i=0; i<GRANIA_SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            wierzcholki[i][j] = 0;
        }
    }
}

/*****************************************************************************
 |  Konstruktor parametryczny klasy Graniastoslup6.                           |
 |  Argumenty:                                                                |
 |     srodek - srodek bryly, wokol ktorego dokonuje sie obrot                |
 |     promien - dlugosc promienia obrotu / boku graniastoslupa               |
 |     sNazwaPliku - przechowuje nazwe pliku zawierajacego wspolrzedne        |
 |  Zwraca:                                                                   |
 |     Obrocona bryle                                                         | 
 */
Graniastoslup6::Graniastoslup6(Wektor3D srodek, double promien, std::string sNazwaPliku)
{
    Wektor3D wektor;
    this->srodek = srodek;
    this->sNazwaPliku = sNazwaPliku;

    for(int i=0; i<360; i+=60)
    {
        wektor[0] = srodek[0] + promien * cos(i * PI / 180);
        wektor[1] = srodek[1] + promien * sin(i * PI / 180);
        wektor[2] = srodek[2];
        wierzcholki.push_back(wektor);
        wektor[0] = srodek[0] + promien * cos(i * PI / 180);
        wektor[1] = srodek[1] + promien * sin(i * PI / 180);
        wektor[2] = srodek[2] + 10;
        wierzcholki.push_back(wektor);
    }
}


/******************************************************************************
 |  Realizuje zapis wspolrzednych Graniastoslupa do pliku                     |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne wierzch|
 |     Pr - przechowuje wspolrzedne wierzcholkow, ktore maja byc zapisane     |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Graniastoslup6::Zapis_do_pliku()
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<GRANIA_SIZE; i++)
    {
        StrmPlikowy << std::setw(16) << std::fixed << std::setprecision(10) << wierzcholki[i] << std::endl;
        if(i%2==1)
        {
            StrmPlikowy << std::endl;
        }
        if(i==GRANIA_SIZE)  //ponowne zapisanie dwoch pierwszych punktow
        {
            StrmPlikowy << std::setw(16) << std::fixed << std::setprecision(10) << wierzcholki[0] << std::endl;
            StrmPlikowy << std::setw(16) << std::fixed << std::setprecision(10) << wierzcholki[1] << std::endl;
        }
    }
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |                                               
 |  Argumenty:                                                                |
 |     strm - strumien wyjsciowy                                              |
 |     Grania - zmienna pomocnicza do operacji na graniastoslupie             |
 |  Zwraca:                                                                   |
 |     Strumien wyjsciowy                                                     |
 */
std::ostream & operator << (std::ostream &strm, const Prostopadloscian &Grania)
{
    for(int i=0; i<GRANIA_SIZE; i++)
    {
        strm << Grania[i] << std::endl;
        if(i%2==1)
        {
            strm << std::endl;
        }
    }
    return strm;
}


