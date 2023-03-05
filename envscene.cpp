#include "envscene.h"
#include "envcontainer.h"
#include "envconnect.h"
#include "envfactory.h"
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include "envfactory.h"
#include <QDebug>
#include <QPainter>

EnvScene::EnvScene()
{
    Initialize();

}

EnvScene::~EnvScene()
{
    delete m_factory;
}
///@brief Method for initialization.
///
void EnvScene::Initialize()
{
    setSceneRect(0,0,200,200);
    m_factory = new EnvFactory();
    m_itemNameForDraw = "";
    m_draw =false;
    m_line = false;
}

///@brief Method return selected item for draw.
///
QString EnvScene::selectedtemForDraw() const
{
    return m_itemNameForDraw;
}

///@brief Method set selected item for draw.
///@param  QString& selectedtemName > selected item name.
///
void EnvScene::setSelectedtemNameForDraw(QString& selectedtemName)
{
    m_itemNameForDraw = selectedtemName;
    qDebug()<<m_itemNameForDraw;
}

///@brief Metfod for removing item.
///@param  AbstractEnvObject* item > item.
///
void EnvScene::removeItem(AbstractEnvObject *item)
{
    if(item->getType() == envType::CONTAINER)
    {
        for (int var = 0; var < m_containersVector.size(); ++var) {
            if(item->getId()== m_containersVector.at(var)->getId()) {
                removeItem(item);
                m_connectVector.removeAt(var);
            }
        }
    }
    else if(item->getType() == envType::CONNECT)
    {
        for (int var = 0; var < m_connectVector.size(); ++var) {
            if(item->getId()== m_connectVector.at(var)->getId()) {
                removeItem(item);
                m_connectVector.removeAt(var);
            }
        }
    }
}

void EnvScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::MouseButton::LeftButton && m_draw && m_itemNameForDraw !="")
    {
        EnvContainer* con = m_factory->createContainer(selectedtemForDraw());
        QPoint tl(mouseEvent->scenePos().x()-50,mouseEvent->scenePos().y()-50);
        QPoint rb(mouseEvent->scenePos().x()+50,mouseEvent->scenePos().y()+50);
        QRectF rect(tl,rb);
        rect.setCoords(tl.rx(),tl.ry(),rb.rx(),rb.ry());
        con->setRect(rect);
        m_containersVector.append(con);
        addItem(con);

    }

    if(mouseEvent->button() == Qt::MouseButton::LeftButton && m_line)
    {
        EnvConnect* line = m_factory->createConnect();
        line->setMouseStartPoint(mouseEvent->scenePos());
        qDebug()<< mouseEvent->scenePos().x();
        //line->setLine(mouseEvent->scenePos().x(),mouseEvent->scenePos().y(),mouseEvent->scenePos().x()+50,mouseEvent->scenePos().y());
        m_connectVector.append(line);
        addItem(line);
    }

    if(mouseEvent->button() == Qt::MouseButton::LeftButton && !m_draw && !m_line && m_delete)
    {
        QPoint tl(mouseEvent->scenePos().x()-50,mouseEvent->scenePos().y()-25);
        QPoint rb(mouseEvent->scenePos().x()+50,mouseEvent->scenePos().y()+25);
        QRectF rect(tl,rb);

    }

    update();
    QGraphicsScene::mousePressEvent(mouseEvent);





}

void EnvScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(!m_connectVector.isEmpty())
        m_connectVector.back()->setMousePoint(mouseEvent->scenePos());
    update();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void EnvScene::drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget)
{
    QPixmap* map = new QPixmap(200,200);
    QPainter *painteb = new QPainter(map);

        for (int i = 0; i < numItems; ++i) {
             // Draw the item
             painteb->save();
             painteb->setTransform(items[i]->sceneTransform(), true);
             items[i]->paint(painteb, &options[i], widget);
             painteb->restore();
             painter->drawPixmap(QRectF(0,0,200,200),*map,QRectF(0,0,200,200));
         }

}

bool EnvScene::getdelete() const
{
    return m_delete;
}

void EnvScene::setDelete(bool mdelete)
{
    m_delete = mdelete;
}

bool EnvScene::line() const
{
    return m_line;
}

void EnvScene::setLine(bool line)
{
    m_line = line;
}

QVector<EnvConnect *> EnvScene::connectVector() const
{
    return m_connectVector;
}

QVector<EnvContainer *> EnvScene::containersVector() const
{
    return m_containersVector;
}

bool EnvScene::draw() const
{
    return m_draw;
}

void EnvScene::setDraw(bool draw)
{
    m_draw = draw;
}
