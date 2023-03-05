#include "envcommand.h"

EnvCommand::EnvCommand()
{

}

EnvCommand::~EnvCommand()
{

}

QString EnvCommand::getProcessName() const
{
    return m_processName;
}



QString EnvCommand::getOutput() const
{
    return m_output;
}

void EnvCommand::setOutput(const QString &output)
{
    m_output = output;
}


