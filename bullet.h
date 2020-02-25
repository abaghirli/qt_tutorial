#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include "game.h"


class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Game* game, QGraphicsItem * parent=nullptr);

public slots:
    void move();

private:
    Game * _game;
};

#endif // BULLET_H
