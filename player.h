#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QSound>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=nullptr);
protected:
    virtual void keyPressEvent(QKeyEvent * ev);
public slots:
    void spawn();
private:
    QSound * shot;
};

#endif // MYRECT_H
