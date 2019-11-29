#include "game.h"
#include "player.h"
#include "consts.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QSound>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, game_scene_width, game_scene_height);
    setBackgroundBrush(QBrush(QImage(":/graphics/cloudy.png")));

    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(game_scene_width, game_scene_height);

    player = new Player();
    player->setPos(game_scene_width/2 - player_width/2, game_scene_height-player_height);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+16);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    QSound * back = new QSound(":/sound/back.wav");
    back->setLoops(-1);
    back->play();

    show();
}
