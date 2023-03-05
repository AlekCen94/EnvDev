#include "envbuilder.h"

EnvBuilder::EnvBuilder()
{

}

EnvBuilder::~EnvBuilder()
{

}

///@brief Virtual method for appending item.
/// @param const QString& item > Item to append.
///
void EnvBuilder::append(const QString &item)
{
    m_content.append(item);
}

QString EnvBuilder::getContent() const
{
    return m_content;
}

QString EnvBuilder::getName() const
{
    return m_name;
}
