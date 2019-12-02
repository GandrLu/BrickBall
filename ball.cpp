#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <qmath.h>

Ball::Ball(QGraphicsItem * parent)
    : size(15)
    , movementRotation(new QGraphicsRotation())
{
//    this->setRect(0, 0, 10, 10);
    // set graphics
    setPixmap(QPixmap(":/images/ball.png").scaled(size,size));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    movementRotation.setAngle(-120);
    /*movementRotation.setAngle(movementRotation.angle() -100);
    qDebug() << "angle -100: " << movementRotation.angle();
    movementRotation.setAngle(movementRotation.angle() -150);
    qDebug() << "angle -250: " << movementRotation.angle();
    movementRotation.setAngle(-120);
    movementRotation.setAngle(movementRotation.angle() +150);
    qDebug() << "angle +150: " << movementRotation.angle();*/
    timer->start(50);
}

int Ball::GetSize()
{
    return this->size;
}

void Ball::move()
{
    // Colliding with bricks
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        qDebug() << typeid(*colliding_items[i]).name();
        if (typeid (*colliding_items[i]) == typeid (Paddle))
        {
            movementRotation.setAngle(-movementRotation.angle());
        }
        if (typeid (*colliding_items[i]) == typeid (Brick))
        {
            movementRotation.setAngle(-movementRotation.angle());
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }



    // Bouncing from walls
    // Ball is at upper border y == 0
    if (y() <= 0)
    {
        qDebug() << "Top";
        movementRotation.setAngle(-movementRotation.angle());
    }
    // Ball is at bottom border y == height
    else if (y() + size >= scene()->height())
    {
        qDebug() << "Bottom";
        scene()->removeItem(this);
        delete this;
        return;
    }
    // Ball is at left border x == 0
    else if (x() <= 0)
    {
        qDebug() << "Left";
        if (movementRotation.angle() > -180)
        {
            movementRotation.setAngle(movementRotation.angle() - 90);
        }
        else if (movementRotation.angle() < -180)
        {
            movementRotation.setAngle(movementRotation.angle() + 90);
        }
    }
    // Ball is at right border x == width
    else if (x() + size >= scene()->width())
    {
        qDebug() << "Right";
        if (movementRotation.angle() < 0)
        {
            movementRotation.setAngle(movementRotation.angle() - 90);
        }
        else
        {
            movementRotation.setAngle(movementRotation.angle() + 90);
        }
    }

    // Move on
    int STEP_SIZE = 10;
    double theta = movementRotation.angle();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    this->setPos(x() + dx, y() + dy);
    qDebug() << movementRotation.angle();
}
