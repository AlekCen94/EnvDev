#include "dockerimagebuilder.h"
#include <QDebug>
#include <QFileDialog>



DockerImageBuilder::DockerImageBuilder()
{
    m_name = "Dockerfile";
}

DockerImageBuilder::~DockerImageBuilder()
{

}

///< Function for returnig a type.
envBuilderType DockerImageBuilder::getType()
{
    return envBuilderType::DOCKER_IMAGE;
}

///@brief Method for exporting constructed file.
///
void DockerImageBuilder::exportFile()
{
    QByteArray::fromStdString(m_content.toStdString());
    QFileDialog::saveFileContent(QByteArray::fromStdString(m_content.toStdString()),m_name);
}

///@brief Method for append base image.
/// @param  const QString& imageName > Name of image.
///
void DockerImageBuilder::appendBaseImage(const QString &imageName)
{
    append("FROM =" + imageName + " \n");
}


///@brief Method for append copy command.
/// @param  const QString& hostPath > hostPath.
/// @param  const QString& containerPath > containerPath.
///
void DockerImageBuilder::appendCopy(const QString &hostPath, const QString &containerPath)
{
    append("COPY "+ hostPath+ " "+containerPath +"\n");
}

///@brief Method for append copy command.
/// @param  const QString& key > Key.
/// @param  const QString& value > Value.
///
void DockerImageBuilder::appendLabel(const QString &key, const QString &value)
{
    append("LABEL "+key+"="+value+"\n");
}

///@brief Method for append command.
/// @param  const QString& command > Command.
///
void DockerImageBuilder::appendCommand(const QString &command)
{
    append("RUN "+command+"\n");
}
