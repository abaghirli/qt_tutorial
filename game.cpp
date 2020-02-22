#include "game.h"
#include "player.h"
#include "enemy.h"
#include "settings.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QEvent>

extern SettingsManager * sManager;

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
    timer->start(1000/sManager->getIntSetting("game/spawn/speed"));

    QSound * back = new QSound(":/sound/back.wav");
    back->setLoops(-1);
    back->play();
    fail = new QMediaPlayer();
    fail->setMedia(QUrl("qrc:/sound/fail.mp3"));
    fail->setVolume(sManager->getIntSetting("game/sound"));
    kill = new QMediaPlayer();
    kill->setMedia(QUrl("qrc:/sound/kill.mp3"));
    kill->setVolume(sManager->getIntSetting("game/sound"));
    shot = new QSound(":/sound/shot.wav");

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
