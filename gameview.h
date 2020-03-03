#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

class Game;
class MainMenu;

// GameView is a QGraphicsView that manages the application. It sets up the main
// menu and the playable game itself and switches between them. 
class GameView : public QGraphicsView
{
	Q_OBJECT

public:
	// _Width and _Height of the application
	GameView();
	~GameView();
public:
	// Event on pressing of a key of the keyboard, when pressing escape in the 
	// game, the main menu is loaded
	void keyPressEvent(QKeyEvent* event);
	// Loads the main menu scene
	void m_LoadMainMenu();
	// Loads the game/level scene
	void m_LoadGame();
private:
	// The width of the Game
	int m_GameWidth;
	// The height of the Game
	int m_GameHeight;
	// Reference to the Game this GameView is holding
	Game* m_Game;
	// Reference to the MainMenu this GameView is holding
	MainMenu* m_MainMenu;
};

#endif // GAMEVIEW_H
