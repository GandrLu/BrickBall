#ifndef UIPOINTS_H
#define UIPOINTS_H

#include <QGraphicsTextItem>

class UiPoints : public QGraphicsTextItem
{
public:
    UiPoints(QString _UiText, int _StartAmount = 10, QGraphicsItem * _Parent = 0);
public:
    void m_IncreasePoints(int _Amount = 10);
    void m_DecreasePoints(int _Amount = 1);
    int  m_GetPoints();
private:
    int m_Points;
    QString m_UiText;
};

#endif // UIPOINTS_H
