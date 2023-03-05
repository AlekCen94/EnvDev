#include "envitem.h"
#include <QPainter>
#include <QDebug>


QSize EnvItem::m_size = QSize(100,50);

qint64 EnvItem::m_count = 0;

bool EnvItem::m_anotherSelected = false;

EnvItem::EnvItem()
{
    m_name = "Unnamed";
    setText(m_name);
    m_count++;
    m_unique = m_count;
    setText(m_name + QString::number(m_unique));
    m_selected = false;
   // setFixedSize(m_size);
   // setStyleSheet("background-color: rgb(85, 170, 255);");
   // setAlignment(Qt::AlignmentFlag::AlignCenter);
    setIcon(QIcon(":/icons/icons/docker(1).png"));

}

EnvItem::~EnvItem()
{

}

///@brief Constructor with params.
/// @param QString name > name of item.
///
EnvItem::EnvItem(const QString& name)
{
    m_name = name;
    m_count++;
    m_unique = m_count;
    setText(m_name + QString::number(m_unique));
    m_selected = false;
   // setFixedSize(m_size);
    //setStyleSheet("background-color: rgb(85, 170, 255);");
    //setAlignment(Qt::AlignmentFlag::AlignCenter);
    setIcon(QIcon(":/icons/icons/docker(3).png"));


}

///@brief Method returm name of item.
///
QString EnvItem::getName()
{
    return m_name;
}

///@brief Method return Unique identifier.
///
qint64 EnvItem::unique()
{
    return m_unique;
}

///@brief Method return Size of item..
///
QSize EnvItem::size()
{
    return m_size;
}
///@brief Method return count of item..
///
qint64 EnvItem::count()
{
    return m_count;
}

///@brief Method return true if another item is selected.
///
bool EnvItem::anotherSelected()
{
    return m_anotherSelected;
}

///@brief Method set true if another item is selected.
/// @param bool anotherSelected > selected value.
///
void EnvItem::setAnotherSelected(bool anotherSelected)
{
    m_anotherSelected = anotherSelected;
}

///@brief Method return true if item is selected.
///
bool EnvItem::selected() const
{
    return m_selected;
}

///@brief Method set true if item is selected.
/// @param bool selected > selected value.
///
void EnvItem::setSelected(bool selected)
{
    m_selected = selected;
}

///< Click event.
void EnvItem::mousePressEvent(QMouseEvent *event)
{

    m_selected = true;
    //setStyleSheet("background-color: rgb(85, 170, 255,50);");
   // if(event->MouseButtonPress == Qt::MouseButton::RightButton)


}

//void EnvItem::paintEvent(QPaintEvent *event)
//{
//    QPainter* m_painter = new QPainter(this);

//    m_painter->drawRect(rect());
//    m_painter->drawText(rect().center(),m_name);

//}
