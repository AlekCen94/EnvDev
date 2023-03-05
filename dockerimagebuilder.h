#ifndef DOCKERIMAGEBUILDER_H
#define DOCKERIMAGEBUILDER_H

#include "envbuilder.h"


class DockerImageBuilder : public EnvBuilder
{

public:
    DockerImageBuilder();
    virtual ~DockerImageBuilder();
    virtual envBuilderType getType() override;  ///< Function for returnig a type.

    ///@brief Method for exporting constructed file.
    ///
    void exportFile() override;

    ///@brief Method for append base image.
    /// @param  const QString& imageName > Name of image.
    ///
    void appendBaseImage(const QString& imageName);

    ///@brief Method for append copy command.
    /// @param  const QString& hostPath > hostPath.
    /// @param  const QString& containerPath > containerPath.
    ///
    void appendCopy(const QString& hostPath, const QString& containerPath);

    ///@brief Method for append copy command.
    /// @param  const QString& key > Key.
    /// @param  const QString& value > Value.
    ///
    void appendLabel(const QString& key, const QString& value);

    ///@brief Method for append command.
    /// @param  const QString& command > Command.
    ///
    void appendCommand(const QString& command);


};

#endif // DOCKERIMAGEBUILDER_H
