#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

void Player::setX(int x) {
    this->x = x;
}

void Player::setY(int y) {
    this->y = y;
}

void Player::changeX(int x) {
    this->x += x;
}

void Player::changeY(int y) {
    this->y += y;
}

int Player::getX() const {
    return this->x;
}

int Player::getY() const {
    return this->y;
}
