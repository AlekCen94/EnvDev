#ifndef ENVBUILDER_H
#define ENVBUILDER_H

#include <Types.h>
#include <QString>

class EnvBuilder
{
public:
    EnvBuilder();  ///< Defuit constructor.
    virtual ~EnvBuilder();  ///< Destructor.
    virtual envBuilderType getType() = 0; ///< Clear virtual function for returnig a type in concrite class.

    ///@brief Clear virtual method for exporting constructed file.
    ///
    virtual void exportFile() = 0;

    QString getContent() const;

    QString getName() const;

protected:
    QString m_content; ///< Content of file.

    QString m_name; ///< Name of file.

protected:
    ///@brief Virtual method for appending item.
    /// @param const QString& item > Item to append.
    ///
    virtual void append(const QString& item);


};

#endif // ENVBUILDER_H
