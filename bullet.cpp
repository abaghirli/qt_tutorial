#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game;

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/graphics/bullet.png"));
    QTimer * timer = new QTimer();
    kill = new QMediaPlayer();
    kill->setMedia(QUrl("qrc:/sound/kill.mp3"));
    kill->setVolume(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid (Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            kill->play();
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-5);
    if (pos().y()+pixmap().height() <0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
