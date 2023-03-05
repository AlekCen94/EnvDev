#include "envsearchitem.h"
#include "QPainter"

EnvSearchItem::EnvSearchItem()
{

}

EnvSearchItem::~EnvSearchItem()
{

}

envType EnvSearchItem::getType()
{
    return envType::SEARCH_ITEM;
}

QString EnvSearchItem::getName()
{
    return "Search item";
}

void EnvSearchItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());

}

QRectF EnvSearchItem::boundingRect() const
{
    return m_rect;
}

void EnvSearchItem::setRect(const QRectF &rect)
{
    m_rect = rect;
}

const QString &EnvSearchItem::owner() const
{
    return m_owner;
}

qint32 EnvSearchItem::stars() const
{
    return m_stars;
}
