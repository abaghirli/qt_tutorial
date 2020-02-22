#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "settings.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game;
extern SettingsManager * sManager;

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    int bullet_speed = sManager->getIntSetting("bullet/speed");
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
            game->score->increase();
            game->info->incKilled();
            game->info->decInGame();
            scene()->removeItem(colliding_items[i]);
             scene()->removeItem(this);
            game->kill->play();
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
