#ifndef SCENEBUTTON_H
#define SCENEBUTTON_H

#include <QGraphicsWidget>

class SceneButton : public QGraphicsWidget
{
    Q_OBJECT
public:
    SceneButton(const QPixmap pixmap, QGraphicsItem * parent = nullptr);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
signals:
    void pressed();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;
private:
    QPixmap _pix;

};

#endif // SCENEBUTTON_H
