#include "gameview.h"
#include "game.h"
#include "mainmenu.h"

GameView::GameView(int _Width, int _Height)
    : m_Game(nullptr)
    , m_GameWidth(_Width)
    , m_GameHeight(_Height)
{
    showFullScreen();
    // This line seems not to work when initialized in initialization list, 
    // maybe because of "this"
    m_MainMenu = new MainMenu(width(), height(), this);
    
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
    }
}

void GameView::m_LoadMainMenu()
{
    setScene(m_MainMenu);
    //show(); // needed?
    //if (m_Game != nullptr)
        //delete m_Game;
    // Show cursor
    QGuiApplication::setOverrideCursor(Qt::ArrowCursor);
}

void GameView::m_LoadGame()
{
    // Create new game to wipe old game state
    m_Game = new Game(m_GameWidth, m_GameHeight, this);
    setScene(m_Game);
    show(); // needed?
    // Hide cursor
    QGuiApplication::setOverrideCursor(Qt::BlankCursor);
}
