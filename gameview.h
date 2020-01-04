#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

class Game;
class MainMenu;

class GameView : public QGraphicsView
{
	Q_OBJECT

public:
	GameView(int _Width, int _Height);
	~GameView();
public:
	void keyPressEvent(QKeyEvent* event);
	void m_LoadMainMenu();
	void m_LoadGame();
private:
	int m_GameWidth;
	int m_GameHeight;
	Game* m_Game;
	MainMenu* m_MainMenu;
};

#endif // GAMEVIEW_H
