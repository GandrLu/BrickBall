#include "game.h"
#include <QGraphicsScene>

Game::Game(int _Width, int _Height)
    : m_AreaWidth(_Width)
    , m_AreaHeight(_Height)
    , m_Scene(new QGraphicsScene)
{
    setSceneRect(0, 0, _Width, _Height);
}

int Game::m_GetAreaWidth() const
{
    return m_AreaWidth;
}

int Game::m_GetAreaHeight() const
{
    return m_AreaHeight;
}
