#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect :public QGraphicsRectItem{
protected:
    virtual void keyPressEvent(QKeyEvent * ev);
};

#endif // MYRECT_H
