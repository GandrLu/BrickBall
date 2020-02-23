#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Game;

class PowerUp : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	PowerUp(Game * _Game, QObject *parent = 0);
	~PowerUp();
public:
	virtual void m_ExecuteCollision() = 0;
	void m_Drop();
	void m_AddToScene();
public slots:
	void move();
protected:
	int m_PlayAreaHeight;
	Game* m_Game;
private:
	bool m_IsDropped;
};

#endif // POWERUP_H
