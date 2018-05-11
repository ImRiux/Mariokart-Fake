#include <iostream>
#include "Snake.h"
#include "Game.h"
#include "conio.h"
#include <algorithm>

Snake::Snake(): m_dir(DIRECTION_STOP) {
	m_tailLength = 0;
	m_hitWall = false;
	m_hitTail = false;
	for(int i = 0; i < 10; i++) {
		m_tailX[i] = mapWidth;
		m_tailY[i] = 0;
	}
}

Snake::~Snake() {
}

void Snake::movement() {
	//changes the direction of the snake
	if(_kbhit()) {
		switch(_getch()) {
			case 'w':
				m_dir = DIRECTION_UP;
				break;
			case 's':
				m_dir = DIRECTION_DOWN;
				break;
			case 'a':
				m_dir = DIRECTION_LEFT;
				break;
			case 'd':
				m_dir = DIRECTION_RIGHT;
				break;
			default: break;
		}
	}

	//saving the last x and y position
	m_lastCoordX = m_snakeX;
	m_lastCoordY = m_snakeY;

	//changes the position of the snake
	switch(m_dir) {
		case DIRECTION_UP:
			m_snakeY -= 1;
			break;
		case DIRECTION_DOWN:
			m_snakeY += 1;
			break;
		case DIRECTION_LEFT:
			m_snakeX -= 1;
			break;
		case DIRECTION_RIGHT:
			m_snakeX += 1;
			break;
		default: break;
	}

    /*if snake hits a wall
     *  snake gets his old coordinates
     *  hit wall is true (game over)
     */
	if(Map[m_snakeY][m_snakeX] == 'b') {
		m_snakeX = m_lastCoordX;
		m_snakeY = m_lastCoordY;
		m_hitWall = true;
		return;
	}

    /*for all tail coordinates
     *  if snake hits his tail
     *      snake gets his old coordinates
     *      hit tail is true (game over)
     */
	for(int i = 0; i < m_tailLength; i++) {
		if(m_snakeX == m_tailX[i] && m_snakeY == m_tailY[i]) {
			m_snakeX = m_lastCoordX;
			m_snakeY = m_lastCoordY;
			m_hitTail = true;
			return;
		}
	}

	//sets the coordinates for the tail
	for(int i = 0; i < m_tailLength; i++) {
		std::swap(m_tailX[i], m_lastCoordX);
		std::swap(m_tailY[i], m_lastCoordY);
	}
}

void Snake::drawSnake() const{
    /*sets the cursor to snakes/tails last position
      and prints a space*/
	setCursor(m_lastCoordX, m_lastCoordY);
	std::cout << SPACE;

    /*sets the cursor to snakes position
      and prints the snake-symbol*/
	setCursor(m_snakeX, m_snakeY);
	std::cout << SNAKE;

	//prints the tail
	for(int i = 0; i < m_tailLength; i++) {
        /*sets the cursor to the tails position
          and prints the tail-symbol*/
		setCursor(m_tailX[i], m_tailY[i]);
		std::cout << TAIL;
	}
}
