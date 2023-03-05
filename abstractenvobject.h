#ifndef ABSTRACTENVOBJECT_H
#define ABSTRACTENVOBJECT_H

#include <Types.h>
#include <QString>

class AbstractEnvObject
{
public:
    AbstractEnvObject(); ///< Default constructor.
    virtual ~AbstractEnvObject(); ///< Virtual destructor.
    virtual envType getType() = 0; ///< Clear virtual getType function.
    virtual QString getName() = 0; ///< Clear virtual getName function.

    static bool getDeleteAllowed();
    static void setDeleteAllowed(bool deleteAllowed);

    static int getCount();
    static void setCount(int count);

    int getId() const;
    void setId(int id);

    static bool getSelectAllowed();
    static void setSelectAllowed(bool selectAllowed);

protected:
    static bool m_deleteAllowed; ///< Bool value true if delete is allowed.

    static int m_count; ///< Counter of object.

    static bool m_selectAllowed; ///< Bool value true if select is allowed.

    int m_id; ///< Id of object.

};

#endif // ABSTRACTENVOBJECT_H
