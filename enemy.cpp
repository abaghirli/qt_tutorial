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
    int rn = rand() % (game_scene_width-enemy_width-panel_offset);
    setPos(rn+panel_offset, 0);
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 0, 20, 20).scaledToHeight(enemy_height, Qt::SmoothTransformation));
    delete sprites;
    //fail = new QMediaPlayer();
    //fail->setMedia(QUrl("qrc:/sound/fail.mp3"));
    //fail->setVolume(50);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
    game->passed_enemies++;
}

void Enemy::move()
{
    setPos(x(), y()+2);
    if (pos().y()-boundingRect().height() > game_scene_height){
        //fail->play();
        game->health->decrease();
        game->info->incPassed();
        game->info->decInGame();
        scene()->removeItem(this);
        delete this;
    }
}

