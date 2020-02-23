#include <math.h>
#include "game.h"
#include "brick.h"
#include "uibar.h"
#include "gameview.h"

Game::Game(int _Width, int _Height, GameView* _ParentView)
    : m_UiBarWidth(_Width)
    , m_UiBarHeight(35)
    , m_PlayAreaWidth(_Width)
    , m_PlayAreaHeight(_Height - m_UiBarHeight)
    , m_MaxHorizontalBricks(16)
    , m_MaxVerticalBricks(4)
    , m_AvailableBalls(1)
    , m_BallsInGame(0)
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
        {2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,},
        {1, 1, 1, 1, 1, 1, 2, 0, 0, 2, 1, 1, 1, 1, 2, 2,},
        {3, 3, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 3, 3,},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,},
    };

    for (size_t v = 0; v < m_MaxVerticalBricks; v++)
    {
        for (size_t h = 0; h < m_MaxHorizontalBricks; h++)
        {
            if (fillArray[v][h] == 9)
                continue;
            Brick * brick = new Brick((BrickType)fillArray[v][h], brickWidth, brickHeight);
            brick->setPos(0 + h * brickWidth, m_UiBarHeight + brickHeight * v);
            addItem(brick);
            m_Bricks[v][h] = brick;
        }
    }
    //for (int i = 0; i < m_MaxHorizontalBricks; ++i) {
    //    Brick * brick = new Brick(BrickType::brown, brickWidth, brickHeight);
    //    brick->setPos(0 + i * brickWidth, m_UiBarHeight);
    //    addItem(brick);
    //    m_Bricks[0][i] = brick;
    //}
    //for (int i = 0; i < m_MaxHorizontalBricks; ++i) {
    //    Brick* brick = new Brick(BrickType::blue, brickWidth, brickHeight);
    //    brick->setPos(0 + i * brickWidth, (qreal)(m_UiBarHeight + brickHeight));
    //    addItem(brick);
    //    m_Bricks[1][i] = brick;
    //}
    
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

int Game::increaseAvailableBalls(int _Amount)
{
    m_Paddle->m_PrepareBall(this);
    this->m_AvailableBalls += _Amount;
    return this->m_AvailableBalls;
}

int Game::decreaseBallsInGame(int _Amount)
{
    this->m_BallsInGame -= _Amount;
    return this->m_BallsInGame;
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
        ++this->m_BallsInGame;
        --this->m_AvailableBalls;
    }
}

void Game::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        m_GameView->m_LoadMainMenu();
    }
}

void Game::m_PlayBallLostSound()
{
    m_SoundLostBall->setPosition(0);
    m_SoundLostBall->play();
}
