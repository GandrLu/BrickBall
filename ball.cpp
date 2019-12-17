#include "ball.h"
#include "game.h"
#include "paddle.h"
#include "brick.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <qmath.h>

extern Game * game;

Ball::Ball(QGraphicsItem * parent)
    : m_Size(15)
    , m_Speed(10)
    , m_MovementRotation(new QGraphicsRotation())
{
    // set graphics
    setPixmap(QPixmap(":/images/ball.png").scaled(m_Size,m_Size));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    m_MovementRotation.setAngle(225);
    timer->start(25);
}

int Ball::GetSize()
{
    return this->m_Size;
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
            qDebug() << "PADDLE " << m_MovementRotation.angle();
            if (90 > m_MovementRotation.angle() && m_MovementRotation.angle() > 0)
            {
                m_MovementRotation.setAngle(360 - m_MovementRotation.angle());
            }
            else if (180 > m_MovementRotation.angle() && m_MovementRotation.angle() > 90)
            {
                qreal value = m_MovementRotation.angle() - 90;
                m_MovementRotation.setAngle(270 - value);
            }

            //m_MovementRotation.setAngle(-m_MovementRotation.angle());
        }
        if (typeid (*colliding_items[i]) == typeid (Brick))
        {
            qDebug() << "BRICK " << m_MovementRotation.angle();
            if (360 > m_MovementRotation.angle() && m_MovementRotation.angle() > 270)
            {
                qreal value = m_MovementRotation.angle() - 270;
                m_MovementRotation.setAngle(90 - value);
            }
            else if (270 > m_MovementRotation.angle() && m_MovementRotation.angle() > 180)
            {
                qreal value = m_MovementRotation.angle() - 180;
                m_MovementRotation.setAngle(180 - value);
            }

            //m_MovementRotation.setAngle(-m_MovementRotation.angle());
            game->m_GetScore()->m_IncreasePoints();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }

    // Bouncing from walls
    // Ball is at upper border y == 0
    if (y() <= game->m_GetUiBarHeight())
    {
        qDebug() << "Top " << y();
        if (360 > m_MovementRotation.angle() && m_MovementRotation.angle() > 270)
        {
            qreal value = m_MovementRotation.angle() - 270;
            m_MovementRotation.setAngle(90 - value);
        }
        else if (270 > m_MovementRotation.angle() && m_MovementRotation.angle() > 180)
        {
            qreal value = m_MovementRotation.angle() - 180;
            m_MovementRotation.setAngle(180 - value);
        }
    }
    // Ball is at bottom border y == height
    else if (y() + m_Size >= scene()->height())
    {
        qDebug() << "Bottom: Remove ball";
        game->m_GetLifes()->m_DecreasePoints();
        scene()->removeItem(this);
        delete this;
        return;
    }
    // Ball is at left border x == 0
    else if (x() <= 0)
    {
        qDebug() << "Left " << m_MovementRotation.angle();
        if (180 > m_MovementRotation.angle() && m_MovementRotation.angle() > 90)
        {
            qreal value = m_MovementRotation.angle() - 90;
            m_MovementRotation.setAngle(90 - value);
        }
        else if (270 > m_MovementRotation.angle() && m_MovementRotation.angle() > 180)
        {
            qreal value = m_MovementRotation.angle() - 180;
            m_MovementRotation.setAngle(360 - value);
        }
    }
    // Ball is at right border x == width
    else if (x() + m_Size >= scene()->width())
    {
        qDebug() << "Right " << m_MovementRotation.angle();
        if (90 > m_MovementRotation.angle() && m_MovementRotation.angle() > 0)
        {
            m_MovementRotation.setAngle(180 - m_MovementRotation.angle());
        }
        else if (360 > m_MovementRotation.angle() && m_MovementRotation.angle() > 270)
        {
            qreal value = 360 - m_MovementRotation.angle();
            m_MovementRotation.setAngle(180 + value);
        }
    }

    // Move on
    int STEP_SIZE = m_Speed;
    double theta = m_MovementRotation.angle();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    this->setPos(x() + dx, y() + dy);
    //qDebug() << m_MovementRotation.angle();
}
