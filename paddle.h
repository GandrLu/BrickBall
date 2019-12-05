#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>

class Paddle: public QGraphicsRectItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
public:
    void keyPressEvent(QKeyEvent * event);
private:
    int m_Speed;
};

#endif // PADDLE_H
