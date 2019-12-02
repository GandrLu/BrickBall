#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRotation>
#include <QObject>

class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(QGraphicsItem * parent = 0);
public:
    int GetSize();
public slots:
    void move();
private:
    int size;
    QGraphicsRotation movementRotation;
};


#endif // BALL_H
