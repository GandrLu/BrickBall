#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

class Game;

class Paddle: public QGraphicsPixmapItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
public:
    void m_SetXPosition(int _XPos);
    void m_FireBall(Game * _Game);
private:
    int m_Speed;
    int m_XPos;
    int m_YPos;
};

#endif // PADDLE_H
