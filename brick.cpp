#include "brick.h"
#include <QGraphicsScene>

Brick::Brick(BrickType _type, int _BrickWidth, int _BrickHeight)
	: m_Type(_type)
{
	switch (m_Type)
	{
	case red:
		setPixmap(QPixmap(":/images/resources/images/brick_red.png").scaled(_BrickWidth, _BrickHeight));
		m_PointValue = 80;
		m_LifePoints = 3;
		break;
	case blue:
		setPixmap(QPixmap(":/images/resources/images/brick_blue.png").scaled(_BrickWidth, _BrickHeight));
		m_PointValue = 10;
		m_LifePoints = 1;
		break;
	case green:
		setPixmap(QPixmap(":/images/resources/images/brick_green.png").scaled(_BrickWidth, _BrickHeight));
		m_PointValue = 20;
		m_LifePoints = 1;
		break;
	case brown:
		setPixmap(QPixmap(":/images/resources/images/brick_brown.png").scaled(_BrickWidth, _BrickHeight));
		m_PointValue = 40;
		m_LifePoints = 2;
		break;
	default:
		setPixmap(QPixmap(":/images/resources/images/brick_blue.png").scaled(_BrickWidth, _BrickHeight));
		m_PointValue = 10;
		m_LifePoints = 1;
		break;
	}
}

void Brick::m_ReduceLifePoints(int _Value)
{
	this->m_LifePoints -= _Value;
}

int Brick::m_GetPointValue()
{
	return this->m_PointValue;
}

int Brick::m_GetLifePoints()
{
	return this->m_LifePoints;
}
