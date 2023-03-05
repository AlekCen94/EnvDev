#ifndef MAPTABLE_H
#define MAPTABLE_H

#include <QWidget>
#include <QMouseEvent>
#include "envitem.h"


class EnvScene;


namespace Ui {
class MapTable;
}

class MapTable : public QWidget
{
    Q_OBJECT

public:
    explicit MapTable(QWidget *parent = nullptr); ///< Default constructor.
    virtual ~MapTable();                          ///< Destructor.

    ///@brief Method for initialize.
    ///
    void initialize();

    ///@brief Method return selected item name.
    ///
    QString selectedtemNwme() const;

    ///@brief Method set selected item.
    ///@param  QString* selectedtem > selected item name.
    ///
    void setSelectedtemName(QString selectedtemname);   

    ///@brief Method return scene.
    ///
    EnvScene *scene() const;

private:
    Ui::MapTable *ui;

protected:
    EnvScene* m_scene;  ///< EnvScene object.
    QString m_selectedtemName;  ///< Selected item from list.

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
};

#endif // MAPTABLE_H
