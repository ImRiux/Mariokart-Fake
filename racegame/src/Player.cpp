#include <iostream>
#include <string>
#include "Player.h"

Player::Player():name("null") {
    //ctor
}

Player::~Player() {
    //dtor
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setCar(unsigned char car) {
    this->car = car;
}

void Player::setXPosition(int x) {
    this->xPosition = x;
}

void Player::setLastXPostion(int x) {
    this->lastXPosition = x;
}

void Player::setYPosition(int y) {
    this->yPosition = y;
}

void Player::setLastYPosition(int y) {
    this->lastYPosition = y;
}

void Player::setDirection(Direction dir) {
    this->dir = dir;
}

void Player::changeXPosition(int x) {
    this->xPosition += x;
}

void Player::changeYPosition(int y) {
    this->yPosition += y;
}

std::string Player::getName() const {
    return this->name;
}

unsigned char Player::getCar() const {
    return this->car;
}

int Player::getXPosition() const {
    return this->xPosition;
}

int Player::getLastXPosition() const {
    return this->lastXPosition;
}

int Player::getYPosition() const {
    return this->yPosition;
}

int Player::getLastYPosition() const {
    return this->lastYPosition;
}

Direction Player::getDirection() const {
    return this->dir;
}
