#ifndef SCENA_HH
#define SCENA_HH

#include "lacze_do_gnuplota.hh"
#include "Plaszczyzna.hh"
#include "Dron.hh"
#include <iostream>

/*!
 * \brief  Klasa opisuje Scene.
 *
 *  Tutaj znajduje sie definicja klasy Scena.
 *  Tworzy scene, na ktorej dochodzi do ruchu drona.
 */
class Scena {
    PzG::LaczeDoGNUPlota Lacze;
    Plaszczyzna *dno;
    Dron *drony[2];
    int numer;

    public:
    Scena();
    void Rysuj();
    bool Wybor_drona();
    void Ruch_dronem();
};


#endif

