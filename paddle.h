#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "ball.h"

class Game;

class Paddle: public QGraphicsPixmapItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
    ~Paddle();
public:
    int m_GetWidth();
    void m_SetXPosition(int _XPos);
    void m_FireBall();
    void m_PrepareBall(Game * _Game);
private:
    int m_Speed;
    int m_Width;
    int m_Height;
    int m_XPos;
    int m_YPos;
    Ball * m_PreparedBall;
};

#endif // PADDLE_H
