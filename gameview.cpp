#include "gameview.h"
#include "game.h"
#include "mainmenu.h"

GameView::GameView(int _Width, int _Height)
    /*: m_MainMenu(new MainMenu(width(), height(), this))
    , m_Game(new Game(width(), height(), this))
    , m_GameWidth(width())
    , m_GameHeight(height())*/
{
    showFullScreen();
    m_MainMenu = new MainMenu(width(), height(), this);
    m_Game = new Game(width(), height(), this);
    m_GameWidth = width();
    m_GameHeight = height();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(_Width, _Height);
    //showFullScreen();
    setMouseTracking(true);

    m_LoadMainMenu();
}

GameView::~GameView()
{
    delete m_MainMenu;
    delete m_Game;
}

void GameView::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        m_LoadMainMenu();
    }
}

void GameView::m_LoadMainMenu()
{
    delete m_Game;
    setScene(m_MainMenu);
    show(); // needed?
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
