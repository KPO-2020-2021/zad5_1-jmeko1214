#include "Dron.hh"

/*!
 * \brief Konstruktor bezparametryczny Drona
 */
Dron::Dron(){}

/*!
 * \brief Konstruktor parametryczny Drona
 */
//Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D polozenie) : Lacze(Lacze)
Dron::Dron(int id, Wektor3D polozenie)
{
    std::cout<<"cos6"<<std::endl;
    kat = 0;
    this->id = id;
    this->Lacze = Lacze;
    
    korpus.UstawNazwaPliku("../datasets/korpus" + std::to_string(id) + ".dat");
    for(int i=0; i<ROTORY; i++)
    {
        rotor[i].UstawNazwaPliku("../datasets/rotor" + std::to_string(i) 
                                 + "_dron" + std::to_string(id) + ".dat");
    }
    Lacze.DodajNazwePliku(korpus.ZwrocNazwaPliku().c_str(), PzG::RR_Ciagly, 2);
    for(int i=0; i<ROTORY; i++)
    {
        Lacze.DodajNazwePliku(rotor[i].ZwrocNazwaPliku().c_str(), PzG::RR_Ciagly, 2);
    }
    korpus_kopia = korpus;
    korpus_kopia.Przesuniecie(polozenie);
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia[i] = rotor[i];
    }
    for(int i=0; i<ROTORY; i++)
    {
        for(int j=0; j<ROTORY; j++)
        {
            j=j*2;
            rotor_kopia[i].Przesuniecie(korpus[j] + polozenie);
        }
        
    }
    this->droga = this->droga + polozenie;
    
}

/*!
 * \brief Metoda odpowiada za wznoszenie Drona
 */
void Dron::Lot_w_gore(double droga)
{
    Wektor3D gora;
    gora[2] = droga;

    this->droga = this->droga + gora;
    korpus_kopia.Obrot(obrot);
    korpus_kopia.Przesuniecie(this->droga);
}

/*!
 * \brief Metoda odpowiada za opadanie Drona
 */
void Dron::Lot_w_dol(double droga)
{
    Wektor3D dol;
    dol[2] = droga;

    this->droga = this->droga + dol;
    korpus_kopia.Obrot(obrot);
    korpus_kopia.Przesuniecie(this->droga);
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
        Lot_w_gore(1);
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
    korpus_kopia.Zapisz_do_pliku();
    for(int i=0; i<ROTORY; i++)
    {
        rotor_kopia[i].Zapisz_do_pliku();
    }
}

