#include "Dron.hh"
#include "Scena.hh"

/*!
 * \brief Konstruktor bezparametryczny Drona
 */
Dron::Dron(){}

/*!
 * \brief Konstruktor parametryczny Drona
 */
Dron::Dron(int id, Wektor3D polozenie)
{
    kat = 0;
    this->id = id;
    korpus = new Prostopadloscian(polozenie, 50, 80, 60, "../datasets/Korpus" + std::to_string(id) + ".dat");
    for(int i=0; i<ROTORY; i++)
    {
        rotor[i] = new Graniastoslup6((*korpus)[i+4], 20, "../datasets/Roror" + std::to_string(id) + ".dat");
    }
    korpus_kopia = *korpus;
    korpus_kopia.Przesuniecie(polozenie);
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia[i] = *rotor[i];
    }
}

/*!
 * \brief Metoda odpowiada za wznoszenie Drona
 */
void Dron::Lot_w_gore()
{
    Wektor3D gora;
    gora[2] = 1;

    korpus->Przesuniecie(gora);
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia->Obrot(obrot);
    }
}

/*!
 * \brief Metoda odpowiada za opadanie Drona
 */
void Dron::Lot_w_dol()
{
    Wektor3D gora;
    gora[2] = -1;

    korpus->Przesuniecie(gora);
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia->Obrot(obrot);
    }
}

/*!
 * \brief Metoda odpowiada za obrot Drona
 */
void Dron::Obrot(double kat)
{
    this->kat = this->kat + kat;
    Macierz3x3 mac;
    os = 'z';
    obrot = mac * MacierzObrotu(this->kat, os);
    korpus_kopia.Obrot(obrot);
    korpus_kopia.Przesuniecie(this->droga);    
}

/*!
 * \brief Metoda odpowiada za przesuniecie Drona
 */
void Dron::Przesuniecie(double droga)
{
    Wektor3D przesun;
    double radiany = kat * PI / 180;
    przesun[0] = droga * cos(radiany);
    przesun[1] = droga * sin(radiany);
    this->droga = this->droga + przesun;
    korpus_kopia.Obrot(obrot);
    korpus_kopia.Przesuniecie(this->droga);
}

void Dron::Steruj_dronem()
{
    double droga;
    double kat;
    std::cout << "  Podaj kierunek lotu (kat w stopniach)> ";
    std::cin >> kat;
    std::cout << "\t\t\t\t Podaj dlugosc lotu> ";
    std::cin >> droga;

    
    std::cout << "  Realizacja przelotu ..." << std::endl;
    std::cout << "  Wznoszenie ..." << std::endl;
    for(int i=0; i<100; i++)
    {
        Lot_w_gore();
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    } 
    std::cout << "  Zmiana orientacji ..." << std::endl;
    for(int i=0; i<kat; i++)
    {
        Obrot(kat);
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    }
    std::cout << "  Lot do przodu ..." << std::endl;
    for(int i=0; i<droga; i++)
    {
        Przesuniecie(droga);
        Zapisz_do_pliku();
        Lacze.Rysuj();
        usleep(CZEKAJ);
    }
    std::cout << "  Opadanie ..." << std::endl;
    for(int i=0; i<100; i++)
    {
        Lot_w_dol();
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
    korpus_kopia.Zapis_do_pliku();
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia[i].Zapis_do_pliku();
    }
}



