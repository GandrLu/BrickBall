#ifndef UIPOINTS_H
#define UIPOINTS_H

#include <QGraphicsTextItem>

// This UiPoints is a GraphicsTextItem that displays a text that contains a 
// label and a integer value.
class UiPoints : public QGraphicsTextItem
{
public:
    // _UiText is the text label and _StartAmount is the integer value 
    // displayed initially
    UiPoints(QString _UiText, int _StartAmount = 10, QGraphicsItem * _Parent = 0);
public:
    // Increases this points value by _Amount
    void m_IncreasePoints(int _Amount = 10);
    // Decreases this points value by _Amount
    void m_DecreasePoints(int _Amount = 1);
    // Returns this points value
    int  m_GetPoints();
private:
    // The integer value that represents points
    int m_Points;
    // The text that displays the label for this points
    QString m_UiText;
};

#endif // UIPOINTS_H
