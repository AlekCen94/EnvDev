#include "envdev.h"
#include "ui_envdev.h"
#include "maptable.h"
#include "envcontainerparametarswig.h"
#include "envpropertiesterminalwig.h"
#include "envtoolwg.h"
#include "envcontainersearch.h"

EnvDev::EnvDev(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EnvDev)
{
    ui->setupUi(this);

    Initialize();
}

EnvDev::~EnvDev()
{
    delete ui;
}

///@brief Method for initialization.
///
void EnvDev::Initialize()
{
    m_map = new MapTable(this);
    m_containers = new EnvContainerParametarsWig(this);
    m_properties = new EnvPropertiesTerminalWig(this);
    m_tools = new EnvToolWg(this);
    m_search = new EnvContainerSearch(this);
    m_containers->setMap(m_map);

    setCentralWidget(m_map);

    ui->m_containers->setWidget(m_containers);
    ui->m_containers->setBaseSize(QSize(100,1000));
    ui->m_containers->setFeatures(QDockWidget::NoDockWidgetFeatures);
    ui->m_containers->setFeatures(QDockWidget::DockWidgetClosable);


    ui->m_tools->setWidget(m_tools);
    ui->m_tools->setBaseSize(QSize(100,1000));
    ui->m_tools->setFeatures(QDockWidget::NoDockWidgetFeatures);
    ui->m_tools->setFeatures(QDockWidget::DockWidgetClosable);

    ui->m_properties->setWidget(m_properties);
    ui->m_properties->setBaseSize(QSize(1000,100));
    ui->m_properties->setFeatures(QDockWidget::NoDockWidgetFeatures);
    ui->m_properties->setFeatures(QDockWidget::DockWidgetClosable);
    ui->m_properties->setAllowedAreas(Qt::DockWidgetArea::BottomDockWidgetArea);


}

///@brief Method for saving env.
///
void EnvDev::saveEnv()
{

}


void EnvDev::on_actionSearch_containers_triggered()
{
    m_search->show();
}


void EnvDev::on_actionSave_env_triggered()
{

}

