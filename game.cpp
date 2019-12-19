#include "game.h"
#include <QGraphicsScene>

Game::Game(int _Width, int _Height)
    : m_UiBarWidth(_Width)
    , m_UiBarHeight(35)
    , m_PlayAreaWidth(_Width)
    , m_PlayAreaHeight(_Height - m_UiBarHeight)
    //, m_Scene(new QGraphicsScene)
{
    setSceneRect(0, 0, _Width, _Height);
    QPixmap* background = new QPixmap(":/images/resources/images/background.png");
    
    addPixmap(background->scaled(m_PlayAreaWidth, m_PlayAreaHeight))->setPos(0, m_UiBarHeight);

    for (int i = 0; i < 10; ++i) {
        Brick * brick = new Brick();
        brick->setPixmap(QPixmap(":/images/resources/images/brick_green.png").scaled(80, 30));
        brick->setPos(0 + i * 80, m_UiBarHeight);
        addItem(brick);
        bricks[i] = brick;
    }
    m_UiBar = new UiBar(this);
    addItem(m_UiBar);
    paddle = new Paddle(this);
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
    qDebug() << "Scene event";
    QGraphicsScene::mousePressEvent(event);
    paddle->m_FireBall();
}
