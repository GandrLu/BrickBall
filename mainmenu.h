#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGuiApplication>
#include <QGraphicsView>
#include "game.h"

class MainMenu : public QGraphicsScene
{
	Q_OBJECT
public:
	MainMenu(int _Width, int _Height, QGraphicsView* _View, Game* _Game, QObject* _Parent = 0);
	~MainMenu();
public slots:
	void s_StartGame();
	void s_QuitApplication();
private:
	QGraphicsTextItem * m_TextTitle;
	QGraphicsTextItem * m_TextCopyright;
	QPushButton * m_ButtonPlay;
	QPushButton * m_ButtonExit;
	QGraphicsView * m_View;
	Game * m_Game;
};

#endif // MAINMENU_H
