#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Enemy: public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    Enemy();
private:
    QMediaPlayer * fail;
public slots:
    void move();
};


#endif // ENEMY_H
