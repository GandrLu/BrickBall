#include "paddle.h"
#include "game.h"
//#include "ball.h"

Paddle::Paddle(QGraphicsScene * scene)
    : m_Width(180)
    , m_Height(20)
    , m_XPos((int)scene->width() * 0.5f - m_Width)
    , m_YPos((int)scene->height() - m_Height * 2)
    , m_PreparedBall(nullptr)
{
    // For interaction
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    // Set image
    setPixmap(QPixmap(":/images/resources/images/paddle.png").scaled(m_Width, m_Height));
    if (scene != nullptr)
    {
        // Add to scene
        setPos(m_XPos, m_YPos);
        scene->addItem(this);
    }
}

Paddle::~Paddle()
{
    if (this->m_PreparedBall != nullptr)
        delete this->m_PreparedBall;
}

int Paddle::m_GetWidth()
{
    return this->m_Width;
}

void Paddle::m_SetXPosition(int _XPos)
{
    // When it is still in the play area, set x position, including paddle width leftside
    // (right border = 0, left = scene width)
    if((qreal)(_XPos + m_Width) < scene()->width() && _XPos > 0) {
        setPos(_XPos, m_YPos);
    }
}

void Paddle::m_FireBall()
{
    if (m_PreparedBall != nullptr)
        this->m_PreparedBall->m_Fire();
}

void Paddle::m_PrepareBall(Game * _Game)
{
    this->m_PreparedBall = new Ball(_Game);
    // Set ball to the middle (horizontal) of the paddle and on top of it (vertical)
    this->m_PreparedBall->setPos(pos().x() + 0.5f * ((qreal)m_Width - (qreal)m_PreparedBall->m_GetSize()), pos().y() - m_PreparedBall->m_GetSize() - 1);
    scene()->addItem(m_PreparedBall);
    _Game->m_IncreaseBallsInGame(1);
}
