#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <paddle.h>
#include "brick.h"
#include "uipoints.h"

class Game : public QGraphicsScene
{
public:
    Game(int _Width = 800, int _Height = 600);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;
    UiPoints * m_GetScore();
    UiPoints * m_GetLifePoints();
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
    int m_AreaWidth;
    int m_AreaHeight;
    QGraphicsScene m_Scene;
    Brick * bricks[10];
    UiPoints * m_UiScore;
    UiPoints * m_UiLifePoints;
    Paddle * paddle;
};

#endif // GAME_H
