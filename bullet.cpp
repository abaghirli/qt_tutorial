#include "bullet.h"
#include <QTimer>

Bullet::Bullet()
{
    setRect(0, 0, 4, 20);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    setPos(x(), y()-5);
}
