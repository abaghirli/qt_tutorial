#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "player.h"
#include "score.h"
#include "health.h"
#include "info.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=nullptr);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Info * info;
    QMediaPlayer * kill;
    QMediaPlayer * fail;
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
