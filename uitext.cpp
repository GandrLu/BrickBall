#include "uitext.h"
#include <QFont>

UiText::UiText(QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
    , m_Score(0)
    , m_LifePoints(3)
{
    setPlainText(QString("SCORE ") + QString::number(m_Score));
    setPlainText(QString("LIFES ") + QString::number(m_LifePoints));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 16));
}

void UiText::m_IncreaseScore(int _Amount)
{
    m_Score += _Amount;
    setPlainText(QString("SCORE ") + QString::number(m_Score));
}

void UiText::m_DecreaseLifePoints()
{
    --m_LifePoints;
}

int UiText::m_GetScore()
{
    return m_Score;
}

int UiText::m_GetLifePoints()
{
    return m_LifePoints;
}
