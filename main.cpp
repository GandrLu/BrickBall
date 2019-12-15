#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "paddle.h"
#include "brick.h"
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    qDebug() << "Create Application";
    QApplication a(argc, argv);

    qDebug() << "Create Scene";
    game = new Game();

    // Hide cursor
    a.setOverrideCursor(QCursor(Qt::BlankCursor));

    qDebug() << "Create view";
    QGraphicsView * view = new QGraphicsView(game);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->setMouseTracking(true);
    view->show();

    return a.exec();
}
