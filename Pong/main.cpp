#include <iostream>
#include "Score.h"
#include "Ball.h"
#include "Player.h"
#include "windows.h"
#include "SetCursorPosition.h"
#include <fstream>
#include "stdio.h"
#include "Intro.h"
#include "AI.h"

using namespace std;

void GameLoop();
void Setup();
int charToInt(char input);

int main()
{
    Setup();
    GameLoop();
}

void GameLoop()
{
	while(true)
    {
        if(Gamemode)
        {
            Player2.playerScore.drawScore();
            Player2.draw();
            Player2.input();
            Player2.Erase();
        }
        else
        {
            AI();
//            if(Player2.playerScore.getScore() == 10)  // Work in Progress
//            {
//                ofstream SaveScore;
//                ifstream ReadScore;
//                ReadScore.open("Highscores.txt");
//                char scores[100];
//                int scoresInt[100];
//                ReadScore >> scores;
//                ReadScore >> scoresInt;
//                int Max{0};
//                for(int i = 0; i < 100; ++i)
//                {
//
//                }
//            }
        }
        Player1.playerScore.drawScore();
        Player1.draw();
        Player1.input();
        Player1.Erase();
        Ball.update(Player1.getPosX(), Player1.getPosY(), Player2.getPosX(), Player2.getPosY());
        Sleep(30);
        if(Ball.getBallPosX() < Player1.getPosX())
        {
            Player2.score();
            Ball.respawn();
        }

        if(Ball.getBallPosX() > Player2.getPosX())
         {
            Player1.score();
            Ball.respawn();
        }
    }
}

