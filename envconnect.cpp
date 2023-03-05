#include "envconnect.h"
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>
#include <QDebug>

EnvConnect::EnvConnect(QObject* parent) :
    QObject(parent)
{

}

EnvConnect::~EnvConnect()
{

}

envType EnvConnect::getType()
{
    return envType::CONNECT;
}

QString EnvConnect::getName()
{
    return m_name;
}

void EnvConnect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setLine(m_mouseStartPoint.x(),m_mouseStartPoint.y(),m_mousePoint.x(),m_mousePoint.y());
    painter->drawText(m_mouseStartPoint,"111111");
    painter->drawLine(line());
    update();


}

///Mouse press event.
void EnvConnect::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::MouseButton::LeftButton)
   {
       //setLine(line().x1(),line().y1(),mouseEvent->scenePos().x(),mouseEvent->scenePos().y());

        //update();
   }
    QGraphicsItem::mousePressEvent(mouseEvent);

}

///Mouse move event.
void EnvConnect::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    m_mousePoint = mouseEvent->scenePos();

    update();
    QGraphicsItem::mouseMoveEvent(mouseEvent);
}
///Mouse release event.
void EnvConnect::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    setLine(line().x1(),line().y1(),mouseEvent->scenePos().x(),mouseEvent->scenePos().y());
    qDebug()<<"MoveLine\n";

    update();
    QGraphicsItem::mouseReleaseEvent(mouseEvent);

}

QPointF EnvConnect::mouseStartPoint() const
{
    return m_mouseStartPoint;
}

void EnvConnect::setMouseStartPoint(QPointF newMouseStartPoint)
{
    m_mouseStartPoint = newMouseStartPoint;
}

bool EnvConnect::firstClick() const
{
    return m_firstClick;
}

void EnvConnect::setFirstClick(bool newFirstClick)
{
    m_firstClick = newFirstClick;
}

QPointF EnvConnect::getMousePoint() const
{
    return m_mousePoint;
}

void EnvConnect::setMousePoint(const QPointF &mousePoint)
{
    m_mousePoint = mousePoint;
}

