#include "game.h"
#include "player.h"
#include "consts.h"
#include "score.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, game_scene_width, game_scene_height);

    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(game_scene_width, game_scene_height);

    player = new Player();
    player->setRect(0, 0, 100, 100);
    player->setPos(game_scene_width/2 - player->rect().width()/2, game_scene_height-player->rect().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
    show();
}
