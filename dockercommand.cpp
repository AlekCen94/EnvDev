#include "dockercommand.h"
#include <QDebug>

DockerCommand::DockerCommand()
{
    m_processName = "docker";
}

DockerCommand::~DockerCommand()
{

}
///< Function for returnig a type in concrite class.
envCommandType DockerCommand::getType()
{
    return envCommandType::DOCKER;
}

///@brief Method for execute command help.
///
void DockerCommand::help()
{
    QStringList arguments;
    arguments <<"-h";

    startDetached(m_processName,arguments);
    m_output = readAllStandardOutput();
    qDebug()<<m_output;
}

///@brief Method for execute command search.
/// @param QString image > name of image.
///
void DockerCommand::search(QString image)
{
    QStringList arguments;
    arguments << "search" << image;
    //open();

    start(m_processName,arguments);
    waitForFinished();
    m_output = readAllStandardOutput();
    QStringList list = m_output.split("\n");
    if(!list.isEmpty())
    {
        //QStringList items = list[1].split(" ");

        //qDebug()<<items[0];
    }
}
