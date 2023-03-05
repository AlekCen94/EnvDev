#include "envcontainersearch.h"
#include "ui_envcontainersearch.h"
#include "envsearchitem.h"
#include "QGraphicsScene"
#include <QDebug>

EnvContainerSearch::EnvContainerSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnvContainerSearch)
{
    ui->setupUi(this);
    Initialize();
}

EnvContainerSearch::~EnvContainerSearch()
{
    delete ui;
}

///@brief Method for initialization.
///
void EnvContainerSearch::Initialize()
{
    setWindowTitle("EnvContainerSearch");
    connect(ui->m_searchButton,SIGNAL(clicked(bool)),this,SLOT(search()));
    connect(ui->m_addItemButton,SIGNAL(clicked(bool)),this,SLOT(add()));
    ui->m_itemsView->setScene(new QGraphicsScene(this));
}

void EnvContainerSearch::search()
{
    if(ui->m_searchLine->text()!= "")
    {
        m_dockerCommand.search(ui->m_searchLine->text());

        //EnvSearchItem* item = new EnvSearchItem();
        //ui->m_itemsView->scene()->addItem(item);
    }
}

void EnvContainerSearch::add()
{
    EnvSearchItem* item = new EnvSearchItem();
    item->setRect(QRectF(0,0,20,20));
    ui->m_itemsView->scene()->addItem(item);
    qDebug()<< "add!!!";
}

const DockerCommand &EnvContainerSearch::dockerCommand() const
{
    return m_dockerCommand;
}
