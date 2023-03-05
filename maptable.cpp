#include "maptable.h"
#include "ui_maptable.h"
#include "envcontainer.h"
#include "envscene.h"
#include <QGraphicsTextItem>
#include "envfactory.h"
#include <QDebug>


MapTable::MapTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTable)
{
    ui->setupUi(this);
    initialize();
}

MapTable::~MapTable()
{
    delete ui;
    delete m_scene;
}

///@brief Method for initialize.
///
void MapTable::initialize()
{
    m_scene =  new EnvScene();
    ui->m_tableView->setScene(m_scene);
}
///@brief Method return selected item name.
///
QString MapTable::selectedtemNwme() const
{
    return m_selectedtemName;
}

///@brief Method set selected item.
///@param  QString* selectedtem > selected item name.
///
void MapTable::setSelectedtemName(QString selectedtem)
{

   m_selectedtemName = QString(selectedtem);

   m_scene->setSelectedtemNameForDraw(m_selectedtemName);

}

EnvScene *MapTable::scene() const
{
    return m_scene;
}

void MapTable::mousePressEvent(QMouseEvent *event)
{


    if(event->button() == Qt::MouseButton::RightButton){
        QPixmap pic(ui->m_tableView->grab());
        pic.save("C:/Users/Aleksandar/Desktop/aaaaaaa.png");

    }

}
