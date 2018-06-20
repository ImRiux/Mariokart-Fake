#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

class ball{
private:
    float m_yVel;  // Velocity in the Y direction
    float m_xVel;  // Velocity in the X direction
    float m_yPos;  // Y position of the ball
    float m_xPos;  // X position of the ball

public:
    ball();
    ~ball();
    void clearBehind();
    void respawn();
    void ballSetPos(int x, int y) { clearBehind(); m_xPos = x; m_yPos = y;  };
    void update(int Player1PosX, int Player1PosY, int Player2PosX, int Player2PosY);  // executes draw() and collDet()
    void draw();  // draws the ball to the screen
    void eraseBall();  // removes the ball from the screen
    bool collDet(int Player1PosX, int Player1PosY, int Player2PosX, int Player2PosY); // detects any collisions with the walls or the players
    float getBallPosX() {return m_xPos; };
    float getBallPosY() {return m_yPos; };
    float getBallVelX() {return m_xVel; };
    float getBallVelY() {return m_yVel; };
};

#endif // BALL_H_INCLUDED
