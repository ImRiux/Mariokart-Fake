#include "HEADER.h"

using namespace std;

//Rohstoff hat immer 8 Zeichen!
void wuerfelFenster1()
{
    for (int i = 1; i <=  6; ++i)
    {
        cout << " __________ ";
    }
    cout << '\n';
    for (int i = 1; i <=  6; ++i)
    {
        cout << "|#" << i << "        |";
    }
    cout << '\n';
    for (int i = 1; i <=  6; ++i)
    {
        cout << "|          |";
    }
    cout << '\n';
}
void wuerfelFenster2()
{
    cout << '\n';
    for (int i = 1; i <= 6; ++i)
    {
        cout << "|          |";
    }
    cout << '\n';
    for (int i = 1; i <= 6; ++i)
    {
        cout << "|__________|";
    }
    cout << '\n' << '\n';
}

Wuerfel spielerWuerfelt()
{
    srand(time(0)); //for Sleep()
    Wuerfel wuerfel;
    char wuerfeln;
    char choice;

    //Zum testen, ob der spieler den Würfel behalten will oder nicht
    bool wfEins{false};
    bool wfZwei{false};
    bool wfDrei{false};
    bool wfVier{false};
    bool wfFuenf{false};
    bool wfSechs{false};

    //1. Wurf
    cout << "Gib eine beliebige Taste ein, um zu wuerfeln: ";
    cin >> wuerfeln;;
    cin.ignore(32767, '\n');
    cout << "Wuerfeln...\n";
    wuerfel.eins = getRandomDieNumber();
    Sleep(rand() % 2000 + 1000);    //warte 1000 bis 2000 millisekunden
    wuerfel.zwei = getRandomDieNumber();
    Sleep(rand() % 2000 + 1000);
    wuerfel.drei = getRandomDieNumber();
    Sleep(rand() % 2000 + 1000);
    wuerfel.vier = getRandomDieNumber();
    Sleep(rand() % 2000 + 1000);
    wuerfel.fuenf = getRandomDieNumber();
    Sleep(rand() % 2000 + 1000);
    wuerfel.sechs = getRandomDieNumber();

    wuerfelFenster1();

    switch(wuerfel.eins)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.zwei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.drei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.vier)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.fuenf)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.sechs)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }
    wuerfelFenster2();


    cout << "Waehle fuer jeden Wuerfel, ob du ihn behalten moechtest (j/n " <<
    "oder 'a', wenn du alle behalten moechtest):\n";
    for (int wfNummer = 1; wfNummer <= 6; ++wfNummer)
    {
        do
        {
            cout << "Wuerfel #" << wfNummer << ": ";
            cin >> choice;
            if (choice != 'j' && choice != 'n' && choice != 'a')
            {
                cout << "Falsche Wahl fur Wuerfel #" << wfNummer <<
                ". Versuch's nochmal.\n";
            }

        }
        while (choice != 'j' && choice != 'n' && choice != 'a');

        if (choice != 'a')
        {
            //Prüfen, welcher Würfel behalten werden soll
            switch (wfNummer)
            {
            case 1:
                if (choice == 'j')
                    wfEins = true;
                    break;
            case 2:
                if (choice == 'j')
                    wfZwei = true;
                break;
            case 3:
                if (choice == 'j')
                    wfDrei = true;
                break;
            case 4:
                if (choice == 'j')
                    wfVier = true;
                break;
            case 5:
                if (choice == 'j')
                    wfFuenf = true;
                break;
            case 6:
                if (choice == 'j')
                    wfSechs = true;
                break;
            }
        }
        else
            return wuerfel;
    }

    //Lösche potentiell übrigen Input aus der Warteschleife
    cin.ignore(32767, '\n');

    //2. Wurf
    cout << "Wuerfeln...\n";
    if (!wfEins)
    {
        wuerfel.eins = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfZwei)
    {
        wuerfel.zwei = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfDrei)
    {
        wuerfel.drei = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfVier)
    {
        wuerfel.vier = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfFuenf)
    {
        wuerfel.fuenf = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfSechs)
    {
        wuerfel.sechs = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }

    wuerfelFenster1();

    switch(wuerfel.eins)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.zwei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.drei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.vier)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.fuenf)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.sechs)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }
    wuerfelFenster2();

    //reset wfValues
    wfEins = false;
    wfZwei = false;
    wfDrei = false;
    wfVier = false;
    wfFuenf = false;
    wfSechs = false;

    cout << "Waehle fuer jeden Wuerfel, ob du ihn behalten moechtest (j/n " <<
    "oder 'a', wenn du alle behalten moechtest):\n";
    for (int wfNummer = 1; wfNummer <= 6; ++wfNummer)
    {
        do
        {
            cout << "Wuerfel #" << wfNummer << ": ";
            cin >> choice;
            if (choice != 'j' && choice != 'n' && choice != 'a')
            {
                cout << "Falsche Wahl fur Wuerfel #" << wfNummer <<
                ". Versuch's nochmal.\n";
            }

        }
        while (choice != 'j' && choice != 'n' && choice != 'a');

        if (choice != 'a')
        {
            //Prüfen, welcher Würfel behalten werden soll
            switch (wfNummer)
            {
            case 1:
                if (choice == 'j')
                    wfEins = true;
                    break;
            case 2:
                if (choice == 'j')
                    wfZwei = true;
                break;
            case 3:
                if (choice == 'j')
                    wfDrei = true;
                break;
            case 4:
                if (choice == 'j')
                    wfVier = true;
                break;
            case 5:
                if (choice == 'j')
                    wfFuenf = true;
                break;
            case 6:
                if (choice == 'j')
                    wfSechs = true;
                break;
            }
        }
        else
            return wuerfel;
    }

    //Lösche potentiell übrigen Input aus der Warteschleife
    cin.ignore(32767, '\n');

    //3.Wurf
    cout << "Wuerfeln...\n";
    if (!wfEins)
    {
        wuerfel.eins = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfZwei)
    {
        wuerfel.zwei = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfDrei)
    {
        wuerfel.drei = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfVier)
    {
        wuerfel.vier = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfFuenf)
    {
        wuerfel.fuenf = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }
    if (!wfSechs)
    {
        wuerfel.sechs = getRandomDieNumber();
        Sleep(rand() % 2000 + 1000);
    }

    wuerfelFenster1();

    switch(wuerfel.eins)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.zwei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.drei)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.vier)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.fuenf)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }

    switch(wuerfel.sechs)    //output
    {
    case BAUTEIL_GETREIDE:
        cout << "| Getreide |";
        break;
    case BAUTEIL_HOLZ:
        cout << "|   Holz   |";
        break;
    case BAUTEIL_LEHM:
        cout << "|   Lehm   |";
        break;
    case BAUTEIL_STEIN:
        cout << "|  Stein   |";
        break;
    case BAUTEIL_WOLLE:
        cout << "|  Wolle   |";
        break;
    }
    wuerfelFenster2();

    return wuerfel;
}

