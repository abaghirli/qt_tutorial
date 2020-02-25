#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

Bullet::Bullet(Game* game, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    _game = game;
    int bullet_speed = _game->_sManager->getIntSetting("bullet/speed");
    setPixmap(game->blt_sprite);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/bullet_speed);
}

void Bullet::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid(*(colliding_items[i])) == typeid (Enemy)){
            _game->score->increase();
            _game->info->incKilled();
            _game->info->decInGame();
            scene()->removeItem(colliding_items[i]);
             scene()->removeItem(this);
            _game->kill->play();
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-5);
    if (pos().y()+pixmap().height() <0){
        scene()->removeItem(this);
        delete this;
    }
}
