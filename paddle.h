#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "ball.h"

class Game;

// The paddle is a PixmapItem that is controlled by the player to keep the ball 
// away from the bottom border, where the ball would vanish. The ball bounces
// from the paddle in an angle depending on the point where it touches the paddle.
// In the middle its exit angle is 90° (measured from the horizontal axis) straight
// upwards, the closer it is to the edges of the paddle, the sharper the angle is,
// reaching from 30° on the left to 150° on the right. The calculation is done in
// ball.cpp though.
class Paddle: public QGraphicsPixmapItem
{
public:
    Paddle(QGraphicsScene * scene = 0);
    ~Paddle();
public:
    // Returns the width of this in pixels
    int m_GetWidth();
    // Sets the position of the x coordinate of this for movement on horizontal axis
    void m_SetXPosition(int _XPos);
    // Sets a ball in motion if a prepared ball is available
    void m_FireBall();
    // Creates a new ball, places it on the paddle, adds it to the scene and 
    // increases the balls in game counter
    void m_PrepareBall(Game * _Game);
private:
    // The width of the paddle in pixels
    int m_Width;
    // The height of the paddle in pixels
    int m_Height;
    // The initial position on x axis
    int m_XPos;
    // The initial position on y axis
    int m_YPos;
    // Reference to the prepared ball
    Ball * m_PreparedBall;
};

#endif // PADDLE_H
