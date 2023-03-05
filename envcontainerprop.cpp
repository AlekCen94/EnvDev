#include "envcontainerprop.h"
#include "ui_envcontainerprop.h"

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
}
