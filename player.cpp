#include "player.h"
#include "consts.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    shot = new QSound(":/sound/shot.wav");
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation));
    delete sprites;
    movleft = false;
    movright = false;
    movetimer = new QTimer();
    firetimer = new QTimer();
    connect(movetimer, SIGNAL(timeout()), this, SLOT(move()));
    connect(firetimer, SIGNAL(timeout()), this, SLOT(fire()));
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        movleft  = true;
        movright = false;
        movetimer->start(3);
    }
    else if (event->key() == Qt::Key_Right){
        movleft  = false;
        movright = true;
        movetimer->start(3);
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
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+(player_width/2 - bullet_width/2), y());
        scene()->addItem(bullet);
        //shot->play();
        firetimer->start(30);
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
        firetimer->stop();
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
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+(player_width/2 - bullet_width/2), y());
    scene()->addItem(bullet);
    shot->play();
}
