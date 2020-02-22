#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QSound>
#include <QTimer>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=nullptr);
protected:
    virtual void keyPressEvent(QKeyEvent * ev);
    virtual void keyReleaseEvent(QKeyEvent * ev);
private:
    //QSound * shot;
    QTimer * movetimer, * firetimer;
    bool movleft, movright, firing;
    int firing_speed, moving_speed;
private slots:
    void move();
    void fire();
};

#endif // MYRECT_H
