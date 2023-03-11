#ifndef ENVCONTAINER_H
#define ENVCONTAINER_H

#include "abstractenvobject.h"
#include <QGraphicsItem>
#include"dockerimagebuilder.h"
#include <QObject>
#include "EnvFramework/tinyxml/tinyxml.h"
#include <QPropertyAnimation>

class EnvItem;

class EnvContainer : public QObject, public AbstractEnvObject, public  QGraphicsItem
{

    Q_OBJECT

    Q_PROPERTY(QRectF geo READ boundingRect WRITE setRect);


public:
    EnvContainer(QObject* parent);  ///< Default constructor.
    virtual ~EnvContainer(); ///< Destructor.

    ///@brief Constructor with params.
    /// @param QString name > nme of item.
    ///
    EnvContainer(const QString& name);

    ///@brief Constructor with params.
    /// @param EnvItem* item > Item for creation.
    ///
    EnvContainer(EnvItem* item);

public:
   virtual envType getType() override; ///< Method shoud return type of object.
   virtual QString getName() override; ///< Method shoud return name of object.
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget) override;
   QRectF boundingRect() const override;



   void setRect(const QRectF &rect);


protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse press event.
   void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse move event.
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override; ///Mouse release event.

protected:
    QString m_name;  ///< Name of container.

    envType m_type; ///< Type of container.

    QMap<quint64,quint64> m_portMap; ///< Port map.

    QMap<QString,QString>m_valueMap; ///< Value map(folders).

    QMap<QString,QString> m_envVarMap; ///< Env variable map.

    quint64 m_unique; ///< Unique identifier.

    QRectF m_rect;  ///< Rect of container.

    DockerImageBuilder m_imageBuilder; ///< Image Builder object.

    bool m_pressed;  ///< Bool value true if item is pressed.

    bool m_selected; ///< Bool value true if item is selected.

    QPixmap m_image; ///< Image of container.

    static QString m_imagePath; ///< Path of image.

    QPropertyAnimation* m_animation; ///< Animation on drawing container.


};

#endif // ENVCONTAINER_H
