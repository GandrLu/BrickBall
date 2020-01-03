#include "mainmenu.h"
#include <qdebug.h>

MainMenu::MainMenu(int _Width, int _Height, QGraphicsView* _View, Game* _Game, QObject* _Parent)
    : m_View(_View)
    , m_Game(_Game)
{
    QPixmap* background = new QPixmap(":/images/resources/images/background_simple.png");
    addPixmap(background->scaled(_Width, _Height))->setPos(0, 0);

    m_TextTitle = new QGraphicsTextItem("Brick Ball");
    m_TextTitle->setDefaultTextColor(Qt::black);
    m_TextTitle->setFont(QFont("terminal", 11, 2));
    m_TextTitle->setPos((_Width - m_TextTitle->boundingRect().width()) * 0.5, 50);
    addItem(m_TextTitle);

    m_ButtonPlay = new QPushButton("Play");
    m_ButtonPlay->setFont(QFont("terminal", 14));
    addWidget(m_ButtonPlay);
    m_ButtonPlay->move((_Width - m_ButtonPlay->width()) * 0.5, 200);
    connect(m_ButtonPlay, SIGNAL(clicked()), this, SLOT(s_StartGame()));
    
    m_ButtonExit = new QPushButton("Exit");
    m_ButtonExit->setFont(QFont("terminal", 14));
    addWidget(m_ButtonExit);
    m_ButtonExit->move((_Width - m_ButtonExit->width()) * 0.5, 250);
    QObject::connect(m_ButtonExit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    QChar copyrightSign = QChar(0xB8);
    QString copyrightText = " 2020 by Luzius Koelling";
    m_TextCopyright = new QGraphicsTextItem(copyrightSign + copyrightText);
    m_TextCopyright->setDefaultTextColor(Qt::black);
    m_TextCopyright->setFont(QFont("terminal", 8));
    m_TextCopyright->setPos((_Width - m_TextCopyright->boundingRect().width()) * 0.5, 500);
    addItem(m_TextCopyright);
}

MainMenu::~MainMenu()
{
}

void MainMenu::s_StartGame()
{
    m_View->setScene(m_Game);
    m_View->show();
    // Hide cursor
    QGuiApplication::setOverrideCursor(Qt::BlankCursor);
}

void MainMenu::s_QuitApplication()
{
    qDebug() << "quit GAME";

}
