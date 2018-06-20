#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include <random>

#include "Player.h"
#include "Ball.h"
#include "Intro.h"

void AI()
{
//    if(Ball.getBallVelY() > 0 && Ball.getBallVelX() > 0) Player2.Move(DOWN);    // Version 1
//    else if(Ball.getBallVelY() < 0 && Ball.getBallVelX() > 0) Player2.Move(UP);

    if((Ball.getBallVelY() >= -1 && Ball.getBallVelX() > 0) || ( Ball.getBallVelY() <= 1 && Ball.getBallVelX() > 0 ))  // Version 2
    {
        if(Ball.getBallPosY() > (Player2.getPosY() + 3 ) ) Player2.Move(DOWN);
        else if(Ball.getBallPosY() == (Player2.getPosY() + 3 )) {  }
        else if(Ball.getBallPosY() < (Player2.getPosY() + 6) ) Player2.Move(UP);

    }
    else if((Ball.getBallVelY() < -1 && Ball.getBallVelX() > 0) || (Ball.getBallVelY() > 1 && Ball.getBallVelX() > 0 ))
    {
        if(Ball.getBallVelY() > 0 && Ball.getBallVelX() > 0) Player2.Move(DOWN);
        else if(Ball.getBallVelY() < 0 && Ball.getBallVelX() > 0) Player2.Move(UP);
    }
    else
    {
        if(Player2.getPosY() < 9) { Player2.Move(DOWN); }
        else if(Player2.getPosY() == 9) {  }
        else{ Player2.Move(UP); }
    }


    Player2.playerScore.drawScore();
    Player2.draw();
    Player2.Erase();
}

#endif // AI_H_INCLUDED
