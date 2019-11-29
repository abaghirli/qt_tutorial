#include "player.h"
#include "consts.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    shot = new QSound(":/sound/shot.wav");
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        {setPos(x()-10, y());}
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + boundingRect().width() < game_scene_width)
        {setPos(x()+10, y());}
    }
    else if (event->key() == Qt::Key_Up){
        qDebug() << "pos" << pos().y();
        qDebug() << "scn" << game_scene_height/2;
        if (pos().y() > game_scene_height/2) {
            setPos(x(), y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() + boundingRect().height() < game_scene_height)
        {setPos(x(), y()+10);}
    }
    else if (event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+(player_width/2 - bullet_width/2), y());
        scene()->addItem(bullet);
        shot->play();
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
