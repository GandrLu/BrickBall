#include "extraballpu.h"
#include "paddle.h"
#include "game.h"
#include "uipoints.h"

ExtraBallPU::ExtraBallPU(Game* _Game, QObject* parent)
	: PowerUp(_Game, parent)
{
	// set graphics
	setPixmap(QPixmap(":/images/resources/images/extraBall.png"));
}

ExtraBallPU::~ExtraBallPU()
{
}

void ExtraBallPU::m_ExecuteCollision()
{
	// Check for collision with the paddle
	QList<QGraphicsItem*> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i)
	{
		if (typeid (*colliding_items[i]) == typeid (Paddle))
		{
			// On paddle collision create a new ball and destroy powerup
			m_Game->m_IncreaseAvailableBalls(1);
			delete(this);
			return;
		}
	}
	// On reaching the bottom border, destroy powerup
	if (x() >= m_PlayAreaHeight)
		delete(this);
}
