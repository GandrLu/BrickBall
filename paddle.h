#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class Paddle: public QGraphicsPixmapItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
public:
    void keyPressEvent(QKeyEvent * event);
    void m_SetXPosition(int _XPos);
    void m_FireBall();
private:
    int m_Speed;
    int m_XPos;
    int m_YPos;
};

#endif // PADDLE_H
