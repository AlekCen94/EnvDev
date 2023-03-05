#ifndef DOCKERCOMPOSEBUILDER_H
#define DOCKERCOMPOSEBUILDER_H

#include "envbuilder.h"

class DockerComposeBuilder : public EnvBuilder
{
public:
    DockerComposeBuilder();
    virtual ~DockerComposeBuilder();
};

#endif // DOCKERCOMPOSEBUILDER_H
