#include "Dron.hh"

/*!
 * \brief Konstruktor bezparametryczny Drona
 */
//Dron::Dron(){}

/*!
 * \brief Konstruktor parametryczny Drona
 */
Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D polozenie) : Lacze(Lacze)
{
    kat = 0;
    this->id = id;
    korpus = new Prostopadloscian(polozenie,30, 40, 50, "../datasets/korpus" 
                                  + std::to_string(id+1) + ".dat");
    

    
}

/*!
 * \brief Metoda odpowiada za wznoszenie Drona
 */
void Dron::Lot_w_gore(double droga)
{
    Wektor3D gora;
    gora[2] = droga;

    //this->droga = this->droga + gora;
    //korpus->Obrot(obrot);
    korpus->Przesuniecie(gora);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za opadanie Drona
 */
void Dron::Lot_w_dol(double droga)
{
    Wektor3D dol;
    dol[2] = droga;

    //this->droga = this->droga + dol;
    //korpus->Obrot(obrot);
    korpus->Przesuniecie(dol);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za obrot Drona
 */
void Dron::Obrot(double kat)
{
    //this->kat = this->kat + kat;
    //Macierz3x3 mac;
    os = 'z';
    //obrot = mac * MacierzObrotu(kat, os);
    
    korpus->Obrot(MacierzObrotu(kat, os));
    //korpus->Przesuniecie(this->droga);
    usleep(CZEKAJ);
}

/*!
 * \brief Metoda odpowiada za przesuniecie Drona
 */
void Dron::Przesuniecie(double droga)
{
    Wektor3D przesun;
    przesun[0] = droga;
    /*Wektor3D ruch;
    os = 'z';
    ruch = MacierzObrotu(kat, os) * przesun;
    korpus->Przesuniecie(ruch);*/
    korpus->Przesuniecie(przesun);
    usleep(CZEKAJ);
}

void Dron::Steruj_dronem()
{
    double droga;
    double kat;
    std::cout << "  Podaj kierunek lotu (kat w stopniach)> ";
    std::cin >> kat;
    std::cout << "\t\t\t Podaj dlugosc lotu> ";
    std::cin >> droga;

    std::cout << "  Realizacja przelotu ..." << std::endl;
    std::cout << "  Wznoszenie ..." << std::endl;
    for(int i=0; i<100; i++)
    {
        Lot_w_gore(1);
        Zapisz_do_pliku();
        
        Lacze.Rysuj();
        usleep(CZEKAJ);
    } 
    std::cout << "  Zmiana orientacji ..." << std::endl;
    for(int i=0; i<kat; i++)
    {
        Obrot(1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    }
    std::cout << "  Lot do przodu ..." << std::endl;
    for(int i=0; i<droga; i++)
    {
        Przesuniecie(1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    }
    std::cout << "  Opadanie ..." << std::endl;
    for(int i=0; i<100; i++)
    {
        Lot_w_dol(-1);
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    }
    Lacze.UsunOstatniaNazwe();
    Lacze.Rysuj();
}

/*!
 * \brief Metoda odpowiada za wyznaczenie trasy przelotu Drona
 */
/*void Dron::Trasa(double droga)
{

}*/

/*!
 * \brief Metoda odpowiada za zapis Drona do pliku
 */
void Dron::Zapisz_do_pliku()
{
    korpus->Zapis_do_pliku();
}

