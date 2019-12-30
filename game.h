#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <paddle.h>
#include "brick.h"
#include "uipoints.h"
#include "uibar.h"
#include <qmediaplayer.h>

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
    void m_PlayBallLostSound();
private:
    int m_UiBarWidth;
    int m_UiBarHeight;
    int m_PlayAreaWidth;
    int m_PlayAreaHeight;
    //QGraphicsScene m_Scene;
    Brick * bricks[10];
    UiBar * m_UiBar;
    Paddle * paddle;
    // Sound of lost ball has to be played at the game instance because the 
    // ball itself gets deleted before it is able to play the sound
    QMediaPlayer* m_SoundLostBall;
};

#endif // GAME_H
