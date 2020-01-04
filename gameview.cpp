#include "gameview.h"
#include "game.h"
#include "mainmenu.h"

GameView::GameView(int _Width, int _Height)
    : m_MainMenu(new MainMenu(_Width, _Height, this))
    , m_Game(new Game(_Width, _Height, this))
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(_Width, _Height);
    //showFullScreen();
    setMouseTracking(true);
}

GameView::~GameView()
{
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
    setScene(m_MainMenu);
    show(); // needed?
    // Show cursor
    QGuiApplication::setOverrideCursor(Qt::ArrowCursor);
}

void GameView::m_LoadGame()
{
    setScene(m_Game);
    show(); // needed?
    // Hide cursor
    QGuiApplication::setOverrideCursor(Qt::BlankCursor);
}
