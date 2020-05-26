#include "player.h"
#include "settings.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

Player::Player(Game* p_game, QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //shot = new QSound(":/sound/shot.wav");
    _game = p_game;
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation));
    delete sprites;
    movleft = false;
    movright = false;
    movetimer = new QTimer();
    firetimer = new QTimer();
    firetimer->setSingleShot(true);
    firing = false;
    firing_speed = 1000/_game->_sManager->getIntSetting("bullet/firing_speed");
    moving_speed = 1000/_game->_sManager->getIntSetting("player/speed");
    connect(movetimer, SIGNAL(timeout()), this, SLOT(move()));
    connect(firetimer, SIGNAL(timeout()), this, SLOT(fire()));
    firetimer->start(firing_speed);
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
            firing = true;
            fire();
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
    if (firing and firetimer->remainingTime() == -1){
        Bullet * bullet = new Bullet(_game);
        bullet->setPos(x()+(player_width/2 - bullet_width/2), y());
        scene()->addItem(bullet);
        _game->shot->play();
        qDebug() << "bullet fired";
        firetimer->start(firing_speed);
    }
    else
        qDebug() << "Timer:" << firetimer->isActive() << "remaining" << firetimer->remainingTime();
        qDebug() << "bullet not fired";
}
