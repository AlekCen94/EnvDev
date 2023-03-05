#ifndef ENVCOMMAND_H
#define ENVCOMMAND_H

#include <QProcess>
#include "Types.h"
#include <QStringList>

class EnvCommand: public QProcess
{
public:
    EnvCommand(); ///< Default constructor.
    virtual ~EnvCommand(); ///< Destructor.

    virtual envCommandType getType() = 0; ///< Clear virtual function for returnig a type in concrite class.

    QString getProcessName() const;

    QString getOutput() const;
    void setOutput(const QString &output);

protected:
    QString m_processName; ///< Name of base process.

    QString m_output; ///< Output of command process.
};

#endif // ENVCOMMAND_H
