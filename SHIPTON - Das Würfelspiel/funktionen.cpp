#include "HEADER.h"

using namespace std;

Bauteilvariable rohstoffjoker(Bauteilvariable bauteile, Spieler spieler)
{
    tryAgain:   //Falls der Spieler einen ung¸ltigen Rohstoffjoker w‰hlt
    cout << "Waehle den Buchstaben des Rohstoffjokers, den du nutzen moechtest. Dazu" <<
    " musst du ihn allerdings besitzen.\n";
    char choice;
    do
    {
        cin >> choice;
        if (choice != 'S' && choice != 's' &&
           choice != 'G' && choice != 'g' &&
           choice != 'L' && choice != 'l' &&
           choice != 'H' && choice != 'h' &&
           choice != 'W' && choice != 'w')
           cout << "Ungueltige Wahl. Waehle einen Joker:";
    }
    while (choice != 'S' && choice != 's' &&
           choice != 'G' && choice != 'g' &&
           choice != 'L' && choice != 'l' &&
           choice != 'H' && choice != 'h' &&
           choice != 'W' && choice != 'w');

        if (spieler.rj1 && (choice == 'S' || choice == 's'))
        {
            cout << "Du hast deinen Stein-Rohstoffjoker genutzt.\n";
            spieler.rj1 = false;
            ++bauteile.stein;
            return bauteile;
        }
        else if (spieler.rj2 && (choice == 'G' || choice == 'g'))
        {
            cout << "Du hast deinen Getreide-Rohstoffjoker genutzt.\n";
            spieler.rj2 = false;
            ++bauteile.getreide;
            return bauteile;
        }
        else if (spieler.rj3 && (choice == 'W' || choice == 'w'))
        {
            cout << "Du hast deinen Wolle-Rohstoffjoker genutzt.\n";
            spieler.rj3 = false;
            ++bauteile.wolle;
            return bauteile;
        }
        else if (spieler.rj4 && (choice == 'H' || choice == 'h'))
        {
            cout << "Du hast deinen Holz-Rohstoffjoker genutzt.\n";
            spieler.rj4 = false;
            ++bauteile.holz;
            return bauteile;
        }
        else if (spieler.rj5 && (choice == 'L' || choice == 'l'))
        {
            cout << "Du hast deinen Lehm-Rohstoffjoker genutzt.\n";
            spieler.rj5 = false;
            ++bauteile.lehm;
            return bauteile;
        }
        else if (spieler.rj6 && choice == '?')
        {
            cout << "Welchen rohstoff moechtest du haben?";
            spieler.rj6 = false;
            char rohstoffwahl;
            do
            {
                cin >> rohstoffwahl;
                if(rohstoffwahl != 'S' && rohstoffwahl != 's' &&
                   rohstoffwahl != 'L' && rohstoffwahl != 'l' &&
                   rohstoffwahl != 'H' && rohstoffwahl != 'h' &&
                   rohstoffwahl != 'W' && rohstoffwahl != 'w' &&
                   rohstoffwahl != 'G' && rohstoffwahl != 'g')
                {
                    cout << "Kein gueltiger Rohstoff.\n";
                }
            }
            while (rohstoffwahl != 'S' && rohstoffwahl != 's' &&
                   rohstoffwahl != 'L' && rohstoffwahl != 'l' &&
                   rohstoffwahl != 'H' && rohstoffwahl != 'h' &&
                   rohstoffwahl != 'W' && rohstoffwahl != 'w' &&
                   rohstoffwahl != 'G' && rohstoffwahl != 'g');
            switch (rohstoffwahl)
            {
            case 'S':
            case 's':
                cout << "Du hast Stein gewaehlt.\n";
                ++bauteile.stein;
                break;
            case 'L':
            case 'l':
                cout << "Du hast Lehm gewaehlt.\n";
                ++bauteile.lehm;
                break;
            case 'H':
            case 'h':
                cout << "Du hast Holz gewaehlt.\n";
                ++bauteile.holz;
                break;
            case 'W':
            case 'w':
                cout << "Du hast Wolle gewaehlt.\n";
                ++bauteile.wolle;
                break;
            case 'G':
            case 'g':
                cout << "Du hast Getreide gewaehlt.\n";
                ++bauteile.getreide;
                break;
            }

            return bauteile;
        }
        else
        {
            cout << "Du besitzt keine Rohstoffjoker mit diesem Namen.\n";
            goto tryAgain;      //Am Anfang dieser Funktion
        }
}

//gibt Anzahl aller Rohstoffe (nach 3 mal w¸rfeln) zur¸ck
Bauteilvariable itemsZaehlen(Wuerfel wuerfel, Spieler spieler)
{
    //allen Rohstoffen wird 0 zugewiesen
    Bauteilvariable bauteile{0};

    //Fragen, ob der spieler einen Rohstoffjoker einsetzen will
    if (spieler.rj1 || spieler.rj2 || spieler.rj3
        || spieler.rj4 || spieler.rj5 || spieler.rj6)
    {
        cout << "Moechtest du einen Rohstoffjoker einsetzen? (j/n)";
        char choice;
        do
        {
            cin >> choice;
            if (choice != 'j' && choice != 'n')
            {
                cout << "Falsche Wahl. Gib 'j' fuer ja oder 'n' fuer nein ein.";
            }
        }
        while (choice != 'j' && choice != 'n');
        if (choice == 'j')
            rohstoffjoker(bauteile, spieler);
    }

//jeder W¸rfel wird auf sein Item gepr¸ft und die Items werden zusammengez‰hlt
    switch (wuerfel.eins)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }

    switch (wuerfel.zwei)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }

    switch (wuerfel.drei)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }

    switch (wuerfel.vier)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }

    switch (wuerfel.fuenf)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }

    switch (wuerfel.sechs)
    {
    case BAUTEIL_LEHM:
        ++bauteile.lehm;
        break;
    case BAUTEIL_GETREIDE:
        ++bauteile.getreide;
        break;
    case BAUTEIL_HOLZ:
        ++bauteile.holz;
        break;
    case BAUTEIL_STEIN:
        ++bauteile.stein;
        break;
    case BAUTEIL_WOLLE:
        ++bauteile.wolle;
        break;
    }
    return bauteile;
}

Spieler activateRohstoffjoker(Spieler spieler)
{
    switch (spieler.map.ritter)
    {
    case 1:
        spieler.rj1 = true;
        break;
    case 2:
        spieler.rj2 = true;
        break;
    case 3:
        spieler.rj3 = true;
        break;
    case 4:
        spieler.rj4 = true;
        break;
    case 5:
        spieler.rj5 = true;
        break;
    case 6:
        spieler.rj6 = true;
        break;
    }
    return spieler;
}

//Gibt Mˆglichkeiten aus und l‰sst den Spieler w‰hlen
string baumoeglichkeiten(Wuerfel wuerfel, Spieler spieler)
{
    Bauteilvariable bauteile = itemsZaehlen(wuerfel, spieler);

    //Um zu testen, was an einer Straﬂe liegt
    static int strassen{0};
    static int siedlungBauMoeglich{0};
    static int straslungBauMoeglich{0};
    static int stadtBauMoeglich{0};
    switch (strassen)
    {
    case 2:
        ++stadtBauMoeglich;
        ++straslungBauMoeglich;
        break;
    case 3:
        ++siedlungBauMoeglich;
        break;
    case 5:
        ++stadtBauMoeglich;
        ++straslungBauMoeglich;
        break;
    case 6:
        ++siedlungBauMoeglich;
        break;
    case 7:
        ++straslungBauMoeglich;
    case 8:
        ++siedlungBauMoeglich;
        break;
    case 9:
        ++straslungBauMoeglich;
        break;
    case 10:
        ++siedlungBauMoeglich;
        break;
    case 11:
        ++straslungBauMoeglich;
        break;
    case 12:
        ++siedlungBauMoeglich;
        break;
    case 14:
        ++stadtBauMoeglich;
        break;
    case 16:
        ++stadtBauMoeglich;
    }


    //Mˆglichkeitenzuweisung
    int strasseMK{0};
    int zstrasseMK{0};
    int dstrasseMK{0};
    int ritterMK{0};
    int zritterMK{0};
    int stratterMK{0};  //Straﬂe & Ritter
    int siedlungMK{0};
    int stadtMK{0};
    int straslungMK{0}; //Straﬂe und Siedlung ^^

    //Straﬂe
    int moeglichkeiten{0};
    if (bauteile.lehm >= 1 && bauteile.holz >= 1)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")" << "Du kannst eine Strasse bauen.\n";
        strasseMK = moeglichkeiten;
    }
    //2 Straﬂen
    if (bauteile.lehm >= 2 && bauteile.holz >= 2)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")Du kannst 2 Strassen bauen.\n";
        zstrasseMK = moeglichkeiten;
    }
    //3 Straﬂen
    if (bauteile.lehm == 3 && bauteile.holz == 3)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")Du kannst 3 Strassen bauen.\n";
        dstrasseMK = moeglichkeiten;
    }
    //Ritter
    if (bauteile.stein >= 1 && bauteile.wolle >= 1 && bauteile.getreide >= 1)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")" << "Du kannst einen Ritter anheuern.\n";
        ritterMK = moeglichkeiten;
    }
    if (bauteile.stein == 2 && bauteile.wolle == 2 && bauteile.getreide == 2)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")Du kannst 2 Ritter anheuern.\n";
        zritterMK = moeglichkeiten;
    }
    if (bauteile.lehm && bauteile.holz && bauteile.getreide && bauteile.wolle && bauteile.stein)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")Du kannst einen Ritter anheuern und eine Strasse bauen.\n";
        stratterMK = moeglichkeiten;
    }
    //Siedlung
    if (bauteile.lehm >= 1 && bauteile.holz >= 1 &&
        bauteile.wolle >= 1 && bauteile.getreide >= 1 && siedlungBauMoeglich != 0)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")" << "Du kannst eine Siedlung bauen.\n";
        siedlungMK = moeglichkeiten;
    }
    //Siedlung + Straﬂe
    if (bauteile.lehm == 2 && bauteile.holz == 2 &&
        bauteile.wolle == 1 && bauteile.getreide == 1 &&
        (siedlungBauMoeglich != 0 && straslungBauMoeglich != 0))    //Checkt, ob eine Straﬂe und eine Siedlung,
                                                                    //oder eine Siedlung und eine Straﬂe baubar ist
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")" << "Du kannst eine Siedlung und " <<
        "eine Strasse bauen.\n";
        straslungMK = moeglichkeiten;
    }
    //Stadt
    if (bauteile.stein >= 3 && bauteile.getreide >= 2 && stadtBauMoeglich != 0)
    {
        ++moeglichkeiten;
        cout << "(" << moeglichkeiten << ")" << "Du kannst eine Stadt bauen.\n";
        stadtMK = moeglichkeiten;
    }

    //Wenn es baumˆglichkeiten gibt
    if (moeglichkeiten)
    {

        int choice;
        //Inputcheck
        do
        {
            cout << "Was waehlst du? ";
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                choice = 20; // ein Wert, der die while-schleife wiederhohlt
            }
        }
        while (choice != strasseMK && choice != ritterMK
               && choice != siedlungMK && choice != stadtMK
               && choice != zstrasseMK && choice != dstrasseMK
               && choice != zritterMK && choice != stratterMK
               && choice != straslungMK);

        if (choice == strasseMK)
        {
            ++strassen;
            return "Straﬂe";
        }
        else if (choice == zstrasseMK)
        {
            strassen += 2;
            return "2 Straﬂen";
        }
        else if (choice == dstrasseMK)
        {
            strassen += 3;
            return "3 Straﬂen";
        }
        else if (choice == ritterMK)
        {
            return "Ritter";
        }
        else if (choice == zritterMK)
            return "2 Ritter";
        else if (choice == stratterMK)
            return "Straﬂe + Ritter";
        else if (choice == siedlungMK)
        {
            --siedlungBauMoeglich;
            --straslungBauMoeglich;
            return "Siedlung";
        }
        else if (choice == stadtMK)
        {
            --stadtBauMoeglich;
            return "Stadt";
        }
        else if (choice == straslungMK)
        {
            --siedlungBauMoeglich;
            --straslungBauMoeglich;
            ++strassen;
            return "Straﬂe + Siedlung";
        }
    }
    else
        return "Keine Mˆglichkeiten";
}

Bauteil getRandomDieNumber()
{
    srand(time(0)); //set seed on time(0)

    int randomNumber = (rand() % 5);    //zuf‰llige Zahl zwischen  0 und 4
    Bauteil randomRessource = static_cast<Bauteil>(randomNumber);
    return randomRessource;
}

void anleitung()
{
    cout << "Vor langer Zeit lebte in Shipton ein Koenig, der fuer Stabilitaet im Land sorgte." <<
    " Doch als\ner im Krieg starb begann unter den Buergern ein Streit um den Thron, da der " <<
    "Koenig keinen Nachfolger\nhinterlassen hatte. Um einen Neunen zu bestimmen wird ein Wettbewerb" <<
    " veranstaltet, bei dem die Buerger ein kleines Imperium\naufbauen sollen. Der beste " <<
    "Stratege gewinnt und wird Herrscher von Shipton!\nZeigt was ihr drauf habt...\n\n";
    cout << "Zuerst entscheidet ihr, wie viele Spieler mitspielen wollen. Das koennen 2 - 4 sein.\n" <<
    "Auf der Karte ist ein fertiges 'Shipton' abgebildet. Jeder Spieler hat nachher eine eigene Karte (die zu Beginn leer ist),\n" <<
    "auf der er innerhalb von 15 Zuegen versucht, so viel wie moeglich zu bauen.\n";
    startMap();
    cout << "Zum Bauen braucht ihr Rohstoffe. Die Rohstoffe werden mit 6 Wuerfeln ausgewuerfelt. Mit " <<
    "jedem Wuerfel besteht\nje eine Moeglichkeit auf Wolle, Getreide, Lehm, Stein oder Holz. Der Bau " <<
    "einer Strasse kostet beispielsweise 1 Holz und 1 Lehm.\nNur dann, wenn ein Spieler diese beiden " <<
    "Rohstofe gewuerfelt hat, kann er auch eine Strasse bauen. Wer etwas baut, bekommt\nPunkte " <<
    "zugeschrieben. Strassen geben jeweils 1 Punkt. Die erste Siedlung gibt 3 Punte und alle darauffolgenden\n" <<
    "Siedlungen geben jeweils 2 Punkte mehr (2. Siedlung = 5 Punkte, 3. Siedlung = 7 Punkte usw).\n" <<
    "Die erste Stadt gibt 7 Punkte, alle Anderen jeweils 4 Punkte" <<
    " mehr. Der erste Ritter\ngibt 3 Punkte und alle anderen Ritter geben jeweils 1 Punkt mehr.\n";
    cout << "SPIELABLAUF:\n1. Wuerfeln: Wer an der Reihe ist, darf bis zu 3 mal Wuerfeln. Nach jedem " <<
    "Wurf legt der Spieler beliebig\nviele Wuerfel zur Seite und wuerfelt mit den verbleibenden erneut." <<
    "\n2. Bauen: In der Bauuebersicht auf der Spielkarte ist angegeben, welche Rohstoffe man zum bauen benoetigt." <<
    " Das Spiel schlaegt vor, was mit\nden gewuerfelten Rohstoffen gebaut werden kann. Ausserdem muss " <<
    "ein Bauwerk an einer Strasse liegen, um gebaut werden zu koennen.\nSo koennen Strassen immer " <<
    "gebaut werden, waehrend Siedlungen und Staedte nur gebaut werden koennen, wenn sie an die Strasse\n" <<
    "'angeschlossen' sind. Ritter koennen immer gebaut werden. Besitzt ein Spieler einen Ritter, so kann\n" <<
    "er den Rohstoff darunter (siehe Karte: S fuer Stein, H fuer Holz, usw) EINMAL im Spiel einstzen.\n" <<
    "\n\nAm Ende des Spiels rechnet der Computer die resultierende Punktzahl aller Spieler aus und gibt ein" <<
    " ranking aus.\n";
}

void hauptmenue()
{
    cout << "\t\t\t\t[SHIPTON]\n";
    cout << "\t\t\t    Das Wuerfelspiel\n";

    while(true)
    {
        cout << "(1)Spielen\n(2)Anleitung\n";
        int input;
        do
        {
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                input = 3;
            }
        }
        while (input != 1 && input != 2);
        if (input == 1)
            break;
        else if (input == 2)
            anleitung();
            break;
    }
}


int getNumberOfPlayers()
{
    int num;
    do
    {
        cout << "Wie viele Spieler wollen spielen?\n";
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            num = 5;
        }
        else if (num < 2 || num > 4)
        {
            cout << "Es koennen nur 2 - 4 Spieler spielen. Versuch es noch einmal.\n";
        }
    }
    while (num < 2 || num > 4);
    return num;
}

Spieler spielerEingabe()
{
    static int spielerNummer = 0;
    ++spielerNummer;
    cout << "Spieler #" << spielerNummer << "\nGib deinen Namen ein:";
    Spieler spieler1;
    Spieler spieler2;
    Spieler spieler3;
    Spieler spieler4;
    if (spielerNummer == 1)
    {
        getline(cin, spieler1.name);    //Iwie wir diese Zeile hier ¸bersprungen...
        getline(cin, spieler1.name);
        cout << spieler1.name << " ist als Erstes dran.\n\n";
        spieler1.nummer = spielerNummer;
        return spieler1;
    }
    else if (spielerNummer == 2)
        {
        getline(cin, spieler2.name);
        cout << spieler2.name << " ist als Zweites dran.\n\n";
        spieler2.nummer = spielerNummer;
        return spieler2;
        }
    else if (spielerNummer == 3)
    {
        getline(cin, spieler3.name);
        cout << spieler3.name << " ist als Drittes dran.\n\n";
        spieler3.nummer = spielerNummer;
        return spieler3;
    }
    else if (spielerNummer == 4)
    {
        getline(cin, spieler4.name);
        cout << spieler4.name << " ist als Viertes dran.\n\n";
        spieler4.nummer = spielerNummer;
        return spieler4;
    }
}


Spieler spielerZug(Spieler spieler)
{
    Wuerfel wuerfel;

            cout << spieler.name << " ist dran. Deine momentane Karte:\n";
            printSpielerMap(spieler);
            wuerfel = spielerWuerfelt();
            string spielerwahl = baumoeglichkeiten(wuerfel, spieler);
            if (spielerwahl == "Ritter")
            {
                cout << "Du hast dich Entschieden, einen Ritter anzuheuern.\n\n";
                ++spieler.map.ritter;
                spieler = activateRohstoffjoker(spieler);
            }
            else if (spielerwahl == "2 Ritter")
            {
                cout << "Du hast dich entschieden, zwei Ritter anzuheuern.\n\n";
                ++spieler.map.ritter;
                spieler = activateRohstoffjoker(spieler);
                ++spieler.map.ritter;
                spieler = activateRohstoffjoker(spieler);
            }
            else if (spielerwahl == "Straﬂe + Ritter")
            {
                cout << "Du hast dich entschieden, einen Ritter anzuheuern und eine Strasse zu bauen.\n\n";
                ++spieler.map.ritter;
                spieler = activateRohstoffjoker(spieler);
                ++spieler.map.strassen;
            }
            else if (spielerwahl == "Keine Mˆglichkeiten")
            {
                cout << "Du kannst leider nichts bauen.\n\n";
                Sleep(1000);
            }
            else if (spielerwahl == "Siedlung")
            {
                cout << "Du hast dich entschieden eine Siedlung zu bauen.\n\n";
                ++spieler.map.siedlungen;
            }
            else if (spielerwahl == "Stadt")
            {
                cout << "Du hast dich entschieden eine Stadt zu bauen.\n\n";
                ++spieler.map.staedte;
            }
            else if (spielerwahl == "Straﬂe")
            {
                cout << "Du hast dich entschieden eine Strasse zu bauen.\n\n";
                ++spieler.map.strassen;
            }
            else if (spielerwahl == "2 Straﬂen")
            {
                cout << "Du hast dich entschieden zwei Strassen zu bauen.\n\n";
                spieler.map.strassen += 2;
            }
            else if (spielerwahl == "3 Straﬂen")
            {
                cout << "Du hast dich entschieden drei Strassen zu bauen.\n\n";
                spieler.map.strassen += 3;
            }
            else if (spielerwahl == "Straﬂe + Siedlung")
            {
                cout << "Du hast dich entschieden eine Strasse und eine Siedlung zu bauen.\n\n";
                ++spieler.map.strassen;
                ++spieler.map.siedlungen;
            }
        return spieler;
}

int punkteZaehlen(Spieler spieler)
{
    //References
    int &strassen = spieler.map.strassen;
    int &ritter = spieler.map.ritter;
    int &siedlungen = spieler.map.siedlungen;
    int &staedte = spieler.map.staedte;

    int spielerPunkte{0};
    spielerPunkte += strassen * 1;      //Anzahl der Straﬂen in Punkten
    spielerPunkte += siedlungen * (siedlungen + 2); //Punkte Siedlungen jedes mal +2
    spielerPunkte += staedte * (staedte * 2 + 5);   //Punkte St‰dte jedes mal + 4
    spielerPunkte += ritter * (0.5 * ritter + 2.5); //Punkte Ritter jedes mal + 1
    return spielerPunkte;
}
