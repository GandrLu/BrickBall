#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>

class Paddle: public QGraphicsRectItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
public:
    void keyPressEvent(QKeyEvent * event);
    void m_SetXPosition(int _XPos);
private:
    int m_Speed;
    int m_XPos;
    int m_YPos;
};

#endif // PADDLE_H
