#include "uibar.h"
#include <QDebug>
#include <QGraphicsLineItem>

UiBar::UiBar(QGraphicsScene * parent)
{
	m_Score = new UiPoints("SCORE ", 0, this);
	parent->addItem(m_Score);
	addToGroup(m_Score);
	m_Lifes = new UiPoints("LIFES ", 3, this);
	m_Lifes->setPos(m_Score->boundingRect().width() + 20, 0);
	parent->addItem(m_Lifes);
	addToGroup(m_Lifes);
	qDebug() << "score pos " << m_Score->pos();
	qDebug() << "lifes pos " << m_Score->boundingRect().height();
	QGraphicsLineItem * line = new QGraphicsLineItem(0, 33, 800, 33, this);
	line->setPen(QPen(QBrush(Qt::SolidLine), 2));
	parent->addItem(line);
}

UiBar::~UiBar()
{
}

UiPoints* UiBar::m_GetScore()
{
	return m_Score;
}

UiPoints* UiBar::m_GetLifes()
{
	return m_Lifes;
}
