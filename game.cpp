#include "game.h"
#include <QGraphicsScene>

Game::Game(int _Width, int _Height)
    : m_AreaWidth(_Width)
    , m_AreaHeight(_Height)
    , m_Scene(new QGraphicsScene)
{
    setSceneRect(0, 0, _Width, _Height);

    for (int i = 0; i < 10; ++i) {
        Brick * brick = new Brick();
        brick->setRect(0, 0, 80, 30);
        brick->setPos(0 + i * 80, 0);
        addItem(brick);
        bricks[i] = brick;
    }

    m_UiScore = new UiPoints("SCORE ", 0);
    addItem(m_UiScore);
    m_UiLifePoints = new UiPoints("LIFES   ", 3);
    m_UiLifePoints->setPos(0, m_UiScore->boundingRect().height());
    addItem(m_UiLifePoints);
    paddle = new Paddle(this);
}

int Game::m_GetAreaWidth() const
{
    return m_AreaWidth;
}

int Game::m_GetAreaHeight() const
{
    return m_AreaHeight;
}

UiPoints * Game::m_GetScore()
{
    return m_UiScore;
}

UiPoints * Game::m_GetLifePoints()
{
    return m_UiLifePoints;
}

void Game::mouseMoveEvent(QGraphicsSceneMouseEvent * event) {
    paddle->m_SetXPosition(event->scenePos().x());
}
