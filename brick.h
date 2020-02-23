#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>
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
public:
    void m_ReduceLifePoints(int _Value = 1);
    int m_GetPointValue();
    int m_GetLifePoints();
private:
    BrickType m_Type;
    int m_PointValue;
    int m_LifePoints;
};

#endif // BRICK_H
