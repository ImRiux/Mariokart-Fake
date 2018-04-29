#include "HEADER.h"

using namespace std;

/*void startbildschirm()
{
    char block = 219;
    cout << block;
}*/

int main()
{
    Spieler spieler1;
    Spieler spieler2;
    Spieler spieler3;
    Spieler spieler4;
    //startbildschirm();
    hauptmenue();
    int numOfPlayers = getNumberOfPlayers();
    if (numOfPlayers >= 2)
    {
        spieler1 = spielerEingabe();

        spieler2 = spielerEingabe();
    }
    if (numOfPlayers >= 3)
        spieler3 = spielerEingabe();

    if (numOfPlayers == 4)
        spieler4 = spielerEingabe();


    for (int runde = 1; runde <= 15; ++runde)
    {
        cout << "Runde " << runde << '\n';
        startMap();
        spieler1 = spielerZug(spieler1);
        spieler2 = spielerZug(spieler2);
        if (numOfPlayers >= 3)
            spieler3 = spielerZug(spieler3);
        if (numOfPlayers == 4)
            spieler4 = spielerZug(spieler4);

        cout << "\n\n\n\n";
    }


    //Array für Spieleroutput beim berechen der Punktzahlen
    Spieler spielerOut[numOfPlayers];
    spielerOut[0].punkte = punkteZaehlen(spieler1);
    spielerOut[1].punkte = punkteZaehlen(spieler2);
    if (numOfPlayers >= 3)
        spielerOut[2].punkte = punkteZaehlen(spieler3);
    if (numOfPlayers == 4)
        spielerOut[3].punkte = punkteZaehlen(spieler4);
    spielerOut[0].name = spieler1.name;
    spielerOut[1].name = spieler2.name;
    if (numOfPlayers >= 3)
        spielerOut[2].name = spieler3.name;
    if (numOfPlayers == 4)
        spielerOut[3].name = spieler4.name;

    //Gewinner sortieren
    for (int startIndex = 0; startIndex < numOfPlayers; ++startIndex)
    {
        int maxIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < numOfPlayers; ++currentIndex)
        {
            if (spielerOut[currentIndex].punkte > spielerOut[maxIndex].punkte)
                maxIndex = currentIndex;
        }
        swap(spielerOut[startIndex], spielerOut[maxIndex]);
    }

    //Gewinner ausgeben
    cout << "Siegerliste:\n";
    for (int iii = 0; iii < numOfPlayers; ++iii)
    {
        cout << iii + 1 << ". " << spielerOut[iii].name <<
        " mit " << spielerOut[iii].punkte << " Punkten.\n";
    }

    return 0;
}
