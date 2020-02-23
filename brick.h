#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>

class Game;
class PowerUp;

enum BrickType
{
    red,
    blue,
    green,
    brown
};

class Brick : public QGraphicsPixmapItem
{
public:
    Brick(BrickType _type, int _BrickWidth, int _BrickHeight);
    ~Brick();
public:
    void m_ReduceLifePoints(int _Value = 1);
    void m_AddPowerUp(Game * _Game);
    int m_GetPointValue();
    int m_GetLifePoints();
private:
    BrickType m_Type;
    int m_PointValue;
    int m_LifePoints;
    PowerUp *m_PowerUp;
};

#endif // BRICK_H
