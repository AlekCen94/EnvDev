#include "envpropertiesterminalwig.h"
#include "ui_envpropertiesterminalwig.h"

EnvPropertiesTerminalWig::EnvPropertiesTerminalWig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvPropertiesTerminalWig)
{
    ui->setupUi(this);
}

EnvPropertiesTerminalWig::~EnvPropertiesTerminalWig()
{
    delete ui;
}
