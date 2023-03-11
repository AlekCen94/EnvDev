#include "envcontainerprop.h"
#include "ui_envcontainerprop.h"
#include <qdebug.h>

EnvContainerProp::EnvContainerProp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnvContainerProp)
{
    ui->setupUi(this);
    initialize();
}

EnvContainerProp::~EnvContainerProp()
{
    delete ui;
}

///@brief Method for initialize.
///
void EnvContainerProp::initialize()
{
    ui->tabWidget->setTabText(0,"Docker");
    ui->tabWidget->setTabText(1,"VirtualBox");

    connect(ui->m_addPortButton,SIGNAL(clicked()),this,SLOT(addPortClicked()));
    connect(ui->m_remotePortButton,SIGNAL(clicked()),this,SLOT(removePortClicked()));
}

///< Slot called when addport button clicked.
void EnvContainerProp::addPortClicked()
{
    //ui->m_portListWidget->addItem(QString::number(ui->m_portHSpinbox->value()) + " : " + QString::number(ui->m_portDMSpinbox->value()));

    ui->m_portListWidget->addItem(new QListWidgetItem(QString::number(ui->m_portHSpinbox->value()) + " : " + QString::number(ui->m_portDMSpinbox->value()),ui->m_portListWidget));
}

///< Slot called when removeport button clicked.
void EnvContainerProp::removePortClicked()
{
    qDeleteAll(ui->m_portListWidget->selectedItems());
    qDebug()<<"remove";
}
