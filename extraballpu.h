#ifndef EXTRABALLPU_H
#define EXTRABALLPU_H

#include <powerup.h>

class ExtraBallPU : public PowerUp
{
public:
	ExtraBallPU(Game* _Game, QObject* parent = 0);
	~ExtraBallPU();
private:
	void m_ExecuteCollision();
};

#endif // EXTRABALLPU_H
