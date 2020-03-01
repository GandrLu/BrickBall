#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsRotation>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>
#include <qmath.h>
#include <qmediaplaylist.h>
#include <qmediaplayer.h>

class Game;

// Has to derive from QObject to use signals and slots
class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(Game* _Game, QObject* _Parent = 0);
public:
    int m_GetSize();
    void m_Fire();
public slots:
    void m_Move();
private:
    bool m_Fired;
    int m_Size;
    int m_Speed;
    QGraphicsRotation m_MovementRotation;
    // Works better with different players because switching the sound files in
    // one takes to long and avoids playing different sounds in a fast sequence
    QMediaPlayer* m_SoundDefault;
    QMediaPlayer* m_SoundScore;
    Game* m_Game;
private:
    void m_PlaySound(int _Type = 0);
};


#endif // BALL_H
