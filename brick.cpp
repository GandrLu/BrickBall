#include "brick.h"
#include <QGraphicsScene>
#include "game.h"
#include "extraballpu.h"

Brick::Brick(BrickType _type, int _BrickWidth, int _BrickHeight)
	: m_Type(_type)
	, m_PowerUp(nullptr)
{
	switch (m_Type)
	{
	case red:
		setPixmap(QPixmap(":/images/resources/images/brick_red.png").scaled(_BrickWidth, _BrickHeight));
		m_ScoreValue = 80;
		m_LifePoints = 3;
		break;
	case blue:
		setPixmap(QPixmap(":/images/resources/images/brick_blue.png").scaled(_BrickWidth, _BrickHeight));
		m_ScoreValue = 10;
		m_LifePoints = 1;
		break;
	case green:
		setPixmap(QPixmap(":/images/resources/images/brick_green.png").scaled(_BrickWidth, _BrickHeight));
		m_ScoreValue = 20;
		m_LifePoints = 1;
		break;
	case brown:
		setPixmap(QPixmap(":/images/resources/images/brick_brown.png").scaled(_BrickWidth, _BrickHeight));
		m_ScoreValue = 40;
		m_LifePoints = 2;
		break;
	default:
		setPixmap(QPixmap(":/images/resources/images/brick_blue.png").scaled(_BrickWidth, _BrickHeight));
		m_ScoreValue = 10;
		m_LifePoints = 1;
		break;
	}
}

Brick::~Brick()
{
	if (this->m_PowerUp != nullptr)
	{
		m_PowerUp->m_AddToScene();
		m_PowerUp->m_Drop();
	}
}

void Brick::m_ReduceLifePoints(int _Value)
{
	this->m_LifePoints -= _Value;
}

void Brick::m_AddPowerUp(Game * _Game)
{
	m_PowerUp = new ExtraBallPU(_Game);
	m_PowerUp->setPos(x(), y());
}

int Brick::m_GetScoreValue()
{
	return this->m_ScoreValue;
}

int Brick::m_GetLifePoints()
{
	return this->m_LifePoints;
}
