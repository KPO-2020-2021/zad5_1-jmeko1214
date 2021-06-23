#include "Scena.hh"



Scena::Scena()
{
    double polozenie[3] = {25.0, 25.0, 25.0};
    double polozenie2[3] = {100.0, 25.0, 25.0};
    Wektor3D w1(polozenie);
    Wektor3D w2(polozenie2);

    Lacze.DodajNazwePliku("../datasets/bryly_wzorcowe/plaszczyzna.dat",PzG::RR_Ciagly,2);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    // Ustawienie zakresow poszczegolnych osi
    Lacze.UstawZakresY(-300,300);
    Lacze.UstawZakresX(-300,300);
    Lacze.UstawZakresZ(-300,300);
    dno = new Plaszczyzna(600, 600, 0, "../datasets/bryly_wzorcowe/plaszczyzna.dat");
    dno->Zapisz_do_pliku();   //plik plaszczyzny
  
    drony[0] = new Dron(0, Lacze, w1);
    drony[1] = new Dron(1, Lacze, w2);

    Lacze.DodajNazwePliku(("../datasets/korpus" + std::to_string(1) + ".dat").c_str(), PzG::RR_Ciagly, 2);
    
    //dron1 = new Dron(1, Lacze, w1);
    //dron1->Zapisz_do_pliku();     //plik drona

    Lacze.DodajNazwePliku(("../datasets/korpus" + std::to_string(2) + ".dat").c_str(), PzG::RR_Ciagly, 2);
    //dron2 = new Dron(2, Lacze, w2);
    //dron2->Zapisz_do_pliku();     //plik drona
  
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
    this->numer = numer;
    if(numer==1 || numer==2)
    {
        if(numer==1)
        {
            std::cout << "    1 - Polozenie     <-- Dron aktywny" << std::endl;
            std::cout << "    2 - Polozenie " << std::endl;
        }
        if(numer==2)
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
    if(numer==1)
    {
        drony[0]->Steruj_dronem();
    }
    if(numer==2)
    {
        drony[1]->Steruj_dronem();
    }
}



Scena::~Scena()
{
    delete dno;
    delete drony[0];
    delete drony[1];
}
