#include "envdev.h"
#include "ui_envdev.h"

EnvDev::EnvDev(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EnvDev)
{
    ui->setupUi(this);
}

EnvDev::~EnvDev()
{
    delete ui;
}

