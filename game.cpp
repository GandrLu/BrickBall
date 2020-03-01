#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "brick.h"
#include "uibar.h"
#include "gameview.h"
#include "extraballpu.h"
#include "paddle.h"

Game::Game(int _Width, int _Height, GameView* _ParentView)
    : m_UiBarWidth(_Width)
    , m_UiBarHeight(35)
    , m_PlayAreaWidth(_Width)
    , m_PlayAreaHeight(_Height - m_UiBarHeight)
    , m_MaxHorizontalBricks(16)
    , m_MaxVerticalBricks(4)
    , m_AvailableBalls(1)
    , m_BallsInGame(0)
    , m_BricksInGame(0)
    , m_GameView(_ParentView)
    //, m_Scene(new QGraphicsScene)
{
    setSceneRect(0, 0, _Width, _Height);
    QPixmap* background = new QPixmap(":/images/resources/images/background_simple.png");
    addPixmap(background->scaled(m_PlayAreaWidth, m_PlayAreaHeight))->setPos(0, m_UiBarHeight);

    // Calculate brick size
    int brickWidth = (int)roundf(m_PlayAreaWidth / m_MaxHorizontalBricks);
    int brickHeight = (int)roundf(brickWidth / 3);

    short fillArray[][16] =
    {
        {9, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 9,},
        {9, 2, 1, 1, 1, 1, 2, 0, 0, 2, 1, 1, 1, 1, 2, 9,},
        {9, 3, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 3, 9,},
        {9, 1, 1, 9, 9, 9, 9, 1, 1, 9, 9, 9, 9, 1, 1, 9,},
    };

    // Random seed
    srand(time(NULL));

    int distanceFromUpperBorder = (int)(0.1 * m_PlayAreaHeight);
    for (size_t v = 0; v < m_MaxVerticalBricks; v++)
    {
        for (size_t h = 0; h < m_MaxHorizontalBricks; h++)
        {
            if (fillArray[v][h] == 9)
                continue;
            Brick * brick = new Brick((BrickType)fillArray[v][h], brickWidth, brickHeight);
            brick->setPos(0 + h * brickWidth, (qreal)(m_UiBarHeight + distanceFromUpperBorder + brickHeight * v));
            addItem(brick);
            m_Bricks[v][h] = brick;
            ++m_BricksInGame;

            // 20 percent chance for a powerup/down
            int nb = rand() % 5 + 1;
            if (nb == 1)
            {
                // Add powerup
                brick->m_AddPowerUp(this);
                qDebug() << "Added pu";
            }
        }
    }

    m_UiBar = new UiBar(this);
    addItem(m_UiBar);
    m_Paddle = new Paddle(this);
    m_Paddle->m_PrepareBall(this);
    m_SoundLostBall = new QMediaPlayer();
    m_SoundLostBall->setMedia(QUrl("qrc:/sounds/resources/sounds/wrongAnswer.mp3"));

}

int Game::m_GetAreaWidth() const
{
    return m_PlayAreaWidth;
}

int Game::m_GetAreaHeight() const
{
    return m_PlayAreaHeight;
}

int Game::m_GetUiBarHeight()
{
    return m_UiBarHeight;
}

int Game::m_IncreaseAvailableBalls(int _Amount)
{
    if (m_AvailableBalls >= 1)
        return this->m_AvailableBalls;
    m_Paddle->m_PrepareBall(this);
    this->m_AvailableBalls += _Amount;
    return this->m_AvailableBalls;
}

int Game::m_IncreaseBallsInGame(int _Amount)
{
    this->m_BallsInGame += _Amount;
    return this->m_BallsInGame;
}

int Game::m_DecreaseBallsInGame(int _Amount)
{
    this->m_BallsInGame -= _Amount;
    return this->m_BallsInGame;
}

int Game::m_DecreaseBricksInGame(int _Amount)
{
    this->m_BricksInGame -= _Amount;
    return this->m_BricksInGame;
}

UiPoints * Game::m_GetScore()
{
    return m_UiBar->m_GetScore();
}

UiPoints * Game::m_GetLifes()
{
    return m_UiBar->m_GetLifes();
}

Paddle * Game::m_GetPaddle()
{
    return m_Paddle;
}

GameView* Game::m_GetGameView()
{
    return this->m_GameView;
}

void Game::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
    m_Paddle->m_SetXPosition(event->scenePos().x());
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mousePressEvent(event);
    if (this->m_AvailableBalls > 0)
    {
        m_Paddle->m_FireBall();
        --this->m_AvailableBalls;
    }
}

void Game::m_PlayBallLostSound()
{
    m_SoundLostBall->setPosition(0);
    m_SoundLostBall->play();
}
