#ifndef ENVSCENE_H
#define ENVSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include "envitem.h"

class AbstractEnvObject;
class EnvFactory;
class EnvContainer;
class EnvConnect;

class EnvScene : public QGraphicsScene
{
    Q_OBJECT
public:
    EnvScene();  ///< Default constructor.
    ~EnvScene(); ///< Destructor.

public:
    ///@brief Method for initialization.
    ///
    void Initialize();

    ///@brief Method return selected item for draw.
    ///
    QString selectedtemForDraw() const;

    ///@brief Method set selected item for draw.
    ///@param  QString& selectedtemName > selected item name.
    ///
    void setSelectedtemNameForDraw(QString& selectedtemName);

    ///@brief Metfod for removing item.
    ///@param  AbstractEnvObject* item > item.
    ///
    void removeItem(AbstractEnvObject* item);

    bool draw() const;

    void setDraw(bool draw);

    QVector<EnvContainer *> containersVector() const;

    QVector<EnvConnect *> connectVector() const;

    bool line() const;

    void setLine(bool line);

    bool getdelete() const;
    void setDelete(bool mdelete);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent); ///Mouse move event.

    void drawItems(QPainter *painter, int numItems,
                                 QGraphicsItem *items[],
                                 const QStyleOptionGraphicsItem options[],
                                 QWidget *widget);


protected:
   EnvFactory* m_factory;  ///< Factory object.

   QString m_itemNameForDraw; ///< Name of selected object.

   bool m_draw;  ///< Bool value if drawing is checked.

   bool m_line; ///< Bool value if line is checked.

   bool m_delete; ///< Bool value if delete is checked.

   QVector<EnvContainer*> m_containersVector; ///< Vector of containers.

   QVector<EnvConnect*> m_connectVector; ///< Vector of connections.


};

#endif // ENVSCENE_H
