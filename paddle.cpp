#include "paddle.h"
//#include "ball.h"

Paddle::Paddle(QGraphicsScene * scene)
    : m_Speed(15)
    , m_Width(100)
    , m_Height(20)
    , m_XPos(scene->width() * 0.5f - m_Width)
    , m_YPos(scene->height() - (int)m_Height * 2)
    , m_PreparedBall(nullptr)
{
    //setRect(0, 0, 100, 20);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPixmap(QPixmap(":/images/resources/images/paddle.png").scaled(m_Width, m_Height));
    if (scene != nullptr)
    {
        setPos(m_XPos, m_YPos);
        scene->addItem(this);
    }
}

Paddle::~Paddle()
{
}

void Paddle::m_SetXPosition(int _XPos)
{
    if(_XPos + m_Width < scene()->width() && _XPos > 0) {
        setPos(_XPos, m_YPos);
    }
}

void Paddle::m_FireBall()
{
    this->m_PreparedBall->Fire();
}

void Paddle::m_PrepareBall(Game * _Game)
{
    this->m_PreparedBall = new Ball(_Game);
    this->m_PreparedBall->setPos(pos().x() + 0.5f * ((qreal)m_Width - (qreal)m_PreparedBall->GetSize()), pos().y() - m_PreparedBall->GetSize() - 1);
    //qDebug() << "pos y: " << m_PreparedBall->pos().y();
    //this->m_PreparedBall->setParentItem(this);
    
    scene()->addItem(m_PreparedBall);
}
