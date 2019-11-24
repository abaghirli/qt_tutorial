#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Player :public QObject, public QGraphicsRectItem{
    Q_OBJECT
protected:
    virtual void keyPressEvent(QKeyEvent * ev);
public slots:
    void spawn();
};

#endif // MYRECT_H
