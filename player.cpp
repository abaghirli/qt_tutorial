#include "player.h"
#include "settings.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

extern SettingsManager * sManager;
extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //shot = new QSound(":/sound/shot.wav");
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation));
    delete sprites;
    movleft = false;
    movright = false;
    movetimer = new QTimer();
    firetimer = new QTimer();
    firing_speed = 1000/sManager->getIntSetting("bullet/firing_speed");
    moving_speed = 1000/sManager->getIntSetting("player/speed");
    connect(movetimer, SIGNAL(timeout()), this, SLOT(move()));
    connect(firetimer, SIGNAL(timeout()), this, SLOT(fire()));
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        movleft  = true;
        movright = false;
        movetimer->start(5);
    }
    else if (event->key() == Qt::Key_Right){
        movleft  = false;
        movright = true;
        movetimer->start(5);
    }
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > game_scene_height/2) {
            setPos(x(), y()-1);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() + boundingRect().height() < game_scene_height)
        {setPos(x(), y()+1);}
    }
    else if (event->key() == Qt::Key_Space){
        if (not firing) {
            firetimer->start(firing_speed);
            firing = true;
            qDebug() << "firing on";
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        movleft  = false;
        movetimer->stop();
    }
    else if (event->key() == Qt::Key_Right){
        movright = false;
        movetimer->stop();
    }
    else if (event->key() == Qt::Key_Space){
        firing = false;
        firetimer->stop();
        qDebug() << "firing off";
    }
}

void Player::move()
{
    if (movleft) {
        if (pos().x() > panel_offset)
        {setPos(x()-1, y());}
    }
    else if (movright){
        if (pos().x() + boundingRect().width() < game_scene_width)
        {setPos(x()+1, y());}
    }
}

void Player::fire()
{
    if (firing){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+(player_width/2 - bullet_width/2), y());
        scene()->addItem(bullet);
        game->shot->play();
        qDebug() << "bullet fired";
    }
    else
        qDebug() << "bullet not fired";
}
