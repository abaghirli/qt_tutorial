#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSound>
#include "player.h"
#include "score.h"
#include "health.h"
#include "info.h"
#include "settings.h"

class Player;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(SettingsManager* sMgr, QWidget* parent=nullptr);
    QGraphicsScene * scene;
    SettingsManager * _sManager;
    Player * player;
    Score * score;
    Health * health;
    Info * info;
    QMediaPlayer * kill;
    QMediaPlayer * fail;
    QSound * shot;
    QPixmap * sprites;
    QPixmap blt_sprite;
    QPixmap plr_sprite;
    QPixmap enm_sprite;    
    int created_enemies, killed_enemies, passed_enemies;
    bool paused;
    void pause();
public slots:
    void spawn();
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // GAME_H
