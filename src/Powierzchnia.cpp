#include "Powierzchnia.hh"


/******************************************************************************
 |  Konstruktor parametryczny klasy Powierzchnia.                             |
 |  Argumenty:                                                                |
 |     dlugosc - dlugosc plaszczyzny                                          |
 |     szerokosc - szerokosc plaszczyzny                                      |
 |     wysokosc - wysokosc plaszczyzny                                        |
 |     sNazwaPliku - przechowuje nazwe pliku zawierajacego wspolrzedne        |
 |  Zwraca:                                                                   |
 |     Obrocona bryle                                                         | 
 */
Powierzchnia::Powierzchnia(double dlugosc, double szerokosc, double wysokosc, std::string sNazwaPliku)
{
    this->sNazwaPliku = sNazwaPliku;
    Wektor3D wek;//[3];
    ilosc = 0;
    for(int i=-dlugosc/2; i<=dlugosc/2; i+=20)
    {
        for(int j=-szerokosc/2; j<=szerokosc/2; j+=20)
        {
            wek[0] = i;
            wek[1] = j;
            wek[2] = wysokosc;
            siatka.push_back(wek);
        }
        ilosc++;
    }
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Powierzchni do pliku                        |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne        |
 |                   powierzchni                                              |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Powierzchnia::Zapisz_do_pliku()
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    for(int i=0; i<ilosc; i++)
    {
        if(i%ilosc==0)
        {
            StrmPlikowy << std::endl;
        }
        StrmPlikowy << siatka[i] << std::endl;
    }
    StrmPlikowy.close();
    return !StrmPlikowy.fail();

}
