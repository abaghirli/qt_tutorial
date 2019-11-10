#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    MyRect * player = new MyRect();
    player->setRect(0, 0, 100, 100);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    view->show();
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(900, 600);
    scene->setSceneRect(0,0,900,600);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height()-player->rect().height());
    return a.exec();
}
