#include "enemy.h"
#include "consts.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy()
{
    int rn = rand() % (game_scene_width-enemy_width);
    qDebug() << "scene:" << game_scene_width << "enemy:" << enemy_width << "range:" << game_scene_width-enemy_width << "random:" << rn;
    setPos(rn, 0);
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 0, 20, 20).scaledToHeight(enemy_height, Qt::SmoothTransformation));
    qDebug() << "new enemy. height:" << this->pixmap().height() << this->pixmap().width();
    fail = new QMediaPlayer();
    fail->setMedia(QUrl("qrc:/sound/fail.mp3"));
    fail->setVolume(50);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+2);
    if (pos().y()-boundingRect().height() > game_scene_height){
        qDebug() << "borect" << boundingRect();
        fail->play();
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy deleted";
    }
}

