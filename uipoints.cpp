#include "uipoints.h"
#include <QFont>

UiPoints::UiPoints(QString _UiText, int _StartAmount, QGraphicsItem * _Parent)
    : QGraphicsTextItem(_Parent)
    , m_Points(_StartAmount)
    , m_UiText(_UiText)
{
    setPlainText(QString(m_UiText) + QString::number(m_Points));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 16));
}

void UiPoints::m_IncreasePoints(int _Amount)
{
    m_Points += _Amount;
    setPlainText(QString(m_UiText) + QString::number(m_Points));
}

void UiPoints::m_DecreasePoints(int _Amount)
{
    m_Points -= _Amount;
    setPlainText(QString(m_UiText) + QString::number(m_Points));
}

int UiPoints::m_GetPoints()
{
    return m_Points;
}
