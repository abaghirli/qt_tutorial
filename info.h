#ifndef INFO_H
#define INFO_H

#include <QGraphicsTextItem>

class Info : public QGraphicsTextItem
{
public:
    Info(QGraphicsItem * parent=nullptr);
    void incCreated();
    void incKilled();
    void incPassed();
    void incInGame();
    void decInGame();
private:
    int created, killed, passed, ingame;
};

#endif // INFO_H
