#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Game;
class QTimer;

// This PowerUp is a abstract class to make different kinds of powerups from.
// Can be attached to and dropped by bricks, moves down when dropped and can be 
// catched by the paddle to provide some improvement or disimprovement to the player.
// Needs to derive from QObject to use slots.
class PowerUp : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	PowerUp(Game * _Game, QObject *parent = 0);
	~PowerUp();
public:
	// Has to be implemented by derivates, is called in move slot
	virtual void m_ExecuteCollision() = 0;
	// Activates the motion state
	void m_Drop();
	// Helper to enable a brick to add this to the game scene when dropped
	void m_AddToScene();
public slots:
	// Moves this downwards when motion state is active
	void move();
protected:
	// The height of the play area this moves in, to check if it passes the 
	// bottom border and vanishes
	int m_PlayAreaHeight;
	// Reference to game scene this is in
	Game* m_Game;
private:
	// Flag to determine if this is in motion state (dropped = in motion)
	bool m_IsDropped;
	// Timer for movement
	QTimer* m_Timer;
};

#endif // POWERUP_H
