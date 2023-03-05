#include "envfactory.h"
#include "abstractenvobject.h"
#include "envcontainer.h"
#include "envconnect.h"



EnvFactory::EnvFactory()
{

}

///@brief Method create EnvContainer.
/// @param EnvItem* item > Item for creation.
///
EnvContainer *EnvFactory::createContainer(EnvItem *item)
{
    return new EnvContainer(item);
}

///@brief Method create EnvContainer.
/// @param QString& name > Name of container.
///
EnvContainer *EnvFactory::createContainer(const QString &name)
{
    return new EnvContainer(name);
}

///@brief Method create EnvConnect object.
///
EnvConnect *EnvFactory::createConnect()
{
    return new EnvConnect(0);
}



EnvFactory::~EnvFactory()
{

}


