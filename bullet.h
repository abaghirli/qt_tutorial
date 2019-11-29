#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>


class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=nullptr);
private:
    QMediaPlayer * kill;

public slots:
    void move();
};

#endif // BULLET_H
