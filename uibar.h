#ifndef UIBAR_H
#define UIBAR_H

#include <QGraphicsItemGroup>
#include <QGraphicsScene>

class UiPoints;

class UiBar : public QGraphicsItemGroup
{
public:
	UiBar(QGraphicsScene * parent);
	~UiBar();
public:
	UiPoints* m_GetScore();
	UiPoints* m_GetLifes();
private:
	UiPoints* m_Score;
	UiPoints* m_Lifes;
};

#endif // UIBAR_H
