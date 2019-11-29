#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    health = 30;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

int Health::getHealth()
{
    return  health;
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::heal(int potion_size)
{
    health+=potion_size;
    setPlainText(QString("Health: ") + QString::number(health));
}


