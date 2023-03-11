#include "envcontainer.h"
#include "envitem.h"
#include "qmenu.h"
#include <QPainter>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include <QGraphicsWidget>


QString EnvContainer::m_imagePath = ":icons/icons/dockerCon.png";

EnvContainer::EnvContainer(QObject* parent) :
QObject(parent)
{

}

EnvContainer::~EnvContainer()
{

}

///@brief Constructor with params.
/// @param QString name > name of item.
///
EnvContainer::EnvContainer(const QString &name)
{
    m_name = name;
    setFlag(QGraphicsItem::ItemIsMovable,true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
    setSelected(false);
    m_pressed = false;
    m_selected = false;
    m_imageBuilder.appendBaseImage("Ubuntu");
    m_imageBuilder.appendLabel("Start","BG");
    m_imageBuilder.appendCommand("apt install firefox");
    //m_imageBuilder.exportFile();




}

///@brief Constructor with params.
/// @param EnvItem* item > Item for creation.
///
EnvContainer::EnvContainer(EnvItem *itema)
{

}

envType EnvContainer::getType()
{
    return envType::CONTAINER;
}

QString EnvContainer::getName()
{
    return m_name;
}

void EnvContainer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


        QBrush m_brushBlue(QColor(0,0,250,20));
        QBrush m_brushRed(QColor(250,0,0,20));

        if(!m_selected)
            painter->fillRect(boundingRect(),m_brushBlue);

        else
            painter->fillRect(boundingRect(),m_brushRed);


        m_image.load(m_imagePath);
        painter->drawPixmap(boundingRect(),m_image,m_image.rect());
        painter->drawText(QPoint(boundingRect().center().x(),boundingRect().bottomRight().y()+10),m_name);


}

QRectF EnvContainer::boundingRect() const
{

   return m_rect;

}


void EnvContainer::setRect(const QRectF &rect)
{
    m_rect = rect;
   // update();
}

///Mouse press event.
void EnvContainer::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::MouseButton::LeftButton)
    {
    if(getSelectAllowed())
    { m_pressed = true;
        m_selected = !m_selected;
        if(m_deleteAllowed)
            delete this;
        update();
         QGraphicsItem::mousePressEvent(mouseEvent);

    }
    }
    else if(mouseEvent->button() == Qt::MouseButton::RightButton)
    {
        QMenu menu;
        QAction *at = new QAction("Test"); // Assumes actions is not empty
        menu.addAction(at);

        menu.exec(mouseEvent->screenPos(), at);

    }



}

///Mouse move event.
void EnvContainer::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(getSelectAllowed())
    {
    update();
    QGraphicsItem::mouseMoveEvent(mouseEvent);
    }

}

///Mouse release event.
void EnvContainer::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
        if(getSelectAllowed())
        {
            m_pressed = false;
            update();
             QGraphicsItem::mouseReleaseEvent(mouseEvent);

        }

}


