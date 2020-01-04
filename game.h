#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <paddle.h>
#include <qmediaplayer.h>

class Brick;
class GameView;
class UiBar;
class UiPoints;

class Game : public QGraphicsScene
{
public:
    Game(int _Width, int _Height, GameView* _ParentView);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;
    int m_GetUiBarHeight();
    UiPoints * m_GetScore();
    UiPoints * m_GetLifes();
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);
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
    GameView * m_GameView;
    // Sound of lost ball has to be played at the game instance because the 
    // ball itself gets deleted before it is able to play the sound
    QMediaPlayer* m_SoundLostBall;
};

#endif // GAME_H
