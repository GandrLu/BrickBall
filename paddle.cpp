#include "paddle.h"
#include "ball.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Paddle::Paddle(QGraphicsScene * scene)
    : m_Speed(15)
    , m_XPos(scene->width() * 0.5 - 50)
    , m_YPos(scene->height() - 20)
{
    //setRect(0, 0, 100, 20);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/resources/images/paddleboat.png").scaled(100,20));
    if (scene != nullptr)
    {
        setPos(m_XPos, m_YPos);
        scene->addItem(this);
    }
}

void Paddle::keyPressEvent(QKeyEvent * event)
{
    /*switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        //qDebug() << "Key left";
        if(pos().x() > 0) {
            setPos(x() - m_Speed, y());
        }
    break;
    case Qt::Key_D:
    case Qt::Key_Right:
        //qDebug() << "Key right";
        if(pos().x() + 100 < scene()->width()) {
            setPos(x() + m_Speed, y());
        }
    break;
    }
    */
    qDebug() << "key event";

    if (event->key() == Qt::Key_Space)
    {
        qDebug() << "Space bar";
        Ball * ball = new Ball();
        ball->setPos(pos().x() + 45, pos().y() - ball->GetSize() - 1);
        //ball->setRotation(-57);
        scene()->addItem(ball);
    }
}

void Paddle::m_SetXPosition(int _XPos)
{
    if(_XPos + 100 < scene()->width() && _XPos > 0) {
        setPos(_XPos, m_YPos);
    }
}

void Paddle::m_FireBall()
{
    Ball* ball = new Ball();
    ball->setPos(pos().x() + 45, pos().y() - ball->GetSize() - 1);
    scene()->addItem(ball);
}
