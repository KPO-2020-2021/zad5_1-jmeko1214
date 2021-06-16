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
            wierzcholek[i][j] = 0;
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
Prostopadloscian::Prostopadloscian(const Wektor3D &wektor, double wysokosc, double szerokosc, double dlugosc)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        wierzcholek[i] = wektor;
    }
    wierzcholek[1][0] += szerokosc;

    wierzcholek[2][1] += wysokosc;

    wierzcholek[3][0] += szerokosc;
    wierzcholek[3][1] += wysokosc;

    wierzcholek[4][1] += wysokosc;
    wierzcholek[4][2] += dlugosc;

    wierzcholek[5][0] += szerokosc;
    wierzcholek[5][1] += wysokosc;
    wierzcholek[5][2] += dlugosc;

    wierzcholek[6][2] += dlugosc;

    wierzcholek[7][0] += szerokosc;
    wierzcholek[7][2] += dlugosc;
}


/******************************************************************************
 |  Realizuje zapis wspolrzednych Prostopadloscian do strumienia              |                                               
 |  Argumenty:                                                                |
 |     StrmWy - strumien do ktorego sa zapisywane wspolrzedne wierrzcholkow   |
 |     Pr - przechowuje wspolrzedne wierzcholkow prostopadloscianu            |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */

void Prostopadloscian::Zapis_do_strumienia(std::ostream& StrmWy,  Prostopadloscian Pr)
{
    //zapis wspolrzednych wierzcholkow do strumienia
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[4] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[5] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[6] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[7] << std::endl;
    StrmWy << std::endl;
    //powtorzenie pierwszych wierzcholkow by zamknoc bryle
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
    StrmWy << std::endl;
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Prostopadloscian do pliku                   |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne wierzch|
 |     Pr - przechowuje wspolrzedne wierzcholkow, ktore maja byc zapisane     |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::Zapis_do_pliku(const std::string &sNazwaPliku, const Prostopadloscian Pr)
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    Zapis_do_strumienia(StrmPlikowy,Pr);

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
        strm << prosty.wierzcholek[i] << std::endl;
    }
    return strm;
}



