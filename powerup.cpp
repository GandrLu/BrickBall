#include "powerup.h"
#include <QTimer>
#include <qdebug.h>
#include "game.h"

PowerUp::PowerUp(Game * _Game, QObject* parent)
	: QObject(parent)
	, m_Game(_Game)
	, m_PlayAreaHeight(_Game->m_GetAreaHeight())
	, m_IsDropped(false)
{
	// set graphics
	setPixmap(QPixmap(":/images/resources/images/ball.png").scaled(15, 15));

	// connect slot
	m_Timer = new QTimer();
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(move()));
	m_Timer->start(18);
}

PowerUp::~PowerUp()
{
	delete m_Timer;
}

void PowerUp::m_Drop()
{
	m_IsDropped = true;
}

void PowerUp::m_AddToScene()
{
	m_Game->addItem(this);
}

void PowerUp::move()
{
	if (this->m_IsDropped)
	{
		// Move 5 pixels down each tick and check collisions
		this->setPos(x(), y() + 5);
		this->m_ExecuteCollision();
	}
}
