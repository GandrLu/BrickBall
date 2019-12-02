#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

class Game : public QGraphicsScene
{
public:
    Game(int _Width = 800, int _Height = 600);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;

private:
    int m_AreaWidth;
    int m_AreaHeight;
    QGraphicsScene m_Scene;
};

#endif // GAME_H
