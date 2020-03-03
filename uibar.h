#ifndef UIBAR_H
#define UIBAR_H

#include <QGraphicsItemGroup>
#include <QGraphicsScene>

class UiPoints;

// This UiBar is a GraphicsItemGroup that contains two UiPoints members to 
// display the players score and lifepoints and to provide a handle for them.
class UiBar : public QGraphicsItemGroup
{
public:
	// Parent is the GraphicsScene this is in
	UiBar(QGraphicsScene * parent);
	~UiBar();
public:
	// Returns the score uiPoints
	UiPoints* m_GetScore();
	// Returns the lifepoint uiPoints
	UiPoints* m_GetLifes();
private:
	// This score uiPoints
	UiPoints* m_Score;
	// This lifepoints uiPoints
	UiPoints* m_Lifes;
};

#endif // UIBAR_H
