#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

class score{
private:
    int m_score{0};
    int m_scorePosX;  // scorePos is the Position at which the score is drawn
    int m_scorePosY;
    int singleDigits[4];

public:
    score(int, int);
    ~score();
    void add(int amount);
    int getScore();
    int length();
    void getDigits();
    void drawScore();
};

#endif // SCORE_H_INCLUDED
