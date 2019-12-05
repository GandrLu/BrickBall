#ifndef UITEXT_H
#define UITEXT_H

#include <QGraphicsTextItem>

class UiText : public QGraphicsTextItem
{
public:
    UiText(QGraphicsItem * parent = 0);
public:
    void m_IncreaseScore(int _Amount = 10);
    void m_DecreaseLifePoints();
    int  m_GetScore();
    int  m_GetLifePoints();
private:
    int m_Score;
    int m_LifePoints;
};

#endif // UITEXT_H
