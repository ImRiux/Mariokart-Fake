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
#include <vector>
#include <algorithm>
//#include <array>

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
            if(Player1.playerScore.getScore() >= 10 || Player2.playerScore.getScore() >= 10 )
            {
                std::ifstream ReadLength;
                ReadLength.open("Multiplayer/amountOfNames.txt");
                int length;
                ReadLength >> length;
                ReadLength.close();
                std::vector<std::string> listOfNames { };
                listOfNames.resize(length);
                std::ifstream SearchName;
                SearchName.open("Multiplayer/Names.txt");
                for(int i = 0; i < length; ++i)
                {
                    std::string tempName;
                    SearchName >> tempName;
                    listOfNames[i] = tempName;
                }
                SearchName.close();
                int indexPlayer1{0}, indexPlayer2{0};
                bool Player1OnList{false}, Player2OnList{false};
                for(int i = 0; i < length; i++)
                {
                    if(listOfNames[i] == Player1.getName()) { indexPlayer1 = i; Player1OnList = true; }
                    if(listOfNames[i] == Player2.getName()) { indexPlayer2 = i; Player2OnList = true; }
                }
                if(!Player1OnList) { ++length; listOfNames.resize(length); indexPlayer1 = (length - 1); listOfNames[indexPlayer1] = Player1.getName(); }
                if(!Player2OnList) { ++length; listOfNames.resize(length); indexPlayer2 = (length - 1); listOfNames[indexPlayer2] = Player2.getName(); }
                std::ifstream ReadWins;
                ReadWins.open("Multiplayer/Wins.txt");
                std::vector<int> playerWins { 0 };
                playerWins.resize(length);
                for(int i = 0; i < length; ++i)
                {
                    int tempWin;
                    ReadWins >> tempWin;
                    playerWins[i] = tempWin;
                }
                ReadWins.close();
                if(!Player1OnList) { playerWins[indexPlayer1] = 0; }
                if(!Player2OnList) { playerWins[indexPlayer2] = 0; }
                std::ifstream ReadLosses;
                ReadLosses.open("Multiplayer/Losses.txt");
                std::vector<int> playerLosses { 0 };
                playerLosses.resize(length);
                for(int i = 0; i < length; ++i)
                {
                    int tempLoss;
                    ReadLosses >> tempLoss;
                    playerLosses[i] = tempLoss;
                }
                ReadLosses.close();
                if(!Player1OnList) { playerLosses[indexPlayer1] = 0; }
                if(!Player2OnList) { playerLosses[indexPlayer2] = 0; }
                if(Player1.playerScore.getScore() >= 10) { playerWins[indexPlayer1] += 1; playerLosses[indexPlayer2] += 1; }
                if(Player2.playerScore.getScore() >= 10) { playerWins[indexPlayer2] += 1; playerLosses[indexPlayer1] += 1; }
                for (int startIndex = 0; startIndex < (length - 1); ++startIndex)
                {
                    int biggestIndex = startIndex;
                    for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
                    {
                        if(playerWins[currentIndex] > playerWins[biggestIndex])
                            biggestIndex = currentIndex;
                    }
                    std::swap(playerWins[startIndex], playerWins[biggestIndex]);
                    std::swap(playerLosses[startIndex], playerLosses[biggestIndex]);
                    std::swap(listOfNames[startIndex], listOfNames[biggestIndex]);
                }
                std::ofstream WriteNames;
                WriteNames.open("Multiplayer/Names.txt");
                for(int i = 0; i < length; ++i)
                {
                    std::string tempName;
                    tempName = listOfNames[i];
                    WriteNames << tempName;
                    WriteNames << " ";
                }
                std::ofstream WriteLength;
                WriteLength.open("Multiplayer/amountOfNames.txt");
                WriteLength << length;
                WriteLength.close();
                WriteNames.close();
                std::ofstream WriteWins;
                WriteWins.open("Multiplayer/Wins.txt");
                for(int i = 0; i < length; ++i)
                {
                    int tempWin;
                    tempWin = playerWins[i];
                    WriteWins << tempWin;
                    WriteWins << " ";
                }
                WriteWins.close();
                std::ofstream WriteLosses;
                WriteLosses.open("Multiplayer/Losses.txt");
                for(int i = 0; i < length; ++i)
                {
                    int tempLoss;
                    tempLoss = playerLosses[i];
                    WriteLosses << tempLoss;
                    WriteLosses << " ";
                }
                WriteLosses.close();
                system("cls");
                drawFrame(70, 20, 25, 3);
                setCursorPosition(57, 5);
                std::cout << "by Wins";
                int xCoords{30}, yCoords{9};
                for(int k = 0; k < 10; k++)
                {
                    if(k >= length) break;
                    xCoords = 37;
                    setCursorPosition(xCoords, yCoords);
                    std::cout << listOfNames[k];
                    xCoords = 80;
                    setCursorPosition(xCoords, yCoords);
                    std::cout << playerWins[k];
                    yCoords++;
                }
                setCursorPosition(55, 20);
                std::cout << "Try again?";
                setCursorPosition(44, 21);
                std::cout << "Press Y for 'yes' and N for 'no'";
                setCursorPosition(0, 28);
                char playerInput;
                while(playerInput != 'y' && playerInput != 'n')
                {
                    playerInput = '0';
                    if(_kbhit()) playerInput = _getch();
                    if(playerInput == 'w') // Sorts Leaderboard by Wins
                    {
                        system("cls");
                        drawFrame(70, 20, 25, 3);
                        setCursorPosition(55, 20);
                        std::cout << "Try again?";
                        setCursorPosition(44, 21);
                        std::cout << "Press Y for 'yes' and N for 'no'";
                        setCursorPosition(0, 28);
                        yCoords = 9;
                        for (int startIndex = 0; startIndex < (length - 1); ++startIndex)
                        {
                            int biggestIndex = startIndex;
                            for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
                            {
                                if(playerWins[currentIndex] > playerWins[biggestIndex])
                                    biggestIndex = currentIndex;
                            }
                            std::swap(playerWins[startIndex], playerWins[biggestIndex]);
                            std::swap(playerLosses[startIndex], playerLosses[biggestIndex]);
                            std::swap(listOfNames[startIndex], listOfNames[biggestIndex]);
                        }
                        setCursorPosition(56, 5);
                        std::cout << "by Wins";
                        for(int i = 0; i < 10; ++i)
                        {
                            if(i >= length) break;
                            xCoords = 37;
                            setCursorPosition(xCoords, yCoords);
                            std::cout << listOfNames[i];
                            xCoords = 80;
                            setCursorPosition(xCoords, yCoords);
                            std::cout << playerWins[i];
                            yCoords++;
                        }
                    }
                    if(playerInput == 'l') // Sorts Leaderboard by Losses
                    {
                        system("cls");
                        drawFrame(70, 20, 25, 3);
                        setCursorPosition(55, 20);
                        std::cout << "Try again?";
                        setCursorPosition(44, 21);
                        std::cout << "Press Y for 'yes' and N for 'no'";
                        setCursorPosition(0, 28);
                        yCoords = 9;
                        for (int startIndex = 0; startIndex < (length - 1); ++startIndex)
                        {
                            int biggestIndex = startIndex;
                            for(int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
                            {
                                if(playerLosses[currentIndex] > playerLosses[biggestIndex])
                                    biggestIndex = currentIndex;
                            }
                            std::swap(playerWins[startIndex], playerWins[biggestIndex]);
                            std::swap(playerLosses[startIndex], playerLosses[biggestIndex]);
                            std::swap(listOfNames[startIndex], listOfNames[biggestIndex]);
                        }
                        setCursorPosition(55, 5);
                        std::cout << "by Losses";
                        for(int i = 0; i < 10; ++i)
                        {
                            if(i >= length) break;
                            xCoords = 37;
                            setCursorPosition(xCoords, yCoords);
                            std::cout << listOfNames[i];
                            xCoords = 80;
                            setCursorPosition(xCoords, yCoords);
                            std::cout << playerLosses[i];
                            yCoords++;
                        }
                    }
//                    if(playerInput == 'r') // Sorts Leaderboard by Win/Loss Ratio // This doesn't work right now and I dont wanna work on it
//                    {
//                        system("cls");
//                        drawFrame(70, 20, 25, 3);
//                        setCursorPosition(55, 20);
//                        std::cout << "Try again?";
//                        setCursorPosition(44, 21);
//                        std::cout << "Press Y for 'yes' and N for 'no'";
//                        setCursorPosition(0, 28);
//                        yCoords = 9;
//                        vector<float> winLossRatio;
//                        winLossRatio.resize(length);
//                        for(int i = 0; i < length; i++)
//                        {
//                            float tempWin = playerWins[i];
//                            float tempLoss = playerLosses[i];
//                            if(tempLoss == 0.0) tempLoss = 1;
//                            winLossRatio[i] = (float)playerWins[i] / (float)playerLosses[i];
//                        }
//                        std::sort (winLossRatio.begin(), winLossRatio.end(), std::greater<float>());
//                        setCursorPosition(57, 5);
//                        std::cout << "by W/L";
//                        for(int i = 0; i < 10; ++i)
//                        {
//                            if(i >= length) break;
//                            xCoords = 37;
//                            setCursorPosition(xCoords, yCoords);
//                            std::cout << listOfNames[i];
//                            xCoords = 80;
//                            setCursorPosition(xCoords, yCoords);
//                            std::cout << winLossRatio[i];
//                            yCoords++;
//                        }
//                    }
                }
                if(playerInput == 'y')
                {
                    system("cls");
                    drawFrame(119, 29, 0, 0);
                    Player1.playerScore.setScore(0);
                    Player2.playerScore.setScore(0);
                    Ball.respawn();
                    playerInput = '0';
                }
                else if(playerInput == 'n')
                {
                    Sleep(10000);
                    exit(0);
                }
            }
        }
        else
        {
            AI();
            if(Player2.playerScore.getScore() == 10)
            {
                int Scores[10];
                ifstream ReadScore;
                ReadScore.open("Singleplayer/Highscores.txt");
                for(int i = 0; i < 10; i++)
                {
                    int tempInt;
                    ReadScore >> tempInt;
                    Scores[i] = tempInt;
                }
                ReadScore.close();
                std::string Names[10];
                ifstream ReadName;
                ReadName.open("Singleplayer/Names.txt");
                for(int i = 0; i < 10; i++)
                {
                    string tempString;
                    ReadName >> tempString;
                    Names[i] = tempString;
                }
                ReadName.close();
                bool addedScore{false};
                for(int j = 0; j < 10; j++)
                {
                    if(Player1.playerScore.getScore() > Scores[j] && !addedScore)
                    {
                        Scores[9] = Player1.playerScore.getScore();
                        Names[9] = Player1.getName();
                        for (int startIndex = 0; startIndex < 10 - 1; ++startIndex)
                        {
                            int biggestIndex = startIndex;
                            for (int currentIndex = startIndex + 1; currentIndex < 10; ++currentIndex)
                            {
                                if (Scores[currentIndex] > Scores[biggestIndex])
                                    biggestIndex = currentIndex;
                            }
                            std::swap(Scores[startIndex], Scores[biggestIndex]);
                            std::swap(Names[startIndex], Names[biggestIndex]);
                        }
                        addedScore = true;
                    }
                }
                ofstream SaveScore;
                SaveScore.open("Singleplayer/Highscores.txt");
                for(int i = 0; i < 10; i++)
                {
                    SaveScore << Scores[i];
                    SaveScore << " ";
                }
                SaveScore.close();
                ofstream SaveName;
                SaveName.open("Singleplayer/Names.txt");
                for(int i = 0; i < 10; i++)
                {
                    SaveName << Names[i];
                    SaveName << " ";
                }
                SaveName.close();
                drawFrame(70, 20, 25, 3);
                setCursorPosition(55, 5);
                std::cout << "Game  over";
                int xCoords{30}, yCoords{10};
                for(int k = 0; k < 10; k++)
                {
                    xCoords = 37;
                    setCursorPosition(xCoords, yCoords);
                    std::cout << Names[k];
                    xCoords = 80;
                    setCursorPosition(xCoords, yCoords);
                    std::cout << Scores[k];
                    yCoords++;
                }
                Sleep(5000);
                setCursorPosition(55, 20);
                std::cout << "Try again?";
                setCursorPosition(44, 21);
                std::cout << "Press Y for 'yes' and N for 'no'";
                setCursorPosition(0, 28);
                char input;
                while (input != 'Y' && input != 'y')
                {
                    if(_kbhit()) input = _getch();
                    if(input == 'N' || input == 'n') exit(0);
                }
                if(input == 'Y' || input == 'y')
                {
                    system("cls");
                    drawFrame(119, 29, 0, 0);
                    Player1.playerScore.setScore(0);
                    Player2.playerScore.setScore(0);
                    Ball.respawn();
                }
                else exit(0);
            }
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

