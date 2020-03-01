#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <qmediaplayer.h>

class Brick;
class GameView;
class UiBar;
class UiPoints;
class Paddle;

class Game : public QGraphicsScene
{
public:
    Game(int _Width, int _Height, GameView* _ParentView);
public:
    int m_GetAreaWidth() const;
    int m_GetAreaHeight() const;
    int m_GetUiBarHeight();
    int m_IncreaseAvailableBalls(int _Amount);
    int m_IncreaseBallsInGame(int _Amount);
    int m_DecreaseBallsInGame(int _Amount);
    UiPoints * m_GetScore();
    UiPoints * m_GetLifes();
    Paddle * m_GetPaddle();
    GameView * m_GetGameView();
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void m_PlayBallLostSound();
private:
    int m_UiBarWidth;
    int m_UiBarHeight;
    int m_PlayAreaWidth;
    int m_PlayAreaHeight;
    int m_MaxHorizontalBricks;
    int m_MaxVerticalBricks;
    int m_AvailableBalls;
    int m_BallsInGame;
    //QGraphicsScene m_Scene;
    Brick * m_Bricks[4][16];
    UiBar * m_UiBar;
    Paddle * m_Paddle;
    GameView * m_GameView;
    // Sound of lost ball has to be played at the game instance because the 
    // ball itself gets deleted before it is able to play the sound
    QMediaPlayer* m_SoundLostBall;
};

#endif // GAME_H
