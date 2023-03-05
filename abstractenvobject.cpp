#include "abstractenvobject.h"

bool AbstractEnvObject::m_deleteAllowed = false;

int AbstractEnvObject::m_count = 0;

bool AbstractEnvObject::m_selectAllowed = false;

AbstractEnvObject::AbstractEnvObject()
{
    m_id = m_count;
    m_count++;

}

AbstractEnvObject::~AbstractEnvObject()
{
    m_count--;
}

bool AbstractEnvObject::getDeleteAllowed()
{
    return m_deleteAllowed;
}

void AbstractEnvObject::setDeleteAllowed(bool deleteAllowed)
{
    m_deleteAllowed = deleteAllowed;
}

int AbstractEnvObject::getCount()
{
    return m_count;
}

void AbstractEnvObject::setCount(int count)
{
    m_count = count;
}

int AbstractEnvObject::getId() const
{
    return m_id;
}

void AbstractEnvObject::setId(int id)
{
    m_id = id;
}

bool AbstractEnvObject::getSelectAllowed()
{
    return m_selectAllowed;
}

void AbstractEnvObject::setSelectAllowed(bool selectAllowed)
{
    m_selectAllowed = selectAllowed;
}
