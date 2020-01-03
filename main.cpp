#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "paddle.h"
#include "brick.h"
#include "game.h"
#include "mainmenu.h"


Game * game;

int main(int argc, char *argv[])
{
    qDebug() << "Create Application";
    QApplication application(argc, argv);
    QGraphicsView* view;
    qDebug() << "Create Scene";
    game = new Game();

    // Hide cursor
    //application.setOverrideCursor(QCursor(Qt::BlankCursor));
    
    qDebug() << "Create view";
    view = new QGraphicsView();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->setMouseTracking(true);
    
    MainMenu* mainmenu = new MainMenu(800, 600, view, game);
    view->setScene(mainmenu);
    view->show();

    return application.exec();
}
