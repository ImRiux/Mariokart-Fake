#ifndef HEADER
#define HEADER

#include <iostream>
#include <string>
#include <cstdlib>  //for srand() and rand()
#include <ctime>    //for time()
#include <windows.h>//for Sleep()
#include <utility>  //for swap()

//Rohstoffe
enum Bauteil
{
    BAUTEIL_LEHM,
    BAUTEIL_HOLZ,
    BAUTEIL_WOLLE,
    BAUTEIL_GETREIDE,
    BAUTEIL_STEIN,
};

//zum zählen in 'int itemsZaehlen'
struct Bauteilvariable
{
    int lehm;
    int holz;
    int stein;
    int wolle;
    int getreide;
};

//Anzahl Würfel
struct Wuerfel
{
    Bauteil eins;
    Bauteil zwei;
    Bauteil drei;
    Bauteil vier;
    Bauteil fuenf;
    Bauteil sechs;
};

struct SpielerMap
{
    //Anzahl der gebauten Strassen
    int strassen = 0;
    //Anzahl der gebauten Siedlungen
    int siedlungen = 1;
    //Anzahl der gebauten Städte
    int staedte = 0;
    //Anzahl der gebauten Ritter
    int ritter = 0;

};

//Spielerdaten
struct Spieler
{
    std::string name;
    int nummer;
    SpielerMap map;
    int minuspunkte;
    int punkte;
    //Rohstoffjoker
    bool rj1{false};
    bool rj2{false};
    bool rj3{false};
    bool rj4{false};
    bool rj5{false};
    bool rj6{false};
};

Wuerfel spielerWuerfelt();
Bauteil getRandomDieNumber();
Spieler spielerEingabe();
Spieler spielerZug(Spieler);
Bauteilvariable itemsZaehlen(Wuerfel);
std::string baumoeglichkeiten(Wuerfel);
int punkteZaehlen(Spieler);
void printSpielerMap(Spieler);
void hauptmenue();
void anleitung();
void startMap();
int getNumberOfPlayers();
//void startMap2();

#endif // HEADER

