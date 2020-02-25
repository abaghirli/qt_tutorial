#include "enemy.h"
#include "settings.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy(Game* p_game)
{
    _game = p_game;
    int rn = rand() % (game_scene_width-enemy_width-panel_offset);
    setPos(rn+panel_offset, 0);
    QPixmap * sprites = new QPixmap(":/graphics/sprites.png");
    setPixmap(sprites->copy(0, 0, 20, 20).scaledToHeight(enemy_height, Qt::SmoothTransformation));
    delete sprites;
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    int speed = _game->_sManager->getIntSetting("enemy/speed");
    timer->start(1000/speed);
    _game->passed_enemies++;
}

void Enemy::move()
{
    setPos(x(), y()+2);
    if (pos().y()-boundingRect().height() > game_scene_height){
        _game->fail->play();
        _game->health->decrease();
        _game->info->incPassed();
        _game->info->decInGame();
        scene()->removeItem(this);
        delete this;
    }
}

