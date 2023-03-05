#include "envtoolwg.h"
#include "ui_envtoolwg.h"
#include "abstractenvobject.h"
#include <QDebug>
QSize EnvToolWg::m_size = QSize(50,50);

EnvToolWg::EnvToolWg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvToolWg)
{
    ui->setupUi(this);
    Initialize();
}

EnvToolWg::~EnvToolWg()
{
    delete ui;
}

///@brief Method for initialization.
///
void EnvToolWg::Initialize()
{
    ui->m_selectButton->setFixedSize(m_size);
    ui->m_selectButton->setText("");
    ui->m_selectButton->setIcon(QIcon(":/icons//icons/select.png"));
    connect(ui->m_selectButton,SIGNAL(toggled(bool)),this,SLOT(selectClicked(bool)));
}

///> Select slot.
void EnvToolWg::selectClicked(bool state)
{
    //emit clickedSelect(state);

    qDebug()<<"Emit state\n";

    AbstractEnvObject::setSelectAllowed(state);
}
