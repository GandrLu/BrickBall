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
    // 270° is straight upwards on the vertival axis in qt
    m_MovementRotation->setAngle(270);

    // set ball graphic
    setPixmap(QPixmap(":/images/resources/images/ball.png").scaled(m_Size,m_Size));

    // set sound files
    m_SoundDefault->setMedia(QUrl("qrc:/sounds/resources/sounds/hint.mp3"));
    m_SoundScore->setMedia(QUrl("qrc:/sounds/resources/sounds/score_powerOn.mp3"));

    // connect slot to timer
    m_Timer = new QTimer();
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(m_Move()));
    // start timer
    m_Timer->start(18);
}

Ball::~Ball()
{
    delete m_MovementRotation;
    delete m_SoundDefault;
    delete m_SoundScore;
    delete m_Timer;
}

int Ball::m_GetSize()
{
    return this->m_Size;
}

void Ball::m_Fire()
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

void Ball::m_Move()
{
    // If ball is not fired move it along with the paddle (update ball pos.
    // according to paddle pos.)
    ///// MOVE WITH PADDLE /////
    if (!this->m_Fired)
    {
        QPointF paddlePos = m_Game->m_GetPaddle()->pos();
        float paddleWidth = m_Game->m_GetPaddle()->boundingRect().width();
        float paddleHeight = m_Game->m_GetPaddle()->boundingRect().height();
        this->setPos(paddlePos.x() + 0.5f * ((qreal)paddleWidth - m_Size), paddlePos.y() - m_Size - 1);
        return;
    }
    // Check for collisions with paddle or bricks
    ///// BRICK AND PADDLE COLLIDING /////
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(size_t i = 0, n = colliding_items.size(); i < n; ++i)
    {
        // PADDLE collision
        if (typeid (*colliding_items[i]) == typeid (Paddle))
        {
            // Calculate exit angle of bouncing ball, depends on collision point
            // on the paddle
            Paddle* paddle = dynamic_cast<Paddle*>(colliding_items[i]);
            float halfPaddleWidth = 0.5 * paddle->m_GetWidth();
            float paddlePosX = colliding_items[i]->pos().x();
            // X position of ball measured from right end of paddle
            float relativePosX = pos().x() - paddlePosX;
            // Factor from -1 to +1
            float factor = (relativePosX - halfPaddleWidth) / halfPaddleWidth;
            // Calculate angle in range from -60 to +60
            float newAngle = factor * 60;
    
            // Add/Remove new angle to/from 270 what is the angle for straight upwards
            // result is in range from 210 to 330
            newAngle += 270;
            m_MovementRotation->setAngle(newAngle);
            
            m_PlaySound();
        }
        // BRICK collision
        if (typeid (*colliding_items[i]) == typeid (Brick))
        {
            // Calculate exit angle, is like incoming angle but in other direction
            // 270° is north, 90° south, 360° west and 180° east in qt
            if (360 > m_MovementRotation->angle() && m_MovementRotation->angle() > 270)
            {
                qreal value = m_MovementRotation->angle() - 270;
                m_MovementRotation->setAngle(90 - value);
            }
            else if (270 > m_MovementRotation->angle() && m_MovementRotation->angle() > 180)
            {
                qreal value = m_MovementRotation->angle() - 180;
                m_MovementRotation->setAngle(180 - value);
            }
            else if (m_MovementRotation->angle() == 270)
            {
                m_MovementRotation->setAngle(90);
            }
            else if (0 < m_MovementRotation->angle() && m_MovementRotation->angle() < 90)
            {
                m_MovementRotation->setAngle(360 - m_MovementRotation->angle());
            }
            else if (90 <= m_MovementRotation->angle() && m_MovementRotation->angle() < 180)
            {
                qreal value = m_MovementRotation->angle() - 90;
                m_MovementRotation->setAngle(270 - value);
            }

            Brick* brick = dynamic_cast<Brick*>(colliding_items[i]);
            brick->m_ReduceLifePoints();
            // If brick has no lifepoints left, destroy it and increase players score
            if (brick->m_GetLifePoints() <= 0)
            {
                m_PlaySound(1);
                m_Game->m_GetScore()->m_IncreasePoints(brick->m_GetScoreValue());
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                ///// GAME WON if all bricks are destroyed
                if (m_Game->m_DecreaseBricksInGame(1) <= 0)
                    m_Game->m_GetGameView()->m_LoadMainMenu();
            }
        }
    }

    // Bouncing from walls / play area borders
    ///// UPPER BORDER (y == 0) /////
    if (y() <= m_Game->m_GetUiBarHeight())
    {
        m_PlaySound();
        // Calculate exit angle
        if (360 > m_MovementRotation->angle() && m_MovementRotation->angle() > 270)
        {
            qreal value = m_MovementRotation->angle() - 270;
            m_MovementRotation->setAngle(90 - value);
        }
        else if (270 > m_MovementRotation->angle() && m_MovementRotation->angle() > 180)
        {
            qreal value = m_MovementRotation->angle() - 180;
            m_MovementRotation->setAngle(180 - value);
        }
        else if (m_MovementRotation->angle() == 270)
        {
            m_MovementRotation->setAngle(90);
        }
    }
    // If the ball reaches the bottom border it gets destroyed and a new ball 
    // is prepared if available
    ///// BOTTOM BORDER (y == height) /////
    else if (y() + m_Size >= scene()->height())
    {
        m_PlaySound(2);
        // Has player still balls (lifes) and no ball is in the game anymore, 
        // then make a new ball available
        if (m_Game->m_GetLifes()->m_GetPoints() > 0
            && m_Game->m_DecreaseBallsInGame(1) <= 0)
        {
            m_Game->m_GetLifes()->m_DecreasePoints();
            m_Game->m_IncreaseAvailableBalls(1);
        }
        ///// GAME OVER when the player has no balls left and no ball is in 
        // the game anymore
        else if (m_Game->m_GetLifes()->m_GetPoints() <= 0
                 && m_Game->m_DecreaseBallsInGame(1) <= 0)
        {
            m_Game->m_GetGameView()->m_LoadMainMenu();
        }
        // Destroy this ball
        scene()->removeItem(this);
        delete this;
        return;
    }
    // Bounce
    ///// LEFT BORDER (x == 0) /////
    else if (x() <= 0)
    {
        m_PlaySound();
        if (180 > m_MovementRotation->angle() && m_MovementRotation->angle() > 90)
        {
            qreal value = m_MovementRotation->angle() - 90;
            m_MovementRotation->setAngle(90 - value);
        }
        else if (270 > m_MovementRotation->angle() && m_MovementRotation->angle() > 180)
        {
            qreal value = m_MovementRotation->angle() - 180;
            m_MovementRotation->setAngle(360 - value);
        }
    }
    // Bounce
    ///// RIGHT BORDER (x == width) /////
    else if (x() + m_Size >= scene()->width())
    {
        m_PlaySound();
        if (90 > m_MovementRotation->angle() && m_MovementRotation->angle() > 0)
        {
            m_MovementRotation->setAngle(180 - m_MovementRotation->angle());
        }
        else if (360 > m_MovementRotation->angle() && m_MovementRotation->angle() > 270)
        {
            qreal value = 360 - m_MovementRotation->angle();
            m_MovementRotation->setAngle(180 + value);
        }
    }

    // When ball did not get destroyed, move it forward in its angle direction
    ///// Movement /////
    int STEP_SIZE = m_Speed;
    double theta = m_MovementRotation->angle();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    this->setPos(x() + dx, y() + dy);
}
