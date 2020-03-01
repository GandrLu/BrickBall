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

// This MainMenu is the entry point for the player on start of the application.
// It sets up buttons to start and quit the game.
class MainMenu : public QGraphicsScene
{
	Q_OBJECT
public:
	// _Width and _Height of the application, _ParentView is a reference to the 
	// GameView this menu is in
	MainMenu(int _Width, int _Height, GameView* _ParentView);
	~MainMenu();
public slots:
	// Slot for a button to load the game scene
	void s_StartGame();
private:
	// TextItem that shows the application title
	QGraphicsTextItem * m_TextTitle;
	// TextItem that shows the copyright text
	QGraphicsTextItem * m_TextCopyright;
	// PushButton that starts the game scene
	QPushButton * m_ButtonPlay;
	// PushButton that quits the application
	QPushButton * m_ButtonExit;
	// Reference to the GameView this menu is in
	GameView * m_GameView;
};

#endif // MAINMENU_H
