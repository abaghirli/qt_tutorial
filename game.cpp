#include "game.h"
#include "player.h"
#include "enemy.h"
#include "settings.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QTransform>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QEvent>

Game::Game(SettingsManager* sMgr, QApplication* a,  QWidget *parent){
    scene = new QGraphicsScene();
    app = a;
    scene->setSceneRect(0, 0, game_scene_width, game_scene_height);
    setBackgroundBrush(QBrush(QImage(":/graphics/cloudy.png")));
    blt_sprite = QPixmap(":/graphics/bullet.png").scaledToHeight(bullet_height, Qt::SmoothTransformation);
    sprites = new QPixmap(":/graphics/sprites.png");
    plr_sprite = sprites->copy(0, 21, 20, 20).scaledToHeight(player_height, Qt::SmoothTransformation);
    enm_sprite = sprites->copy(0, 0, 20, 20).scaledToHeight(enemy_height, Qt::SmoothTransformation);
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _sManager = sMgr;
    QSound * back = new QSound(":/sound/back.wav");
    back->setLoops(-1);
    back->play();
    fail = new QMediaPlayer();
    fail->setMedia(QUrl("qrc:/sound/fail.mp3"));
    fail->setVolume(_sManager->getIntSetting("game/sound"));
    kill = new QMediaPlayer();
    kill->setMedia(QUrl("qrc:/sound/kill.mp3"));
    kill->setVolume(_sManager->getIntSetting("game/sound"));
    shot = new QSound(":/sound/shot.wav");
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));

    show();
    startscreen();
    //startgame();
}

void Game::pause()
{
    // stop all processes

}

void Game::startgame()
{
    scene->removeItem(p_qbp);
    scene->removeItem(p_sbp);
    player = new Player(this);
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
    timer->start(1000/_sManager->getIntSetting("game/spawn/speed"));
}

void Game::testslotstart()
{
    qDebug() << "start pressed";
    startgame();
}

void Game::testslotquit()
{
    qDebug() << "quit pressed";
    qDebug() << this->parent();
}

void Game::startscreen()
{
    QPushButton* p_btns = new QPushButton("Start");
    p_sbp = scene->addWidget(p_btns);
    p_sbp->resize(game_scene_width/3, game_scene_height/6);
    p_sbp->setPos((game_scene_width-game_scene_width/3)/2, game_scene_height/2 - game_scene_height/6 - 5);
    connect(p_btns, SIGNAL(clicked()), this, SLOT(testslotstart()));

    QPushButton* p_btnq = new QPushButton("Quit");
    p_qbp = scene->addWidget(p_btnq);
    p_qbp->resize(game_scene_width/3, game_scene_height/6);
    p_qbp->setPos((game_scene_width-game_scene_width/3)/2, game_scene_height/2 + 5);
    connect(p_btnq, SIGNAL(clicked()), app, SLOT(quit()));
}

void Game::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

void Game::spawn()
{
    Enemy * enemy = new Enemy(this);
    scene->addItem(enemy);
    info->incCreated();
    info->incInGame();
}
