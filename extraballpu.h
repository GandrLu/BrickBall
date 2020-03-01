#ifndef EXTRABALLPU_H
#define EXTRABALLPU_H

#include <powerup.h>

// ExtraBallPU is a PowerUp that gives the player one additional ball that spawns
// on the paddle.
class ExtraBallPU : public PowerUp
{
public:
	ExtraBallPU(Game* _Game, QObject* parent = 0);
	~ExtraBallPU();
private:
	// Executes collision check, adds an additional ball to the players paddle, 
	// when it collides with the paddle
	void m_ExecuteCollision();
};

#endif // EXTRABALLPU_H
