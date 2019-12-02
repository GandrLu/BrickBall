#include "paddle.h"
#include "ball.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Paddle::Paddle(QGraphicsScene * scene)
{
    setRect(0, 0, 100, 20);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    if (scene != nullptr)
    {
        setPos(scene->width() * 0.5 - 50, scene->height() - 20);
        scene->addItem(this);
    }
}

void Paddle::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "X position: " << x();
    switch (event->key()) {
    case Qt::Key_Left:
        qDebug() << "Key left";
        if(pos().x() > 0) {
            setPos(x() - 5, y());
        }
    break;
    case Qt::Key_Right:
        qDebug() << "Key right";
        if(pos().x() + 100 < 800) {
            setPos(x() + 5, y());
        }
    break;
    case Qt::Key_Space:
        qDebug() << "Space bar";
        Ball * ball = new Ball();
        ball->setPos(pos().x() + 45, pos().y() - ball->GetSize() - 1);
        //ball->setRotation(-57);
        scene()->addItem(ball);
        break;
    }
}
