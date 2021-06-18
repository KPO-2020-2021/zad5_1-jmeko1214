#include "Scena.hh"



Scena::Scena()
{
  double polozenie1[] = {25.0, 25.0, 25.0};
  double polozenie2[] = {100.0, 25.0, 25.0}; 

  Lacze.DodajNazwePliku("../datasets/bryly_wzorcowe/plaszczyzna.dat",PzG::RR_Ciagly,2);
  Lacze.ZmienTrybRys(PzG::TR_3D);
  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-300,300);
  Lacze.UstawZakresX(-300,300);
  Lacze.UstawZakresZ(-300,300);
  
  dno = new Plaszczyzna(600, 600, 0, "../datasets/bryly_wzorcowe/plaszczyzna.dat");
  dno->Zapisz_do_pliku();   //plik plaszczyzny
  
  drony[0] = new Dron(0, polozenie1);
  drony[0]-> Zapisz_do_pliku();     //plik drona
  drony[1] = new Dron(1, polozenie2);
  drony[1]-> Zapisz_do_pliku();     //plik drona

  Lacze.Rysuj();
}

void Scena::Rysuj()
{
    Lacze.Rysuj();
}

bool Scena::Wybor_drona()
{
    std::cout << "   Wybor aktywnego drona" << std::endl << std::endl;
    std::cout << " Wprowadz numer aktywnego drona> ";
    int numer;
    std::cin >> numer;
    if(numer==1 || numer==2)
    {
        if((numer-1)==0)
        {
            std::cout << "    1 - Polozenie     <-- Dron aktywny" << std::endl;
            std::cout << "    2 - Polozenie " << std::endl;
        }
        if((numer-1)==1)
        {
            std::cout << "    1 - Polozenie " << std::endl;
            std::cout << "    2 - Polozenie     <-- Dron aktywny " << std::endl;
        }
    }
    else
    {
        std::cerr << " Blad! Dozwolony wybor 1 lub 2 Drona!" << std::endl;
        return false;
    }
    return true;      
}


void Scena::Ruch_dronem()
{
    int numer;
    numer = this->numer;
    if((numer-1)==0)
    {
        drony[numer]->Steruj_dronem();
    }
    if((numer-1)==1)
    {
        drony[numer]->Steruj_dronem();
    }
}
