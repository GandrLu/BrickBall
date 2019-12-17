#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <paddle.h>
#include "brick.h"
#include "uipoints.h"
#include "uibar.h"

class Game : public QGraphicsScene
{
public:
    Game(int _Width = 800, int _Height = 600);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;
    int m_GetUiBarHeight();
    UiPoints * m_GetScore();
    UiPoints * m_GetLifes();
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
    int m_PlayAreaWidth;
    int m_PlayAreaHeight;
    int m_UiBarWidth;
    int m_UiBarHeight;
    //QGraphicsScene m_Scene;
    Brick * bricks[10];
    UiBar * m_UiBar;
    Paddle * paddle;
};

#endif // GAME_H
