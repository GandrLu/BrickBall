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
	QTimer* timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(18);
}

PowerUp::~PowerUp()
{
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
		this->setPos(x(), y() + 5);
		this->m_ExecuteCollision();
	}
}
