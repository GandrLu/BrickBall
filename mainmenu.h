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

class GameView;

class MainMenu : public QGraphicsScene
{
	Q_OBJECT
public:
	MainMenu(int _Width, int _Height, GameView* _ParentView);
	~MainMenu();
public slots:
	void s_StartGame();
private:
	QGraphicsTextItem * m_TextTitle;
	QGraphicsTextItem * m_TextCopyright;
	QPushButton * m_ButtonPlay;
	QPushButton * m_ButtonExit;
	GameView * m_GameView;
};

#endif // MAINMENU_H
