#include "gameview.h"
#include "game.h"
#include "mainmenu.h"

GameView::GameView()
    : m_Game(nullptr)
{
    showFullScreen();
    // Has to be set up after fullscreen to receive right size
    m_MainMenu = new MainMenu(width(), height(), this);
    m_GameWidth = width();
    m_GameHeight = height();

    // Avoid scrolling in game
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    // Initially load the main menu
    m_LoadMainMenu();
}

GameView::~GameView()
{
    delete m_MainMenu;
    if (m_Game != nullptr)
        delete m_Game;
}

void GameView::keyPressEvent(QKeyEvent* event)
{
    // On press of esc return to main menu
    if (event->key() == Qt::Key_Escape)
    {
        m_LoadMainMenu();
        delete m_Game;
    }
}

void GameView::m_LoadMainMenu()
{
    setScene(m_MainMenu);
    // Show cursor (disabled to enhance paddle control)
    //QGuiApplication::setOverrideCursor(Qt::ArrowCursor);
}

void GameView::m_LoadGame()
{
    // Create new game to wipe old game state
    m_Game = new Game(m_GameWidth, m_GameHeight, this);
    setScene(m_Game);
    // Hide cursor  (disabled to enhance paddle control because when mouse is 
    // outside the gameview the paddle does not move)
    //QGuiApplication::setOverrideCursor(Qt::BlankCursor);
}
