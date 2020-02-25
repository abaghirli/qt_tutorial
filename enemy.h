#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include "game.h"

class Enemy: public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    Enemy(Game* p_game);
private:
    QMediaPlayer * fail;
    Game * _game;
public slots:
    void move();
};


#endif // ENEMY_H
