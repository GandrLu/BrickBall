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
    //QGraphicsScene * scene = new QGraphicsScene();
    //scene->setSceneRect(0, 0, 800, 600);
    game = new Game();

    qDebug() << "Create Paddle";
    Paddle * paddle = new Paddle(game);
    //paddle->setRect(0, 0, 100, 20);
    //paddle->setFlag(QGraphicsItem::ItemIsFocusable);
    //paddle->setFocus();
    //paddle->setPos(game->width() * 0.5 - 50, game->height() - 20);
    //game->addItem(paddle);


    //Brick * brick = new Brick();
    //brick->setRect(0, 0, 80, 30);
    //brick->setPos(game->width() * 0.5 - 50, 0);

    //game->addItem(brick);

    qDebug() << "Create view";
    QGraphicsView * view = new QGraphicsView(game);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->show();

    return a.exec();
}
