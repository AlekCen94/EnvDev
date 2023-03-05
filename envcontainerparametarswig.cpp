#include "envcontainerparametarswig.h"
#include "ui_envcontainerparametarswig.h"
#include "abstractenvobject.h"
#include "envitem.h"
#include "maptable.h"
#include "envscene.h"
#include <qpushbutton.h>
#include <QDebug>
#include <QFileDialog>


EnvContainerParametarsWig::EnvContainerParametarsWig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvContainerParametarsWig)
{
    ui->setupUi(this);

    m_map = nullptr;
    initialize();
}

EnvContainerParametarsWig::~EnvContainerParametarsWig()
{
    delete ui;
    m_map = nullptr;
    delete m_containerDoc;
}

///@brief Method return map pointer.
///
MapTable *EnvContainerParametarsWig::getMap() const
{
    return m_map;
}

///@brief Method set Map pointer.
/// @param MapTable *map > Map poinetr.
///
void EnvContainerParametarsWig::setMap(MapTable *map)
{
    m_map = map;
}


///@brief Method for initialize.
///
void EnvContainerParametarsWig::initialize()
{
    m_propDialog = new EnvContainerProp(this);
    m_containerDoc = new TiXmlDocument();

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectEnvItem(QListWidgetItem*)));

    ui->m_addButton->setFixedSize(QSize(50,50));
    ui->m_removeButton->setFixedSize(QSize(50,50));

    ui->m_addButton->setIcon(QIcon(":icons/icons/add.png"));
    ui->m_removeButton->setIcon(QIcon(":icons/icons/minus.png"));


    connect(ui->m_addButton,SIGNAL(clicked()),this,SLOT(addClick()));
    connect(ui->m_removeButton,SIGNAL(clicked()),this,SLOT(removeClick()));
    connect(ui->m_drawButton,SIGNAL(toggled(bool)),this,SLOT(checkedDraw(bool)));
    connect(ui->m_lineButton,SIGNAL(toggled(bool)),this,SLOT(checkLine(bool)));
    connect(ui->m_deleteButton,SIGNAL(toggled(bool)),this,SLOT(checkDelete(bool)));
    connect(ui->m_SaveButton,SIGNAL(clicked()),this,SLOT(saveClick()));


    addItem(new EnvItem("VM"));
    addItem(new EnvItem("Vegrant"));
    addItem(new EnvItem("Docker"));
    addItem(new EnvItem("Docker"));

}

///@brief Method for adding item.
/// @param EnvItem* item > item.
///
void EnvContainerParametarsWig::addItem(EnvItem* item)
{
    m_items.append(item);

    ui->listWidget->addItem(item);

}

///@brief Method for removing item.
/// @param QPointer<EnvItem>item > item.
///
void EnvContainerParametarsWig::removeItem(EnvItem* item)
{
    m_items.removeOne(item);
     ui->listWidget->removeItemWidget(item);

}

///@brief Method for searching item by name.
/// @param QString& name > name of item.
///
EnvItem* EnvContainerParametarsWig::getItemByName(QString name)
{
    for (int var = 0; var < m_items.size(); ++var) {
        if(m_items[var]->getName() == name)
            return m_items[var];
    }
    return nullptr;
}

///@brief Method for searching item by unique identifier.
/// @param quint64& unique > id of item.
///
EnvItem* EnvContainerParametarsWig::getItemById(quint64 &unique)
{
    for (int var = 0; var < m_items.size(); ++var) {
        if(m_items[var]->unique() == unique)
            return m_items[var];
    }
    return nullptr;
}

///@brief Method return selected item.
///
EnvItem* EnvContainerParametarsWig::getSelectedItem()
{
    for (int var = 0; var < m_items.size(); ++var) {
        if(m_items[var]->selected())
            return m_items[var];
    }
    return nullptr;
}
///@brief Method clear items.
///
void EnvContainerParametarsWig::clear()
{
    ui->listWidget->clear();

}

///< Click slot for add button
void EnvContainerParametarsWig::addClick()
{
    m_propDialog->show();
}

///< Slot for checking draw button.
void EnvContainerParametarsWig::checkedDraw(bool checked)
{
    qDebug()<<"checked\n";

    if(m_map->scene()->line())
    {
        m_map->scene()->setLine(false);
        ui->m_lineButton->setChecked(false);
    }
    m_map->scene()->setDraw(checked);
}

///< Slot for checking line button.
void EnvContainerParametarsWig::checkLine(bool checked)
{
    qDebug()<<"Line checked\n";

    if(m_map->scene()->draw())
    {
        m_map->scene()->setDraw(false);
        ui->m_drawButton->setChecked(false);
    }
    m_map->scene()->setLine(checked);
}

///< Click slot for remove button.
void EnvContainerParametarsWig::removeClick()
{
    qDeleteAll(ui->listWidget->selectedItems());
}

///< Slot for select item.
void EnvContainerParametarsWig::selectEnvItem(QListWidgetItem *item)
{

    m_map->setSelectedtemName(dynamic_cast<EnvItem*>(item)->getName());
    qDebug()<<"Selected\n";

}

///< Slot for checking delete button.
void EnvContainerParametarsWig::checkDelete(bool checked)
{
    AbstractEnvObject::setDeleteAllowed(checked);
     m_map->scene()->setDelete(checked);
    qDebug()<<"Delete checked\n";

    m_map->scene()->setLine(false);
    ui->m_lineButton->setChecked(false);

    m_map->scene()->setDraw(false);
    ui->m_drawButton->setChecked(false);


}

///< Click slot for save button.
void EnvContainerParametarsWig::saveClick()
{
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    m_containerDoc->LinkEndChild(decl);
    foreach (EnvItem*item, m_items) {
        TiXmlElement* element = new TiXmlElement(item->getName().toStdString());
        m_containerDoc->LinkEndChild(element);

    }

    QString filePath = QFileDialog::getSaveFileName(this, "Save containers", ".", "*.xml");
    m_containerDoc->SaveFile(filePath.toStdString());
}


