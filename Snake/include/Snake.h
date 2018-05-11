#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

enum Direction{DIRECTION_STOP, DIRECTION_UP, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT};

class Snake {
private:
	int m_snakeX;
	int m_snakeY;
	int m_lastCoordX;
	int m_lastCoordY;
	int m_tailX[9];
	int m_tailY[9];
	int m_tailLength;
	Direction m_dir;
	bool m_hitWall;
	bool m_hitTail;
public:
	Snake();
	~Snake();
	void setCoordX(int x){m_snakeX = x;}
	void setCoordY(int y){m_snakeY = y;}
	void changeCoordX(int x){m_snakeX += x;}
	void changeCoordY(int y){m_snakeY += y;}
	void changeTailLength(int l){m_tailLength += l;}

	void movement();
	void drawSnake() const;

	int getCoordX() const{return m_snakeX;}
	int getCoordY() const {return m_snakeY;}
	int getLastCoordX() const {return m_lastCoordX;}
	int getLastCoordY() const {return m_lastCoordY;}
	int getTailLength() const {return m_tailLength;}
	bool hitWall() const{return m_hitWall;}
	bool hitTail() const{return m_hitTail;}
};

#endif // REFERENCES_H_INCLUDED
