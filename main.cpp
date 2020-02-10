#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "paddle.h"
#include "brick.h"
#include "game.h"
#include "mainmenu.h"
#include "gameview.h"


int main(int argc, char *argv[])
{
    qDebug() << "Create Application";
    QApplication application(argc, argv);
    qDebug() << "Create view";
    GameView* appFrame = new GameView(800, 600);
    qDebug() << "Create Scene";
    
    //MainMenu* mainMenu = new MainMenu(800, 600, appFrame);
    //appFrame->setScene(mainMenu);
    //appFrame->showFullScreen();
    qDebug() << "Width: " << appFrame->width();
    //appFrame->show();

    return application.exec();
    delete appFrame;
}
