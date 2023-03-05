#ifndef ENVFACTORY_H
#define ENVFACTORY_H

#include <QObject>
#include "Types.h"



class EnvContainer;
class EnvConnect;
class AbstractEnvObject;
class EnvItem;

typedef QVector<QVector<AbstractEnvObject*>> EnvObject;

class EnvFactory
{

public:
   virtual ~EnvFactory(); ///< Destructor.
   EnvFactory();  ///< Default constructor.

public:
///@brief Method create EnvContainer.
/// @param EnvItem* item > Item for creation.
///
EnvContainer* createContainer(EnvItem* item);

///@brief Method create EnvContainer.
/// @param QString& name > Name of container.
///
EnvContainer* createContainer(const QString& name);

///@brief Method create EnvConnect object.
///
EnvConnect* createConnect();


};

#endif // ENVFACTORY_H
