#include "player.h"
#include "consts.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        {setPos(x()-5, y());}
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + rect().width() < game_scene_width)
        {setPos(x()+5, y());}
    }
    else if (event->key() == Qt::Key_Up){
        qDebug() << "pos" << pos().y();
        qDebug() << "scn" << game_scene_height/2;
        if (pos().y() > game_scene_height/2) {
            setPos(x(), y()-5);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if(pos().y() + rect().height() < game_scene_height)
        {setPos(x(), y()+5);}
    }
    else if (event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+48, y());
        scene()->addItem(bullet);
    }

}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
