#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget * parent=nullptr);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
};

#endif // GAME_H
