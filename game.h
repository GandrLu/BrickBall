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

// Game is the QGraphicsScene that holds all elements of the game play area.
// It sets up the level and provides several methods to manage the game.
class Game : public QGraphicsScene
{
public:
    // _Width is the width of the application, _Height is the height of the 
    // application and _ParentView is a reference to the GameView this game is 
    // running in.
    Game(int _Width, int _Height, GameView* _ParentView);
    ~Game();
public:
    // Returns the play area width
    int m_GetAreaWidth() const;
    // Returns the play area height
    int m_GetAreaHeight() const;
    // Returns the user interface bar height
    int m_GetUiBarHeight();
    // Increases the available balls by _Amount but only if the count is lower 
    // than one, when it is it prepares a ball as well, returns current amount
    int m_IncreaseAvailableBalls(int _Amount);
    // Increases the balls in the game by _Amount and returns current count
    int m_IncreaseBallsInGame(int _Amount);
    // Decreases the balls in the game by _Amount and returns current count
    int m_DecreaseBallsInGame(int _Amount);
    // Decreases the bricks in the game by _Amount and returns current count
    int m_DecreaseBricksInGame(int _Amount);
    // Returns reference to the score UiPoints
    UiPoints * m_GetScore();
    // Returns reference to the lifepoint UiPoints
    UiPoints * m_GetLifes();
    // Returns reference to the paddle
    Paddle * m_GetPaddle();
    // Returns reference to the GameView
    GameView * m_GetGameView();
    // Event on movement of the mouse, position of the mouse cursor determines 
    // the position of the paddle
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    // Event on pressing a button of the mouse, when a ball is available it 
    // gets fired and available balls are reduced by one
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    // Plays the ball lost sound
    void m_PlayBallLostSound();
private:
    // The width of the user interface bar
    int m_UiBarWidth;
    // The height of the user interface bar
    int m_UiBarHeight;
    // Width of the area where the are bricks laying in and the ball and the 
    // paddle are moving in
    int m_PlayAreaWidth;
    // Height of the area where the are bricks laying in and the ball and the 
    // paddle are moving in
    int m_PlayAreaHeight;
    // Maximum amount of horizontal brick columns
    int m_MaxHorizontalBricks;
    // Maximum amount of vertical brick rows
    int m_MaxVerticalBricks;
    // The amount of the currently ready to be fired balls laying on the paddle
    int m_AvailableBalls;
    // The amount of fired balls that are moving currently in the level
    int m_BallsInGame;
    // The amount of remaining bricks in the game
    int m_BricksInGame;
    // An array that holds references to all bricks in the level
    Brick * m_Bricks[4][16];
    // Reference to the UiBar in this game
    UiBar * m_UiBar;
    // Reference to the paddle in this game
    Paddle * m_Paddle;
    // Reference to the GameView this game is running in
    GameView * m_GameView;
    // Player for the ball lost sound.
    // Sound of lost ball has to be played at the game instance because the 
    // ball itself gets deleted before it is able to play the sound
    QMediaPlayer* m_SoundLostBall;
};

#endif // GAME_H
