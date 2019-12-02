#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>

class Paddle: public QGraphicsRectItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
public:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PADDLE_H
