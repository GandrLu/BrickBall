#include "mainmenu.h"
#include <qdebug.h>
#include "gameview.h"

MainMenu::MainMenu(int _Width, int _Height, GameView* _ParentView)
    : m_GameView(_ParentView)
{
    // Vertical distance between text/button elements
    float vDistanceBetweenElements = _Height / 5;

    // Set background pic
    QPixmap background = QPixmap(":/images/resources/images/background_simple.png");
    addPixmap(background.scaled(_Width, _Height))->setPos(0, 0);

    // Title Text
    m_TextTitle = new QGraphicsTextItem("Brick Ball");
    m_TextTitle->setDefaultTextColor(Qt::black);
    m_TextTitle->setFont(QFont("Courier", 18, 75)); // Weight 75 for Bold
    m_TextTitle->setPos((_Width - m_TextTitle->boundingRect().width()) * 0.5, vDistanceBetweenElements);
    addItem(m_TextTitle);

    // Button Play
    m_ButtonPlay = new QPushButton("Play");
    m_ButtonPlay->setFont(QFont("Courier", 14, 63)); // Weight 63 for Demi Bold
    addWidget(m_ButtonPlay);
    m_ButtonPlay->move((_Width - m_ButtonPlay->width()) * 0.5, vDistanceBetweenElements * 2);
    connect(m_ButtonPlay, SIGNAL(clicked()), this, SLOT(s_StartGame()));

    // Button Exit
    m_ButtonExit = new QPushButton("Exit");
    m_ButtonExit->setFont(QFont("Courier", 14, 63));
    addWidget(m_ButtonExit);
    m_ButtonExit->move((_Width - m_ButtonExit->width()) * 0.5, vDistanceBetweenElements * 2 + m_ButtonPlay->height() * 2);
    connect(m_ButtonExit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    // Copyright Text
    QChar copyrightSign = QChar(0xA9);
    QString copyrightText = " 2020 by Luzius Koelling";
    m_TextCopyright = new QGraphicsTextItem(copyrightSign + copyrightText);
    m_TextCopyright->setDefaultTextColor(Qt::black);
    m_TextCopyright->setFont(QFont("Courier", 8));
    m_TextCopyright->setPos((_Width - m_TextCopyright->boundingRect().width()) * 0.5, vDistanceBetweenElements * 4);
    addItem(m_TextCopyright);
}

MainMenu::~MainMenu()
{
    delete m_TextTitle;
    delete m_ButtonPlay;
    delete m_ButtonExit;
    delete m_TextCopyright;
}

void MainMenu::s_StartGame()
{
    m_GameView->m_LoadGame();
}
