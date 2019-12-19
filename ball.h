#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRotation>
#include <QObject>
#include <qmediaplayer.h>

class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(QGraphicsItem * parent = 0);
public:
    int GetSize();
public slots:
    void move();
private:
    int m_Size;
    int m_Speed;
    QGraphicsRotation m_MovementRotation;
    // Works better with different players because switching the sound files in
    // one takes to long and avoids playing different sounds in a fast sequence
    QMediaPlayer* m_SoundDefault;
    QMediaPlayer* m_SoundScore;
    QMediaPlayer* m_SoundFail;
private:
    void m_PlaySound(int _Type = 0);
};


#endif // BALL_H
