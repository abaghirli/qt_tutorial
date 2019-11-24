#include "enemy.h"
#include "consts.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy()
{
    int rn = rand() % game_scene_width;
    setPos(rn, 0);
    setRect(0, 0, 50, 50);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+2);
    if (pos().y()-rect().height() > game_scene_height){
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy deleted";
    }
}

