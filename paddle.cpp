#include "paddle.h"
#include "ball.h"

Paddle::Paddle(QGraphicsScene * scene)
    : m_Speed(15)
    , m_XPos(scene->width() * 0.5 - 50)
    , m_YPos(scene->height() - 20)
{
    //setRect(0, 0, 100, 20);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/resources/images/paddle.png").scaled(100,20));
    if (scene != nullptr)
    {
        setPos(m_XPos, m_YPos);
        scene->addItem(this);
    }
}

void Paddle::m_SetXPosition(int _XPos)
{
    if(_XPos + 100 < scene()->width() && _XPos > 0) {
        setPos(_XPos, m_YPos);
    }
}

void Paddle::m_FireBall(Game * _Game)
{
    Ball* ball = new Ball(_Game);
    ball->setPos(pos().x() + 45, pos().y() - ball->GetSize() - 1);
    scene()->addItem(ball);
}
