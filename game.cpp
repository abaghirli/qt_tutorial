#include "game.h"
#include "player.h"
#include "enemy.h"
#include "consts.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QSound>
#include <QEvent>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, game_scene_width, game_scene_height);
    setBackgroundBrush(QBrush(QImage(":/graphics/cloudy.png")));
    blt_sprite = QPixmap(":/graphics/bullet.png");
    sprites = new QPixmap(":/graphics/sprites.png");
    plr_sprite = sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation);
    enm_sprite = sprites->copy(0, 0, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation);

    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    player->setPos(game_scene_width/2 - player_width/2 - panel_offset/2, game_scene_height-player_height);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+14);
    scene->addItem(health);
    info = new Info();
    info->setPos(info->x(), info->y()+32);
    scene->addItem(info);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(100);

    QSound * back = new QSound(":/sound/back.wav");
    back->setLoops(-1);
    back->play();
    fail = new QMediaPlayer();
    fail->setMedia(QUrl("qrc:/sound/fail.mp3"));
    fail->setVolume(50);
    kill = new QMediaPlayer();
    kill->setMedia(QUrl("qrc:/sound/kill.mp3"));
    kill->setVolume(50);

    show();
}

void Game::pause()
{
    // stop all processes

}

void Game::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

void Game::spawn()
{
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
    info->incCreated();
    info->incInGame();
}
