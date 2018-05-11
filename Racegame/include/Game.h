#ifndef GAME_H
#define GAME_H
#include "Player.h"
//forward declarations
void setCursor(int x, int y);
void showConsoleCursor(bool showFlag);
std::string spaceForCharacters(int length);

enum Mode {MODE_DONT_HIT_WALL, MODE_6_ROUNDS};

//used for displaying the map and printing the symbols
typedef unsigned const char UCC;
UCC P_BLOCK = 219;
UCC P_SPACE = 32;
UCC P_CHECKPOINT = 32;
UCC BLOCK = 'b';
UCC SPACE = 's';
UCC C1_P1 = 'p';
UCC C2_P1 = 'l';
UCC C3_P1 = 'm';
UCC C1_P2 = 'n';
UCC C2_P2 = 'j';
UCC C3_P2 = 'g';

UCC CAR_DOLLAR = 36;
UCC CAR_STAR = 42;
UCC CAR_CROSS = 158;
UCC CAR_YEN = 190;

const int mapHeight = 25;
const int mapLength = 86;
const unsigned char map_[mapHeight][mapLength] =
	{        //0     1      2      3      4      5      6      7      8      9      10     11     12     13     14     15     16     17     18     19     20     21     22     23     24     25     26     27     28     29     30     31     32     33     34     35     36     37     38     39
	/*0*/    {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*1*/    {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, C1_P1, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, C1_P2, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*2*/    {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*3*/    {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, C1_P1, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, C1_P2, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*4*/    {BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*5*/    {BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*6*/    {BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*7*/    {BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*8*/    {BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*9*/    {BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*10*/   {BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*11*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*12*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*13*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*14*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*15*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*16*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, C2_P1, C2_P1, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, C2_P2, C2_P2, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*17*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK},
	/*18*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK},
	/*19*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK},
	/*20*/   {BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK},
	/*21*/   {BLOCK, C3_P1, C3_P1, C3_P1, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, C3_P2, C3_P2, C3_P2, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, BLOCK, BLOCK},
	/*22*/   {BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, BLOCK, BLOCK},
	/*23*/   {BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK},
	/*24*/   {BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK, BLOCK}
	};

class Game {
    private:
        Mode m_mode;
        Player m_player1;
        Player m_player2;

        bool m_running = true;
        bool m_p1c1 = false;
        bool m_p1c2 = false;
        bool m_p1c3 = false;
        bool m_p2c1 = false;
        bool m_p2c2 = false;
        bool m_p2c3 = false;

        void setMode();
        void setName(Player &player);
        void setCar(Player &player);
        void drawMap();
        void drawControls();
        void movement();
        void checkCheckpoints();
    public:
        Game();
        virtual ~Game();
        void runGame();
};

#endif // GAME_H
