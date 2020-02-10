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
    
    for (int i = 0; i < m_MaxHorizontalBricks; ++i) {
        Brick * brick = new Brick();
        brick->setPixmap(QPixmap(":/images/resources/images/brick_red.png").scaled(brickWidth, brickHeight));
        brick->setPos(0 + i * brickWidth, m_UiBarHeight);
        addItem(brick);
        bricks[0][i] = brick;
    }
    for (int i = 0; i < m_MaxHorizontalBricks; ++i) {
        Brick* brick = new Brick();
        brick->setPixmap(QPixmap(":/images/resources/images/brick_blue.png").scaled(brickWidth, brickHeight));
        brick->setPos(0 + i * brickWidth, m_UiBarHeight + brickHeight);
        addItem(brick);
        bricks[1][i] = brick;
    }

    m_UiBar = new UiBar(this);
    addItem(m_UiBar);
    paddle = new Paddle(this);
    paddle->m_PrepareBall(this);
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
    paddle->m_PrepareBall(this);
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

void Game::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
    paddle->m_SetXPosition(event->scenePos().x());
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsScene::mousePressEvent(event);
    if (this->m_AvailableBalls > 0)
    {
        paddle->m_FireBall();
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
