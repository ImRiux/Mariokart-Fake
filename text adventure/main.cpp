#include <iostream>
#include "Functions.h"
#include <cstdlib>
#include <ctime>
#include <random>
//#include <windows>


int playerHP{100};
int playerDMG{0};
bool isRunning{true};


using namespace std;

int main()
{
    while(isRunning)
    {
        if(chapter == 4)
        {
            while(input != 'O' && input != 'o')
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cin >> input;
            }
            drawChestUI();
            input = 'k';
            while(input != 'O' && input != 'o')
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cin >> input;
            }
        }
        else if((chapter < 4 && chapter > 0) || (chapter > 4 && chapter < 11) || (chapter > 11 && chapter <= 16))
        {
            cin >> input;
            while(input != 'W' && input != 'w')
            {
                cout << "Enter 'w' to move forwards. You cannot move freely until the tutorial ends.\n";
                cin >> input;
            }
            if(playersY < 8)
            {
                playersY++;
            }
            else
            {
                playersY = 1;
            }
        }
        else if(chapter == 11)
        {
            cin >> input;
            while(input != 'e' && input != 'E')
            {
                cout << "Enter 'E' to open your inventory.\n";
                cin >> input;
            }
            inventoryUI();
        }
        else if(chapter > 16)
        {
            input = takeInput(input);
            playersY = playerInput(playersY, input);
        }
        if(enemiesAccured == (scene - 3))
        {
            enemyAccurs = checkIfTheresEnemy(playersY, enemysY);
        }
        if(enemyAccurs)
        {
            enemiesAccured += 1;
            chapter = drawScene(chapter, scene, playersY, input, drawEnemy, enemyAccurs);
            input = takeInput(input);
            while(input != 'F' && input != 'f')
            {
                cin >> input;
                cout << "\nThe enemy has grabbed you! You can't move anymore. You'll have to fight.\n";
            }
            if(input == 'F' || input == 'f')
            {
                if((scene % 2) == 0)
                {
                    enemyHP = Zombie.health * (1 + ((scene - 3) / 10));
                    enemyDMG = Zombie.attack * (1 + ((scene - 3) / 10));
                }
                else
                {
                    enemyHP = Alien.health * (1 + ((scene - 3) / 10));
                    enemyDMG = Alien.attack * (1 + ((scene - 3) / 10));
                }
                fightActive = true;
                while(fightActive)
                {
                    fightActive = fight(enemyHP, enemyDMG, fightActive, scene);
                    if(fightActive)
                    {
                        input = takeInput(input);
                        enemyHP = fightInput(input, enemyHP, scene);
                        playerHP = calculatePlayerHP(enemyDMG, scene);
                    }
                }
            }
            if(isRunning)
            {
                drawEnemy = fightIsOver();
                enemyAccurs = fightIsOver();
                chapter = drawScene(chapter, scene, playersY, input, drawEnemy, enemyAccurs);
            }
        }
        else if(!enemyAccurs)
        {
             chapter = drawScene(chapter, scene, playersY, input, drawEnemy, enemyAccurs);
        }
        scene = calculateScene(scene, input, playersY);
    }
}

void drawChestUI()
{
    int lengthOfArrays = sizeof(ItemFound) / sizeof(ItemFound[0]);
    const int heightChestWindow{12};
    for(int rowsDrawn = 1; rowsDrawn <= heightChestWindow; rowsDrawn++)
    {
        if(rowsDrawn == 1)
        {
            cout << "----------------" << endl;
        }
        else if(rowsDrawn == 2)
        {
            cout << "|              |" << "\tWow look you found a common dagger and an apple! They have been sent to your inventory." << endl;
        }
        else if(rowsDrawn == 11)
        {
            cout << "|              |" << "\tNow close the chest again with 'O'" << endl;
        }
        else if(rowsDrawn == 12)
        {
            cout << "----------------" << endl;
        }
        else if(rowsDrawn >= 3 && rowsDrawn <= 10)
        {
            currentID = nextID(currentID, lengthOfArrays);
            if(rowsDrawn == 3)
            {
                currentID -= 1;
            }
            if(currentID < lengthOfArrays && ItemFound[currentID] == false)
            {
                 while(ItemFound[currentID] == false)
                 {
                     ++currentID;
                 }
            }
            cout << "| - ";
            if(currentID < lengthOfArrays && ItemFound[currentID] == true)
            {
                printItemName(currentID, rowsDrawn);
            }
            else
            {
                printRestLine(0, false, rowsDrawn, invY);
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

int fightInput(char input, int enemyHP, int scene)
{
    if(input == 'E' || input == 'e')
    {
        inventoryUI();
        return enemyHP;
    }
    else if((input == 'R' && scene > 3) || (input == 'r' && scene > 3))
    {
        srand(time(0));
        int rdmNumber = rand();
        if(rdmNumber <= 6552)
        {
            fightActive = false;
        }
        return enemyHP;
    }
    else if((input == 'R' && scene <= 3) || (input == 'r' && scene <= 3))
    {
        cout << "\n" << "You cannot run away from your first fight!" << "\n";
        return enemyHP;
    }
    else if(input == 'A' || input == 'a')
    {
        enemyHP = calculateEnemyHP(enemyHP);
        return enemyHP;
    }
    // if(input != 'E' || input != 'P' || input != 'R')
    else
    {
        std::cin.clear();
        std::cin.ignore(32767,'\n');
        cout << "\n" << "Error: invalid input" << "\n" << "Enter 'A' or 'a' to attack the enemy" << "\n" << "Enter 'R' or 'r' to try and run away" <<
                "\n" << "Enter 'E' or 'e' to open your inventory" << "\n";
        input = takeInput(input);
        fightInput(input, enemyHP, scene);
    }
}

int drawScene(int chapter, int scene, int playersY, char input, bool drawEnemy, bool enemyAccurs)
{
    const int heightOfWindow{8};

    for(int rowsDrawn = heightOfWindow; rowsDrawn >= 1; rowsDrawn--)
    {
        if(enemyAccurs && rowsDrawn == 7)
        {
                drawPlayerLine(playersY);
                cout << "       " << "Press 'F' to fight the enemy";
                cout << "\n";
        }
        if(checkIfTheresATree(rowsDrawn)) // if there is no tree in the line this will be executed
        {
            if(scene > 2 && rowsDrawn == enemysY && drawEnemy == true)
            {
                cout << "------|X|-------" << endl;
            }
            else if(rowsDrawn != playersY && rowsDrawn != 5)
            {
                cout << "------| |-------" << endl;
            }
            else if(rowsDrawn != playersY && rowsDrawn == 5 )
            {
                cout << "------| |-------";
                displayStory(chapter);
                cout << "\n";
            }
            else if(rowsDrawn == playersY && rowsDrawn == 5 && enemyAccurs == false)
            {
                drawPlayerLine(playersY);
                displayStory(chapter);
                cout << "\n";
            }
            else if(rowsDrawn == playersY && rowsDrawn != 5 && enemyAccurs == false)
            {
                drawPlayerLine(playersY);
            }
        }
        else if((scene % 2) == 0)
        {
            drawTreeRight(rowsDrawn, playersY);
        }
        else if((scene % 2) != 0)
        {
            drawTreeLeft(rowsDrawn, playersY);
        }
    }
    cout << "\n";
    return chapter + 1;

}

char takeInput(char input)
{
    cin >> input;
    return input;
}

int calculateScene(int scene, int input, int playersY)
{
    if(input == 'w' && playersY == 8)
    {
        scene += 1;
        drawEnemy = true;
    }
    else if(input == 's' && playersY == 1)
    {
        scene -= 1;
    }
    return scene;
}

void displayHelp()
{
    cout << "\n" << "Enter w/W to move up" << "\n" << "Enter s/S to move down" << "\n" << "Enter e/E to open your inventory" << "\n";
}

int playerInput(int playersY, int input) {

    if((input == 'w' && playersY < 8) || (input == 'W' && playersY < 8))
    {
        playersY += 1;
        return playersY; // 'w' makes the player move forward thus increase the ypos by one
    }
    else if((input == 'w' && playersY == 8) || (input == 'W' && playersY == 8))
    {
        playersY = 1;
        return playersY;
    }
    else if((input == 's' && playersY > 1) || (input == 'S' && playersY > 1))
    {
        playersY -= 1;
        return playersY; // 's' makes the player move backwards thus decrease the ypos by one
    }
    else if((input == 's' && playersY == 1) || (input == 'S' && playersY == 1))
    {
        playersY = 8;
        return playersY;
    }
    else if(input == 'E' || input == 'e')
    {
        inventoryUI();
        return playersY;
    }
    else if(input == 'h' || input == 'H')
    {
        displayHelp();
        char input;
        cin >> input;
        playerInput(playersY, input);
    }
    else if(input != 'w' && input != 's' && input != 'W' && input != 'S' && input != 'E' && input != 'e')
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\n" << "Error: invalid input" << "\n" << "Enter h if you need help" << "\n";
        char input;
        cin >> input;
        playerInput(playersY, input);
    }
    else
    {
        return playersY;
    }
}

void drawPlayerLine(int playersY)
{
    const int playersX{8}; // The Player can only move in the Z direction thus his X and Y position always stay the same
    const int widthOfWindow{16};

    for(int spacesDrawn = 1; spacesDrawn <= widthOfWindow; spacesDrawn++)
    {
        if(spacesDrawn != playersX && spacesDrawn != playersX + 1 && spacesDrawn != playersX - 1)
        {
            cout << "-";
        }
        else if(spacesDrawn == playersX)
        {
            cout << "*"; // '*' represents the player
        }
        else if(spacesDrawn == playersX + 1 || spacesDrawn == playersX - 1)
        {
            cout << "|";
        }
    }
    if(playersY != 5 && enemyAccurs == false)
    {
        cout << "\n";
    }
}

void displayStory(int chapter)
{
    switch(chapter)
    {
        case 0:
        {
            cout << "\t" << "This is the beginning of your adventure! Are you excited?" << " Enter w to move up";
            break;
        }
        case 1:
        {
            cout << "\t" << "You're doing great! Keep moving up, maybe we'll discover something interesting.";
            break;
        }
        case 2:
        {
            cout << "\t" << "Look there's a chest on the road";
            break;
        }
        case 3:
        {
            cout << "\t" << "Enter 'O' to open the chest";
            break;
        }
        case 9:
        {
            cout << "\t" << "Oh no! Look there's an enemy! I think you'll have to approach him.";
            break;
        }
        case 10:
        {
            cout << "\t" << "Wait! What if he's gonna fight you? You need to equip a weapon. Enter E to open your inventory.";
            break;
        }
        case 11:
        {
            cout << "\t" << "Great now that you're armed you're ready to take him on.";
            break;
        }
        case 13:
        {
            cout << "\t" << "Go ahead and walk up to him";
            break;
        }
        case 17:
        {
            cout << "\t" << "Great! You won! Now open your inventory again to see what he dropped";
            break;
        }
        default:
        {
            cout << "";
            break;
        }
    }
}

bool checkIfTheresATree(int rowsDrawn)
{
    bool theresNoTree{true};
    int treesY{2};
    if(rowsDrawn >= treesY && rowsDrawn < (treesY + 4))
    {
        return theresNoTree = false;
    }
    else
    {
        return theresNoTree = true;
    }
}

bool checkIfTheresEnemy(int playersY,int enemysY)
{
    bool thereIsEnemy{false};
    if(playersY == (enemysY - 1) && scene > 2)
    {
        thereIsEnemy = true;
        return thereIsEnemy;
    }
    else
    {
        thereIsEnemy = false;
        return thereIsEnemy;
    }
}
void drawTreeRight(int rowsDrawn, int playersY)
{
    if(rowsDrawn == 2)
                {
                    switch(playersY)
                    {
                        case 2:
                            {
                                cout << "------|*|--" << "  ||  " << endl;
                                break;
                            }
                        default:
                            {
                                cout << "------| |--" << "  ||  " << endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 3)
                {
                    switch(playersY)
                    {
                        case 3:
                            {
                                cout << "------|*|--" << "\\____/" << endl;
                                break;
                            }
                        default:
                            {
                                cout << "------| |--" << "\\____/" << endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 4)
                {
                    switch(playersY)
                    {
                        case 4:
                            {
                                cout << "------|*|--" << "/    \\"<< endl;
                                break;
                            }
                        default:
                            {
                                cout << "------| |--" << "/    \\"<< endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 5)
                {
                    if(chapter < 4)
                    {
                        char chest = 254;
                        cout << "------|"<< chest << "|--" << " ____";
                        displayStory(chapter);
                        cout << "\n";
                    }
                    else
                    {
                        switch(playersY)
                        {
                            case 5:
                                {
                                    cout << "------|*|--" << " ____";
                                    displayStory(chapter);
                                    cout << "\n";
                                    break;
                                }
                            default:
                                {
                                    cout << "------| |--" << " ____";
                                    displayStory(chapter);
                                    cout << "\n";
                                    break;
                                }
                        }
                    }
                }
}

void drawTreeLeft(int rowsDrawn, int playersY)
{
    if(rowsDrawn == 2)
                {
                    switch(playersY)
                    {
                        case 2:
                            {
                                cout << "  ||  " << "|*|-------" << endl;
                                break;
                            }
                        default:
                            {
                                cout << "  ||  " << "| |-------" << endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 3)
                {
                    switch(playersY)
                    {
                        case 3:
                            {
                                cout <<  "\\____/" <<  "|*|-------" << endl;
                                break;
                            }
                        default:
                            {
                                cout <<  "\\____/" <<  "| |-------" << endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 4)
                {
                    switch(playersY)
                    {
                        case 4:
                            {
                                cout << "/    \\" << "|*|-------" <<  endl;
                                break;
                            }
                        default:
                            {
                                cout << "/    \\" << "| |-------" <<  endl;
                                break;
                            }
                    }
                }
                else if(rowsDrawn == 5)
                {
                    switch(playersY)
                    {
                        case 5:
                            {
                                cout << " ____ " << "|*|-------";
                                displayStory(chapter);
                                cout << "\n";
                                break;
                            }
                        default:
                            {
                                cout << " ____ " << "| |-------";
                                displayStory(chapter);
                                cout << "\n";
                                break;
                            }
                    }
                }
}

void drawVictory()
{
char bigBox = 219;
char smallUpperBox = 223;
char smallBottomBox = 220;
// Line One starts
cout << "\t" << bigBox << bigBox << "         " << bigBox << bigBox /*first Line of V*/ << "  " << smallUpperBox << bigBox << bigBox << smallUpperBox /*first Line of I*/ << "      " << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox
    /*first Line of C*/ << "    " << bigBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << bigBox /*first Line of T*/ << "      " <<
    smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox << smallBottomBox /*first Line of O*/ << "     " << smallUpperBox << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox <<
    smallBottomBox /*first Line of R*/ << "   " << smallUpperBox << bigBox << smallBottomBox << "        " << smallBottomBox << bigBox << smallUpperBox /*first Line of Y*/ << "\n";
// Line One ends
// Line Two starts
cout << "\t" << bigBox << bigBox << "         " << bigBox << bigBox /*second Line of V*/ << "   " << bigBox << bigBox /*second Line of I*/ << "      " << bigBox << bigBox << "    " << bigBox /*second Line of C*/ << "   " << bigBox << smallUpperBox << smallUpperBox <<
    smallUpperBox << smallUpperBox << bigBox << bigBox << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox << bigBox /*second Line of T*/ << "     " << bigBox << bigBox << "      " << bigBox << bigBox /*second Line of O*/ << "     " << bigBox <<
    bigBox << "     " << smallUpperBox << bigBox << bigBox /*second Line of R*/ << "   " << bigBox << bigBox << "        " << bigBox << bigBox /*second Line of Y*/ << "\n";
// Line Two ends
// Line Three starts
cout << "\t" << smallUpperBox << bigBox << bigBox << "       " << bigBox << bigBox << smallUpperBox /*third Line of V*/ << "   " << bigBox << bigBox /*third Line of I*/ << "     " << bigBox << bigBox /*third Line of C*/ << "              " << bigBox << bigBox
    /*third Line of T*/ << "         " << bigBox << bigBox << "        " << bigBox << bigBox /*third Line of O*/ << "    " << bigBox << bigBox << "      " << bigBox << bigBox /*third Line of R*/ << "    " << bigBox << bigBox << "      " << bigBox << bigBox << "\n";
// Line Three ends
// Line Four starts
cout << "\t" << " " << bigBox << bigBox << "       " << bigBox << bigBox /*fourth Line of V*/ << "    " << bigBox << bigBox /*fourth Line of I*/ << "    " << bigBox << bigBox /*fourth Line of C*/ << "               " << bigBox << bigBox /*fourth Line of T*/ << "        " <<
    bigBox << bigBox << "          " << bigBox << bigBox /*fourth Line of O*/ << "   " << bigBox << bigBox << "     " << smallBottomBox << bigBox << bigBox /*fourth Line of R*/ << "    " << smallUpperBox << bigBox << smallBottomBox << "    " << smallBottomBox << bigBox <<
    smallUpperBox /*fourth Line of Y*/ << "\n";
// Line Four ends
// Line Five starts
cout << "\t" << " " << bigBox << bigBox << "       " << bigBox << bigBox /*fifth Line of V*/ << "    " << bigBox << bigBox /*fifth Line of I*/ << "    " << bigBox << bigBox /*fifth Line of C*/ << "               " << bigBox << bigBox /*fifth Line of T*/ << "        " <<
    bigBox << bigBox << "          " << bigBox << bigBox /*fifth Line of O*/ << "   " << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox << bigBox << smallUpperBox /*fifth Line of R*/ << "       " << smallUpperBox << bigBox << bigBox << bigBox << bigBox <<
    smallUpperBox << "\n";
// Line Five ends
// Line Six starts
cout << "\t" << " " << smallUpperBox << bigBox << bigBox << "     " << bigBox << bigBox << smallUpperBox /*sixth Line of V*/ << "    " << bigBox << bigBox /*sixth Line of I*/ << "    " << bigBox << bigBox /*sixth Line of C*/ << "               " <<
    bigBox << bigBox /*sixth Line of T*/ << "        " << bigBox << bigBox << "          " << bigBox << bigBox /*sixth Line of O*/ << "   " << bigBox << bigBox << bigBox /*sixth Line of R*/ << "               " << bigBox << bigBox /*sixth Line of Y*/ << "\n";
// Line Six ends
// Line Seven starts
cout << "\t" << "  " << bigBox << bigBox << "     " << bigBox << bigBox /*seventh Line of V*/ << "     " << bigBox << bigBox /*seventh Line of I*/ << "    " << bigBox << bigBox /*seventh Line of C*/ << "               " << bigBox << bigBox /*seventh Line of T*/ <<
    "        " << bigBox << bigBox << "          " << bigBox << bigBox /*seventh Line of O*/ << "   " << bigBox << bigBox << bigBox << bigBox << smallBottomBox /*seventh Line of R*/ << "             " << bigBox << bigBox /*seventh Line of Y*/ << "\n";
// Line Seven ends
// Line Eight starts
cout << "\t" << "  " << bigBox << bigBox << "     " << bigBox << bigBox /*eighth Line of V*/ << "     " << bigBox << bigBox /*eighth Line of I*/ << "    " << bigBox << bigBox /*eighth Line of C*/ << "               " << bigBox << bigBox /*eighth Line of T*/ << "        " <<
    bigBox << bigBox << "          " << bigBox << bigBox /*eighth Line of O*/ << "   " << bigBox << bigBox << " " <<  bigBox << bigBox /*eighth Line of R*/ << "             " << bigBox << bigBox /*eighth Line of Y*/ << "\n";
// Line Eight ends
// Line Nine starts
cout << "\t" << "  " << smallUpperBox << bigBox << bigBox << "   " << bigBox << bigBox << smallUpperBox /*ninth Line of V*/ << "     " << bigBox << bigBox /*ninth Line of I*/ << "    " << bigBox << bigBox /*ninth Line of C*/ << "               " <<
    bigBox << bigBox /*ninth Line of T*/ << "        " << bigBox << bigBox << "          " << bigBox << bigBox /*ninth Line of O*/ << "   " << bigBox << bigBox << " " <<  bigBox << bigBox /*ninth Line of R*/ << "             " << bigBox << bigBox /*ninth Line of Y*/ << "\n";
// Line Nine ends
// Line Ten starts
cout << "\t" << "   " << bigBox << bigBox << "   " << bigBox << bigBox /*tenth Line of V*/ << "      " << bigBox << bigBox /*tenth Line of I*/ << "    " << bigBox << bigBox /*tenth Line of C*/ << "               " << bigBox << bigBox /*tenth Line of T*/ << "        " <<
    bigBox << bigBox << "          " << bigBox << bigBox /*tenth Line of O*/ << "   " << bigBox << bigBox << " " << smallUpperBox << bigBox << bigBox /*tenth Line of R*/ << "            " << bigBox << bigBox /*tenth Line of Y*/ << "\n";
// Line Ten ends
// Line Eleven starts
cout << "\t" << "   " << smallUpperBox << bigBox << bigBox << " " << bigBox << bigBox << smallUpperBox /*eleventh Line of V*/ << "      " << bigBox << bigBox /*eleventh Line of I*/ << "     " << bigBox << bigBox /*eleventh Line of C*/ << "              " <<
    bigBox << bigBox /*eleventh Line of T*/ << "         " << bigBox << bigBox << "        " << bigBox << bigBox /*eleventh Line of O*/ << "    " << bigBox << bigBox << "  " << bigBox << bigBox << smallBottomBox  /*eleventh Line of R*/ << "           " <<
    bigBox << bigBox /*eleventh Line of Y*/ << "\n";
// Line Eleven ends
// Line Twelve starts
cout << "\t" << "    " << bigBox << bigBox << " " << bigBox << bigBox /*twelve Line of V*/ << "       " << bigBox << bigBox /*twelve Line of I*/ << "      " << bigBox << bigBox << "    " << bigBox /*twelve Line of C*/ << "        " << bigBox << bigBox /*twelve Line of T*/
    << "          " << bigBox << bigBox << "      " << bigBox << bigBox /*twelve Line of O*/ << "     " << bigBox << bigBox << "   " << bigBox << bigBox /*twelve Line of R*/ << "           " << bigBox << bigBox /*twelve Line of Y*/ << "\n";
// Line Twelve ends
// Line Thirteen starts
cout << "\t" << "    " << smallUpperBox << bigBox << bigBox << bigBox << smallUpperBox /*thirteenth Line of V*/ << "      " << smallBottomBox << bigBox << bigBox << smallBottomBox /*thirteenth Line of I*/ << "      " << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox;
cout << smallUpperBox /*thirteenth Line of C*/ << "        " << smallBottomBox << bigBox << bigBox << smallBottomBox /*thirteenth Line of T*/ << "          " << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox << smallUpperBox;
cout << smallUpperBox /*thirteenth Line of O*/ << "     " << smallBottomBox << bigBox << smallUpperBox << "    " << smallUpperBox << bigBox << smallBottomBox /*thirteenth Line of R*/ << "        " << smallBottomBox << bigBox << bigBox << smallBottomBox/*thirteenth Line of Y*/ << "\n";
// Line Thirteen ends
}

bool fight(int enemyHP, int enemyDMG, bool fightActive, int scene)
{
    drawFightScene(enemyHP);
    if(playerHP <= 0)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t\t" << "Game over" << endl;
        endProgram();
        fightActive = false;
        return fightActive;
    }
    if(enemyHP <= 0)
    {
        fightActive = false;
        cout << "\n\n\n\n\n\n\n\n\n\n";
        drawVictory();
        cout << "\n\n\n";
        playerHP += 10;
        givePlayerLoot();
        return fightActive;
    }
}

void endProgram()
{
    isRunning = false;
}

bool fightIsOver()
{
    return drawEnemy = false;
}

int getRandomNumber(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 mersenne{ rd() };
	static const double fraction = 1.0 / (mersenne.max() + 1.0);
	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}

void givePlayerLoot()
{
    int number = getRandomNumber(1, 100);
    if(number > 0 && number <= 30)
    {
        ItemFound[0] = true; // Apple
    }
    else if(number > 30 && number <= 40)
    {
        ItemFound[1] = true; // Potion
    }
    else if(number > 40 && number <= 50)
    {
        ItemFound[2] = true; // Common Sword
    }
    else if(number > 50 && number <= 60)
    {
        ItemFound[5] = true; // Common Axe
    }
    else if(number > 60 && number <= 70)
    {
        ItemFound[8] = true; // Common Dagger
    }
    else if(number > 70 && number <= 77)
    {
        ItemFound[3] = true; // Rare Sword
    }
    else if(number > 77 && number <= 84)
    {
        ItemFound[6] = true; // Rare Axe
    }
    else if(number > 84 && number <= 90)
    {
        ItemFound[9] = true; // Rare Dagger
    }
    else if(number > 90 && number <= 93)
    {
        ItemFound[4] = true; // Legendary Sword
    }
    else if(number > 93 && number <= 96)
    {
        ItemFound[7] = true; // Legendary Axe
    }
    else if(number > 96 && number <= 100)
    {
        ItemFound[10] = true; // Legendary Dagger
    }
}

void drawFightScene(int enemyHP)
{
    const int heightFightWindow{12};

    for(int rowsDrawn = 1; rowsDrawn <= heightFightWindow; rowsDrawn++)
    {
        switch(rowsDrawn)
        {
            case 1:
            {
                cout << "\n" << "----------------" << "     " << "What do you want to do?" << endl;
                break;
            }case 2:
            {
                cout << "|              |" << "     " << "Press A to attack the enemy" << endl;
                break;
            }case 3:
            {
                cout << "|     ____     |" << "     " << "Press R to try and run away" << endl;
                break;
            }case 4:
            {
                cout << "|    / oo \\    |" << "     " << "Press E to enter your inventory" << endl;
                break;
            }case 5:
            {
                cout << "|    \\____/    |" << endl;
                break;
            }case 6:
            {
                cout << "|   \\  ||  /   |" << endl;
                break;
            }case 7:
            {
                cout << "|    \\_||_/    |" << endl;
                break;
            }case 8:
            {
                cout << "|    |    |    |" << endl;
                break;
            }case 9:
            {
                cout << "|    |____|    |" << endl;
                break;
            }case 10:
            {
                cout << "|     |  |     |" << endl;
                break;
            }case 11:
            {
                cout << "|              |" << "     " << "Your HP: " << playerHP << endl;
                break;
            }case 12:
            {
                cout << "----------------" << "     " << "The enemy's HP: " << enemyHP << endl;
                break;
            }
        }
    }
}

int calculatePlayerHP(int enemyDMG, int scene)
{
    playerHP -= enemyDMG;
    return playerHP;
}

int calculateEnemyHP(int enemyHP)
{
        enemyHP -= playerDMG;
        if(enemyHP < 0)
            enemyHP = 0;
        return enemyHP;
}

void inventoryUI()
{
    int lengthOfArrays = sizeof(ItemFound) / sizeof(ItemFound[0]);
    const int heightInventoryWindow{12};
    bool inInventory{true};
    while(inInventory)
    {
        currentID = 0;
        for(int rowsDrawn = 1; rowsDrawn <= heightInventoryWindow; rowsDrawn++)
        {
            if(rowsDrawn == 1)
            {
                cout << "----------------" << "\tEnter w/s to move up or down" << endl;
            }
            else if(rowsDrawn == 2)
            {
                cout << "|              |" << "\tEnter 'U' to use the selected item | Enter 'T' to throw the item away | Enter 'h' for more help" << endl;
            }
            else if(rowsDrawn == 12)
            {
                cout << "----------------" << endl;
            }
            else if(rowsDrawn >= 3 && rowsDrawn <= 10)
            {
                currentID = nextID(currentID, lengthOfArrays);
                if(rowsDrawn == 3)
                {
                    currentID -= 1;
                }
                if(ItemFound[currentID] == false)
                {
                     while(ItemFound[currentID] == false && currentID < lengthOfArrays)
                     {
                         ++currentID;
                     }
                }
                if(rowsDrawn == invY)
                    cout << "| ->";
                else
                    cout << "| - ";

                if(currentID < lengthOfArrays && ItemFound[currentID] == true)
                {
                    printItemName(currentID, rowsDrawn);
                    if(rowsDrawn == invY)
                    {
                        printItemInfo(currentID);
                    }
                }
                else
                {
                    printRestLine(0, false, rowsDrawn, invY);
                }
                cout << "\n";
            }
            else if(rowsDrawn == 11)
            {
                cout << "|              |" << endl;
            }
        }
        cout << "\n";
        invY = invInput();
        if(invY > 50 && invY < 100) // invY is normally between 3 and 10 and this checks if the user pressed 'E' which adds 50 to invY. Pressing 'U' adds 100
        {
            invY -= 50;
            inInventory = false;
        }
        else if(invY > 100 && invY < 200) // In an earlier version of this program I couldn't change the playersHP or playersDMG from a function and couldn't return the input (e.g. 'U') to this function,
        {                   // so I check invY and if it's at a value that the player couldn't reach moving up or down in the inventory, I subtract the value I added and then execute the action that should happen when u enter 'U'.
            invY -= 100;
            int displayedItem{0};
            for(int ID = 0; ID < lengthOfArrays; ID++) // The loop cycles through the array of Items
            {
                if(ItemFound[ID]) // If the Item it's currently at in the array is found (-> ItemFound[ID] would be true)
                {
                    displayedItem++; // Keeps track of how many Items have been displayed in the inventory (since only Items that have been found are displayed)
                    if((displayedItem + 2) == invY) // The first Item is displayed in line 3 so we need to add 2 to displayedItems because invY in line 3 is 3..
                    {
                        if(ItemKind[ID] == "Food")
                        {
                            playerHP += (1 * ItemEffectiveness[ID]);
                            if(playerHP > 100)
                                playerHP = 100;
                        }
                        else if(ItemKind[ID] == "Weapon")
                        {
                            playerDMG = (1 * ItemEffectiveness[ID]);
                        }
                        ItemFound[ID] = false; // After using the Item it shouldn't be in the inventory anymore obviously
                    }
                }
            }
        }
        else if(invY > 200)
        {
            invY -= 200;
            int displayedItem{0};
            for(int ID = 0; ID < lengthOfArrays; ID++) // The loop cycles through the array of Items
            {
                if(ItemFound[ID]) // If the Item it's currently at in the array is found (-> ItemFound[ID] would be true)
                {
                    displayedItem++; // Keeps track of how many Items have been displayed in the inventory (since only Items that have been found are displayed)
                    if((displayedItem + 2) == invY) // The first Item is displayed in line 3 so we need to add 2 to displayedItems because invY in line 3 is 3..
                    {
                        ItemFound[ID] = false; // After throwing the Item away it shouldn't be in the inventory anymore obviously
                    }
                }
            }
        }
    }
}

int nextID(int currentID, int lengthOfArrays)
{
     if(currentID <= lengthOfArrays)
     {
         ++currentID;
     }
     return currentID;
}

void printRestLine(int lettersPrinted, bool printedName, int rowsDrawn, int invY)
{
    if(printedName)
    {
       for(int spacesLeft = 11 - lettersPrinted; spacesLeft > 0; spacesLeft--)
        {
                cout << " ";
        }
        cout << "|";
    }
    else
    {
        for(int spacesLeft = 11; spacesLeft > 0; spacesLeft--)
        {
                cout << " ";
        }
        cout << "|";
    }
}

void printItemName(int currentID, int rowsDrawn)
{
    bool hasntPrintedName{true};
    int lettersPrinted{0};
    while(hasntPrintedName)
    {
        for(lettersPrinted = 0; lettersPrinted < 255; lettersPrinted++)
        {
            if(ItemNames[currentID][lettersPrinted] != '/')
            {
                cout << ItemNames[currentID][lettersPrinted];
            }
            else if(ItemNames[currentID][lettersPrinted] == '/')
            {
                printRestLine(lettersPrinted, true, rowsDrawn, invY);
                lettersPrinted = 255;
            }
        }
        hasntPrintedName = false;
    }
}

void printItemInfo(int currentID)
{
    if(ItemFound[currentID])
    {
        cout << "\t" << ItemUse[currentID];
    }

}

int invInput()
 {
    char input;
    cin >> input;
    if((input == 'w' && invY  > 3) || (input == 'W' && invY  > 3))
    {
        --invY;
        return invY;
    }
    else if((input == 's' && invY < 10) || (input == 'S' && invY < 10))
    {
        ++invY;
        return invY;
    }
    else if(input == 'E' || input == 'e')
    {
        invY += 50;
        return invY;
    }
    else if(input == 'U' || input == 'u')
    {
        invY += 100;
        return invY;
    }
    else if(input == 'T' || input == 't')
    {
        invY += 200;
        return invY;
    }
    else if(input == 'H' || input == 'h')
    {
        cout << "\n" << "| ->           | \t The arrow on the left indicates the row you are currently in." << "\n" << "To move to the row above enter 'w'; To move to the row below enter 's'" <<
                "\n" << "| -> Apple     |        Restores 20 HP \t || The information next to the inventory screen \n(for example 'Restores 20 HP') tells you what the selected item does when you use it (enter 'U').\n" <<
                "\n" << "There are two types of items: Weapons and Healthboosters. Weapons set your DMG \n(the damage you deal to enemies when attacking them once) to a certain value, \nwhich is displayed when you select the item." <<
                "\n" << "Healthboosters increase your health, the amount is, again, displayed when the item is selected.\n" <<
                "\n" << "You can only carry one apple at a time (applies for every other item too), so use them, don't hoard them." << "\n\n\n";
        return invY;
    }
    else
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "\nError invalid input. \n" << "Enter 'E' to exit the inventory \n" << "Enter 'W' to move up \n" << "Enter 'S' to move down \n" << "Enter 'U' to use an item \n";
        invInput();
    }
}
