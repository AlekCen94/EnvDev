#ifndef ENVITEM_H
#define ENVITEM_H

#include <QListWidgetItem>
#include <QPaintEvent>
#include <QMouseEvent>

class EnvItem : public QListWidgetItem
{

public:
    EnvItem();  ///< Default constructor.
    virtual ~EnvItem(); ///< Destructor.

    ///@brief Constructor with params.
    /// @param QString name > name of item.
    ///
    EnvItem( const QString& name);

    ///@brief Method returm name of item.
    ///
    QString getName();

    ///@brief Method return Unique identifier.
    ///
    qint64 unique();

    ///@brief Method return Size of item..
    ///
    static QSize size();

    ///@brief Method return count of item..
    ///
    static qint64 count();

    ///@brief Method return true if another item is selected.
    ///
    static bool anotherSelected();

    ///@brief Method set true if another item is selected.
    /// @param bool anotherSelected > selected value.
    ///
    static void setAnotherSelected(bool anotherSelected);

    ///@brief Method return true if item is selected.
    ///
    bool selected() const;

    ///@brief Method set true if item is selected.
    /// @param bool selected > selected value.
    ///
    void setSelected(bool selected);

protected:
 //void paintEvent(QPaintEvent* event); ///< Paint event.
 void mousePressEvent(QMouseEvent* event); ///< Click event.

protected:
    QString m_name; ///< Name of item.

    qint64 m_unique; ///< Unique identifier.

    static QSize m_size;     ///< Size of item.

    static qint64 m_count; ///< Number of item.

    bool m_selected;        ///< Indicator for selected item.

    static bool m_anotherSelected; ///< Indicator for another selected item.
};

#endif // ENVITEM_H
