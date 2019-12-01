#include "scenebutton.h"
#include <QStyleOptionGraphicsItem>
#include <QPainter>

SceneButton::SceneButton(const QPixmap pixmap, QGraphicsItem *parent)
    :QGraphicsWidget(parent), _pix(pixmap)
{
    setAcceptHoverEvents(true);
    setCacheMode(DeviceCoordinateCache);
}

QRectF SceneButton::boundingRect() const
{
    return QRectF (-25, -25, 50, 50);
}

QPainterPath SceneButton::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void SceneButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    bool down = option->state & QStyle::State_Sunken;
    QRectF r = boundingRect();
    QLinearGradient grad(r.topLeft(), r.bottomRight());
    grad.setColorAt(down ? 1 : 0, option->state & QStyle::State_MouseOver ? Qt::white : Qt::lightGray);
    grad.setColorAt(down ? 0 : 1, Qt::darkGray);
    painter->setPen(Qt::darkGray);
    painter->setBrush(grad);
    painter->drawEllipse(r);
    grad.setColorAt(down ? 1 : 0, Qt::darkGray);
    grad.setColorAt(down ? 0 : 1, Qt::lightGray);
    painter->setPen(Qt::NoPen);
    painter->setBrush(grad);
    if (down)
        painter->translate(1,1);
    painter->drawEllipse(r.adjusted(3,3,-3,-3));
    painter->drawPixmap(-_pix.width()/2, -_pix.height()/2, _pix);
}

void SceneButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit pressed();
    update();
}

void SceneButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    update();
}
