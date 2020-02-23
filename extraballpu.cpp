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
	QList<QGraphicsItem*> colliding_items = collidingItems();
	for (int i = 0, n = colliding_items.size(); i < n; ++i)
	{
		if (typeid (*colliding_items[i]) == typeid (Paddle))
		{
			
			m_Game->increaseAvailableBalls(1);
			delete(this);
			return;
		}
	}
	if (x() >= m_PlayAreaHeight)
		delete(this);
}
