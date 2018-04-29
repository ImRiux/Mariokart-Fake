#include "HEADER.h"

using namespace std;

//für 'startMap()'
void stadt()
{
    char x = static_cast<char>(219);
    char y = static_cast<char>(220);
    cout << x << y;
}
/*void startMap2()
{


    char strasse = static_cast<char>(196);
    char siedlung = static_cast<char>(254);

    for (int y = 26; y >= 0; y--)            //Stellt y Koordinate dar, da am ende der Schleife 1x 'endl' ausgegeben wird
    {
        bool printed{false};
        //ANFANG JEDER ZEILE
        if (y < 26)            //Am Anfang jeder Zeile wird '|' ausgegeben, außer in der Obersten
        {
            cout << "\t\t\t\t|";
        }
        else                //Gibt Tab und backspace aus
        {
            cout << "\t\t\t\t ";
        }

        //MITTELTEIL bzw. TEXTTEIL JEDER ZEILE
        //Für jeden output muss eine 'else if' Klammer eingefügt werden. Ungenuzte
        //Stellen müssen mit Leertaste ausgefüllt werden
        if (y == 26)                        //In der obersten Zeile wird eine Abgrenzung ausgegeben
        {
            cout << "__________________________________________";
            printed = true;
        }
        else if (y == 25)
        {
            cout << "                 SHIPTON                  ";
            printed = true;
        }
        else if (y == 23)
        {
            cout << "Strasse : Holz | Lehm                     ";
            printed = true;
        }
        else if (y == 22)
        {
            cout << "Ritter  : Stein| Wolle | Getreide         ";
            printed = true;
        }
        else if (y == 21)
        {
            cout << "Siedlung: Holz | Wolle | Getreide | Lehm  ";
            printed = true;
        }
        if (y == 20)
        {
            cout << "Stadt   : 3x Stein | 2x Getreide          ";
            printed = true;
        }
        if (y == 18)
        {
            cout << "------------------------------------------";
            printed = true;
        }
        if (y == 16)
        {
            cout << "        ";
            stadt();
            cout << "      ";
            stadt();
            cout << "                        ";
            printed = true;
        }
        if (y == 14)
        {
            cout << "        |       |                         ";
            printed = true;
        }
        switch (y)
        {
        case 12:
            cout << "    " << siedlung << "  " << strasse << " " << strasse << "  " << siedlung <<
            "  " << strasse << " " << strasse << "  " << siedlung << "  <" << strasse << " Start           ";
            printed = true;
            break;
        case 10:
            cout << "    |                                     ";
            printed = true;
            break;
        case 8:
            cout << "    |                                     ";
            printed = true;
            break;
        case 6:
            cout << "    " << siedlung << "  " << strasse << " " << strasse << "  " << siedlung <<
            "  " << strasse << " " << strasse << "  " << siedlung << "                     ";
            printed = true;
            break;
        case 4:
            cout << "    |                                     ";
            printed = true;
            break;
        case 2:
            cout << "    ";
            stadt();
            cout << " " << strasse << " " << strasse << " ";
            stadt();
            cout << "                             ";
            printed = true;
            break;
        }
        if (y == 0)                    //In der letzten Zeile wird wieder eine Abgrenzung ausgegeben
        {
            cout << "__________________________________________";
            printed = true;
        }
        else if (printed == false)       //Wenn nichts ausgegeben werden soll, werden 20 leere Stellen ausgegeben
        {
            cout << "                                          ";
        }


        //ENDE JEDER ZEILE
        if (y != 26)        //Am Ende jeder Zeile wird '|' ausgegeben, außer in der Ersten
        {
            cout << "|";
        }

        cout << endl;
    }
    cout << endl;
}*/


//Gibt die Map jedes Spielers aus
void printSpielerMap(Spieler spieler)
{
    //references:
    int &staedte = spieler.map.staedte;
    int &siedlungen = spieler.map.siedlungen;
    int &ritter = spieler.map.ritter;
    int &strassen = spieler.map.strassen;

    char strasse = static_cast<char>(196);
    char siedlung = static_cast<char>(254);

    //Gibt obere 2 Städte aus
    if (staedte == 1)
    {
        cout << "                 ";
        stadt();
        cout << "                      \n";
    }
    else if (staedte >= 2)
    {
        cout << "        ";
        stadt();
        cout << "        ";
        stadt();
        cout << "                      \n";
    }
    //Gibt Ritter aus
    if (ritter == 1)
        cout << "                       °                  \n";
    else if (ritter >= 2)
        cout << "             °         °                  \n";
    //Gibt Straßen zu oberen Städten aus
    if (strassen >= 2 && strassen < 5)
        cout << "                  |                       \n";
    if (strassen >= 5)
        cout << "        |         |                       \n";
    //Gibt Rohstoffjoker aus
    if (ritter == 1)
        cout << "                       S                  \n";
    else if (ritter >= 2)
        cout << "             G         S                  \n";
    if (strassen == 1 || strassen == 2)
    {
        cout << "                  _                       \n";
        cout << "                     \\                    \n";
    }
    else if (strassen == 3)
    {
        cout << "                  _                       \n";
        cout << "               /     \\                    \n";
    }
    else if (strassen == 4 || strassen == 5)
    {
        cout << "        _         _                       \n";
        cout << "           \\   /     \\                    \n";
    }
    else if (strassen >= 6)
    {
        cout << "        _         _                       \n";
        cout << "     /     \\   /     \\                    \n";
    }
    //Gibt Siedlungen aus
    if (siedlungen == 1)
    {
        cout << "                      " << siedlung << " <" << strasse << "Start           \n";
    }
    else if (siedlungen == 2)
    {
        cout << "             " << siedlung << "        " <<
            siedlung << " <" << strasse << "Start           \n";
    }
    else if (siedlungen >= 3)
    {
        cout << "    " << siedlung << "        " << siedlung << "        " <<
            siedlung << " <" << strasse << "Start           \n";
    }
    //Gibt Ritter aus
    if(ritter == 3)
        cout << "                  °                       \n";
    else if (ritter >= 4)
        cout << "        °         °                       \n";
    //Gibt Straße aus
    if(strassen >= 7)
        cout << "    |                                     \n";
    //Gibt Rohstoffjoker
    if (ritter == 3)
        cout << "                  ?                       \n";
    else if (ritter >= 4)
        cout << "        W         ?                       \n";
    //Gibt Straßen aus
    if (strassen == 8)
    {
        cout << "             _                            \n";
        cout << "     \\                                    ";
    }
    else if (strassen == 9)
    {
        cout << "                       _                  \n";
        cout << "     \\     /                              \n";
    }
    else if (strassen == 10)
    {
        cout << "             _                            \n";
        cout << "     \\     /   \\                          \n";
    }
    else if (strassen == 11)
    {
        cout << "             _         _                  \n";
        cout << "     \\     /   \\     /                    \n";
    }
    else if (strassen >= 12)
    {
        cout << "             _         _                  \n";
        cout << "     \\     /   \\     /   \\                \n";
    }
    //Gibt Siedlungen aus
    if (siedlungen == 4)
        cout << "        " << siedlung << '\n';
    else if (siedlungen == 5)
        cout << "        " << siedlung << "         " << siedlung << '\n';
    else if (siedlungen == 6)
        cout << "        " << siedlung << "         " << siedlung << "       " << siedlung << '\n';
    //Gibt Ritter aus
    if (ritter == 5)
        cout << "             °                            \n";
    else if (ritter == 6)
        cout << "             °         °                  \n";
    //Gibt Straße aus
    if (strassen >= 13)
        cout << "        |                                 \n";
    //Gibt Rohstoffjoker
    if (ritter == 5)
        cout << "             H                            \n";
    else if (ritter == 6)
        cout << "             H         L                  \n";
    //Gibt Straßen aus
    if (strassen == 14)
    {
        cout << "          \\                               \n";
    }
    else if (strassen == 15)
    {
        cout << "                   _                      \n";
        cout << "          \\     /                         \n";
    }
    else if (strassen == 16)
    {
        cout << "                   _                      \n";
        cout << "          \\     /     \\                   \n";
    }
    //Gibt Städte aus
    if (staedte == 3)
    {
        cout << "             ";
        stadt();
        cout << "                           \n";
    }
    if (staedte == 4)
    {
        cout << "             ";
        stadt();
        cout << "         ";
        stadt();
        cout << "                ";
    }

}

void startMap()
{
    char strasse = static_cast<char>(196);
    char siedlung = static_cast<char>(254);

    for (int y = 31; y >= 0; y--)            //Stellt y Koordinate dar, da am ende der Schleife 1x 'endl' ausgegeben wird
    {
        bool printed{false};
        //ANFANG JEDER ZEILE
        if (y < 31)            //Am Anfang jeder Zeile wird '|' ausgegeben, außer in der Obersten
        {
            cout << "\t\t\t\t|";
        }
        else                //Gibt Tab und backspace aus
        {
            cout << "\t\t\t\t ";
        }

        //MITTELTEIL bzw. TEXTTEIL JEDER ZEILE
        //Für jeden output muss eine 'else if' Klammer eingefügt werden. Ungenuzte
        //Stellen müssen mit Leertaste ausgefüllt werden
        switch (y)
        {
        case 31:
            cout << "__________________________________________";
            printed = true;
            break;

        case 30:
            cout << "                 SHIPTON                  ";
            printed = true;
            break;
        case 28:
            cout << "Strasse : Holz | Lehm                     ";
            printed = true;
            break;
        case 27:
            cout << "Ritter  : Stein| Wolle | Getreide         ";
            printed = true;
            break;
        case 26:
            cout << "Siedlung: Holz | Wolle | Getreide | Lehm  ";
            printed = true;
            break;
        case 25:
            cout << "Stadt   : 3x Stein | 2x Getreide          ";
            printed = true;
            break;
        case 23:
            cout << "------------------------------------------";
            printed = true;
            break;
        case 21:
            cout << "        ";
            stadt();
            cout << "        ";
            stadt();
            cout << "                      ";
            printed = true;
            break;
        case 20:
            cout << "             °         °                  ";
            printed = true;
        break;
        case 19:
            cout << "        |    G    |    S                  ";
            printed = true;
            break;
        case 18:
            cout << "        _         _                       ";
            printed = true;
            break;
        case 17:
            cout << "     /     \\   /     \\                    ";
            printed = true;
            break;
        case 15:
            cout << "    " << siedlung << "        " << siedlung << "        " <<
            siedlung << " <" << strasse << "Start           ";
            printed = true;
            break;
        case 14:
            cout << "        °         °                       ";
            printed = true;
            break;
        case 13:
            cout << "    |   W         ?                       ";
            printed = true;
            break;
        case 12:
            cout << "             _         _                  ";
            printed = true;
            break;
        case 11:
            cout << "     \\     /   \\     /   \\                ";
            printed = true;
            break;
        case 9:
            cout << "        " << siedlung << "         " << siedlung << "       " << siedlung << "               ";
            printed = true;
            break;
        case 8:
            cout << "             °         °                  ";
            printed = true;
            break;
        case 7:
            cout << "        |    H         L                  ";
            printed = true;
            break;
        case 6:
            cout << "                   _                      ";
            printed = true;
            break;
        case 5:
            cout << "          \\     /     \\                   ";
            printed = true;
            break;
        case 3:
            cout << "             ";
            stadt();
            cout << "         ";
            stadt();
            cout << "                ";
            printed = true;
            break;
        case 1:

            stadt();
            cout << ": Stadt, / und \\: Strasse, °: Ritter    ";
            printed = true;
            break;
        case 0:
            cout << "__________________________________________";
            printed = true;
            break;
        }

        if (printed == false)       //Wenn nichts ausgegeben werden soll, werden 20 leere Stellen ausgegeben
        {
            cout << "                                          ";
        }


        //ENDE JEDER ZEILE
        if (y != 31)        //Am Ende jeder Zeile wird '|' ausgegeben, außer in der Ersten
        {
            cout << "|";
        }

        cout << endl;
    }
    cout << endl;
}

