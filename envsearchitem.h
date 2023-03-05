#ifndef ENVSEARCHITEM_H
#define ENVSEARCHITEM_H

#include "abstractenvobject.h"
#include <QGraphicsItem>
#include <QObject>

class EnvSearchItem : public QObject, public AbstractEnvObject, public  QGraphicsItem
{
    Q_OBJECT
public:
    EnvSearchItem();  ///< Default constructor.
    virtual ~EnvSearchItem(); ///< Destructor.



public:
    virtual envType getType() override; ///< Method shoud return type of object.
    virtual QString getName() override; ///< Method shoud return name of object.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) override;
    QRectF boundingRect() const override;

    void setRect(const QRectF &rect);


    const QString &owner() const;

    qint32 stars() const;

protected:
    bool m_selected; ///< Bool value true if item is selected.

    QPixmap m_image; ///< Image of item.

    static QString m_baseImagePath; ///< Path of image.

    QRectF m_rect;  ///< Rect of item.

    QString m_owner; ///< Owner of container.

    qint32 m_stars; ///< Number of stars.
};

#endif // ENVSEARCHITEM_H
