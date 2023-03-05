#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include "envcommand.h"

class GitCommand : public EnvCommand
{
public:
    GitCommand();
    virtual ~GitCommand();
};

#endif // GITCOMMAND_H
