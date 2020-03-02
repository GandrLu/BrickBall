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
    // Create Application
    QApplication application(argc, argv);
    
    // Create view
    GameView* appFrame = new GameView(800, 600);

    return application.exec();
    delete appFrame;
}
