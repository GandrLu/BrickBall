#include <QTimer>
#include "ball.h"
#include "game.h"
#include "gameview.h"
#include "brick.h"
#include "uipoints.h"
#include "paddle.h"

Ball::Ball(Game* _Game, QObject* _Parent)
    : m_Size(15)
    , m_Speed(10)
    , m_MovementRotation(new QGraphicsRotation(this))
    , m_SoundDefault(new QMediaPlayer(this))
    , m_SoundScore(new QMediaPlayer(this))
    , m_Game(_Game)
    , m_Fired(false)
{
    setParent(_Parent);
    m_MovementRotation.setAngle(270);

    // set graphics
    setPixmap(QPixmap(":/images/resources/images/ball.png").scaled(m_Size,m_Size));

    // set sound
    m_SoundDefault->setMedia(QUrl("qrc:/sounds/resources/sounds/hint.mp3"));
    m_SoundScore->setMedia(QUrl("qrc:/sounds/resources/sounds/score_powerOn.mp3"));

    // connect slot
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(18);
}

int Ball::GetSize()
{
    return this->m_Size;
}

void Ball::Fire()
{
    this->m_Fired = true;
}

void Ball::m_PlaySound(int _Type)
{
    switch (_Type)
    {
    case 1:
        m_SoundScore->setPosition(0);
        m_SoundScore->play();
        break;
    case 2:
        m_Game->m_PlayBallLostSound();
        break;
    default:
        m_SoundDefault->setPosition(0);
        m_SoundDefault->play();
        break;
    }
}

void Ball::move()
{
    if (!this->m_Fired)
    {
        QPointF paddlePos = m_Game->m_GetPaddle()->pos();
        float paddleWidth = m_Game->m_GetPaddle()->boundingRect().width();
        float paddleHeight = m_Game->m_GetPaddle()->boundingRect().height();
        this->setPos(paddlePos.x() + 0.5f * ((qreal)paddleWidth - m_Size), paddlePos.y() - m_Size - 1);
        return;
    }
    // Colliding with bricks
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug() << "Initial angle " << m_MovementRotation.angle();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        qDebug() << typeid(*colliding_items[i]).name();
        if (typeid (*colliding_items[i]) == typeid (Paddle))
        {
            //qDebug() << colliding_items[i]->boundingRect().width();
            float paddlePosX = colliding_items[i]->pos().x();
            float relativePosX = pos().x() - paddlePosX;
            float factor = (relativePosX - 50) / 50;
            float newAngle = factor * 60;
    
            newAngle += 270;
            m_MovementRotation.setAngle(newAngle);
            qDebug() << "newangle " << m_MovementRotation.angle();
            
            //qDebug() << "PADDLE " << m_MovementRotation.angle();
            m_PlaySound();
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
            else if (m_MovementRotation.angle() == 270)
            {
                m_MovementRotation.setAngle(90);
            }
            m_PlaySound(1);

            //m_MovementRotation.setAngle(-m_MovementRotation.angle());
            Brick* brick = dynamic_cast<Brick*>(colliding_items[i]);
            brick->m_ReduceLifePoints();
            if (brick->m_GetLifePoints() <= 0)
            {
                m_Game->m_GetScore()->m_IncreasePoints(brick->m_GetPointValue());
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
        }
    }

    // Bouncing from walls
    // Ball is at upper border y == 0
    if (y() <= m_Game->m_GetUiBarHeight())
    {
        //qDebug() << "Top " << y();
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
        else if (m_MovementRotation.angle() == 270)
        {
            m_MovementRotation.setAngle(90);
        }
        m_PlaySound();
    }
    // Ball is at bottom border y == height
    else if (y() + m_Size >= scene()->height())
    {
        m_PlaySound(2);
        qDebug() << "Bottom: Remove ball";
        m_Game->m_GetLifes()->m_DecreasePoints();
        if (m_Game->m_GetLifes()->m_GetPoints() > 0)
        {
            m_Game->increaseAvailableBalls(1);
        }
        else
            m_Game->m_GetGameView()->m_LoadMainMenu();
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
        m_PlaySound();
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
        m_PlaySound();
    }

    // Move on
    int STEP_SIZE = m_Speed;
    double theta = m_MovementRotation.angle();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    this->setPos(x() + dx, y() + dy);
    //qDebug() << m_MovementRotation.angle();
}
