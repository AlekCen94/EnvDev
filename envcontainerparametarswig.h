#ifndef ENVCONTAINERPARAMETARSWIG_H
#define ENVCONTAINERPARAMETARSWIG_H

#include <QWidget>
#include "envcontainerprop.h"
#include <QPointer>
#include "EnvFramework/tinyxml/tinyxml.h"

namespace Ui {
class EnvContainerParametarsWig;
}

class EnvItem;
class MapTable;
class QListWidgetItem;


class EnvContainerParametarsWig : public QWidget
{
    Q_OBJECT

public:
    explicit EnvContainerParametarsWig(QWidget *parent = nullptr);  ///< Default constructor.
    virtual ~EnvContainerParametarsWig();  ///< Destructor.

private:
    Ui::EnvContainerParametarsWig *ui;

protected:
    QVector<EnvItem*> m_items;  ///Array of items.

    QPointer<EnvContainerProp> m_propDialog;

    MapTable* m_map;           ///< Pointer to map.

    TiXmlDocument* m_containerDoc;  ///< XML file of containers.

public:

    ///@brief Method for initialize.
    ///
    void initialize();

    ///@brief Method for adding item.
    /// @param QPointer<EnvItem> item > item.
    ///
    void addItem(EnvItem* item);

    ///@brief Method for removing item.
    /// @param QPointer<EnvItem>item > item.
    ///
    void removeItem(EnvItem* item);

    ///@brief Method for searching item by name.
    /// @param QString& name > name of item.
    ///
    EnvItem* getItemByName(QString name);

    ///@brief Method for searching item by unique identifier.
    /// @param quint64& unique > id of item.
    ///
    EnvItem* getItemById(quint64& unique);

    ///@brief Method return selected item.
    ///
    EnvItem* getSelectedItem();

    ///@brief Method clear items.
    ///
    void clear();

    ///@brief Method return map pointer.
    ///
    MapTable *getMap() const;

    ///@brief Method set Map pointer.
    /// @param MapTable *map > Map poinetr.
    ///
    void setMap(MapTable *map);

protected slots:
    void addClick(); ///< Click slot for add button.

    void checkedDraw(bool checked); ///< Slot for checking draw button.

    void checkLine(bool checked); ///< Slot for checking line button.

    void removeClick(); ///< Click slot for remove button.

    void selectEnvItem(QListWidgetItem* item); ///< Slot for select item.

    void checkDelete(bool checked); ///< Slot for checking delete button.

    void saveClick(); ///< Click slot for save button.
};

#endif // ENVCONTAINERPARAMETARSWIG_H
