#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsRotation>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>
#include <qmath.h>
#include <qmediaplaylist.h>
#include <qmediaplayer.h>

class Game;

// Ball is the PixmapItem that moves over the screen, destroys bricks and 
// bounces from them as well as from the paddle and the game borders. 
// Except from the bottom border, when it goes lower than that, the ball is
// lost and destroyed.
// Has to derive from QObject to use signals and slots
class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // _Game parameter is reference to the game this brick is in
    Ball(Game* _Game, QObject* _Parent = 0);
    ~Ball();
public:
    // Returns the diameter of the ball in pixels
    int m_GetSize();
    // Starts the movement of the ball
    void m_Fire();
public slots:
    // A slot that moves the ball each time it is called and checks for 
    // collisions and game borders
    void m_Move();
private:
    // Flag that indicates if the ball is fired or still laying on the paddle
    bool m_Fired;
    // The diameter of the ball
    int m_Size;
    // The movement speed
    int m_Speed;
    // The rotation of the ball, is a member additionally to the QGraphicsRotation
    // of the QGraphicsPixmapItem to avoid rotating of itself because that would
    // rotate the picture of the ball what is unwanted
    QGraphicsRotation m_MovementRotation;
    // MediaPlayer for bouncing sound
    // Works better with different players because switching the sound files in
    // one takes to long and avoids playing different sounds in a fast sequence
    QMediaPlayer* m_SoundDefault;
    // MediaPlayer for scoring sound
    QMediaPlayer* m_SoundScore;
    // Reference to the game the ball is in
    Game* m_Game;
private:
    // Plays the bouncing, scoring or ball lost sound depending on the _Type 
    // parameter. Without argument it plays the bouncing sound.
    void m_PlaySound(int _Type = 0);
};


#endif // BALL_H
