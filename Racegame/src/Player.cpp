#include <iostream>
#include "Player.h"
#include "Game.h"

Player::Player() {

}

Player::~Player() {

}

void Player::drawPlayer(Player &player) {
    /*jumps to players last position
     *and draws a space
     */
    setCursor(m_lastXPosition, m_lastYPosition);
    std::cout << P_SPACE;

    /*jumps to players position
     *and draws his character
     */
    setCursor(m_xPosition, m_yPosition);
    std::cout << player.getCar();
}

