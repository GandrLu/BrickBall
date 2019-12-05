#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "brick.h"
#include "uitext.h"

class Game : public QGraphicsScene
{
public:
    Game(int _Width = 800, int _Height = 600);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;
    UiText * m_GetScore();
private:
    int m_AreaWidth;
    int m_AreaHeight;
    QGraphicsScene m_Scene;
    Brick * bricks[10];
    UiText * m_UiText;
};

#endif // GAME_H
