#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>

class Game;
class PowerUp;

// Enum that describes the different brick types
enum BrickType
{
    red,
    blue,
    green,
    brown
};

// Brick is the PixmapItem that has to be destroyed by a ball. It has different
// score values and different lifepoints, depending on its type. One ball
// contact decreases the lifepoints by one.
class Brick : public QGraphicsPixmapItem
{
public:
    Brick(BrickType _Type, int _BrickWidth, int _BrickHeight);
    ~Brick();
public:
    // Reduces this life points by _Value, without argument it is one lifepoint
    void m_ReduceLifePoints(int _Value = 1);
    // Adds a power up to this that is dropped on destruction
    void m_AddPowerUp(Game * _Game);
    // Returns this score value
    int m_GetScoreValue();
    // Returns this life points
    int m_GetLifePoints();
private:
    // The Bricktype this brick is of
    BrickType m_Type;
    // Score value of this
    int m_ScoreValue;
    // Life points of this
    int m_LifePoints;
    // The powerup this brick holds, if it has one
    PowerUp *m_PowerUp;
};

#endif // BRICK_H
