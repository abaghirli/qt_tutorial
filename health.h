#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=nullptr);
    int getHealth();
    void decrease();
    void heal(int potion_size=1);
private:
    int health;
};

#endif // HEALTH_H
