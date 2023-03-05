#ifndef DOCKERCOMMAND_H
#define DOCKERCOMMAND_H

#include "envcommand.h"

class DockerCommand : public EnvCommand
{
public:
    DockerCommand(); ///< Default constructor.
    virtual ~DockerCommand(); ///< Destructor.

    virtual envCommandType getType() override; ///< Function for returnig a type in concrite class.

    ///@brief Method for execute command help.
    ///
    void help();

    ///@brief Method for execute command search.
    /// @param QString image > name of image.
    ///
    void search(QString image);
};

#endif // DOCKERCOMMAND_H
