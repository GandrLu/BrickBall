#include "uibar.h"
#include <QDebug>
#include <QGraphicsLineItem>
#include "uipoints.h"

UiBar::UiBar(QGraphicsScene * parent)
{
	// Value to center texts
	float halfWidth = parent->width() * 0.5f;
	// Create score points
	m_Score = new UiPoints("SCORE ", 0, this);
	// Place before center
	m_Score->setPos(halfWidth - m_Score->boundingRect().width() - 20, 0);
	parent->addItem(m_Score);
	addToGroup(m_Score);

	// Create life points
	m_Lifes = new UiPoints("LIFES ", 3, this);
	// Place after center
	m_Lifes->setPos((qreal)halfWidth + 20, 0);
	parent->addItem(m_Lifes);
	addToGroup(m_Lifes);
}

UiBar::~UiBar()
{
	delete m_Score;
	delete m_Lifes;
}

UiPoints* UiBar::m_GetScore()
{
	return m_Score;
}

UiPoints* UiBar::m_GetLifes()
{
	return m_Lifes;
}
