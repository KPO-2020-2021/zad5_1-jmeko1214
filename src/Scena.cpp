#include "Scena.hh"



Scena::Scena()
{
     std::cout<<"cos1"<<std::endl;
  double polozenie[3] = {25.0, 25.0, 25.0};
  double polozenie2[3] = {100.0, 25.0, 25.0}; 
 std::cout<<"cos2"<<std::endl;
  Lacze.DodajNazwePliku("../datasets/bryly_wzorcowe/plaszczyzna.dat",PzG::RR_Ciagly,2);
 std::cout<<"cos3"<<std::endl;
  Lacze.ZmienTrybRys(PzG::TR_3D);
  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-300,300);
  Lacze.UstawZakresX(-300,300);
  Lacze.UstawZakresZ(-300,300);
  std::cout<<"cos4"<<std::endl;
  dno = new Plaszczyzna(600, 600, 0, "../datasets/bryly_wzorcowe/plaszczyzna.dat");
  dno->Zapisz_do_pliku();   //plik plaszczyzny
  std::cout<<"cos5"<<std::endl;

  //dron1 = new Dron(0, Lacze, Wektor3D(polozenie));
  Wektor3D w1(polozenie);
  Wektor3D w2(polozenie2);
  std::cout<<"cos5"<<std::endl;
  
  dron1 = new Dron(0, w1);
  //dron1 = new Dron(0, Lacze, w1);
  std::cout<<"cos"<<std::endl;
  dron1->Zapisz_do_pliku();     //plik drona

  //dron2 = new Dron(1, Lacze, w2);
  dron2 = new Dron(1, w2);
  std::cout<<"cos"<<std::endl;
  dron2->Zapisz_do_pliku();     //plik drona
  
  
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
        dron1->Steruj_dronem();
    }
    if((numer-1)==1)
    {
        dron2->Steruj_dronem();
    }
}

Scena::~Scena()
{
    delete dno;
    delete dron1;
    delete dron2;
}
