#ifndef ENVCONNECT_H
#define ENVCONNECT_H

#include "abstractenvobject.h"
#include <QGraphicsItem>

class EnvConnect : public QObject, public AbstractEnvObject, public  QGraphicsLineItem
{

public:
    EnvConnect(QObject* parent);  ///< Default constructor.
    ~EnvConnect(); ///< Destructor.

    virtual envType getType() override; ///< Method shoud return type of object.
    virtual QString getName() override; ///< Method shoud return name of object.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) override;

    QPointF getMousePoint() const;

    void setMousePoint(const QPointF &mousePoint);

    bool firstClick() const;
    void setFirstClick(bool newFirstClick);

    QPointF mouseStartPoint() const;
    void setMouseStartPoint(QPointF newMouseStartPoint);

protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse press event.
   void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse move event.
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse release event.

protected:
   QString m_name;  ///< Name of container.

   QPointF m_mousePoint; ///< Mouse coordinate.

   QPointF m_mouseStartPoint; ///< Start point.

   bool m_firstClick;  ///< Bool value if first clicked is set true.
};

#endif // ENVCONNECT_H
