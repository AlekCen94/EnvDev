#ifndef ENVDEV_H
#define ENVDEV_H

#include <QMainWindow>
#include <QPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class EnvDev; }
QT_END_NAMESPACE

class MapTable;
class EnvContainerParametarsWig;
class EnvToolWg;
class EnvPropertiesTerminalWig;
class EnvContainerSearch;


class EnvDev : public QMainWindow
{
    Q_OBJECT

public:
    EnvDev(QWidget *parent = nullptr);  ///< Default constructor.
    virtual ~EnvDev();                  ///< Destructor.

private:
    Ui::EnvDev *ui;

protected:
    QPointer<MapTable> m_map; ///< Table object.
    QPointer<EnvContainerParametarsWig> m_containers; ///< Widget for container list.
    QPointer<EnvToolWg> m_tools; ///< Widget for tools.
    QPointer<EnvPropertiesTerminalWig> m_properties; ///< Widget for properties and terminal.
    QPointer<EnvContainerSearch> m_search; ///< Dialog for search containers.

protected:
    ///@brief Method for initialization.
    ///
    void Initialize();

    ///@brief Method for saving env.
    ///
    void saveEnv();

private slots:
    void on_actionSearch_containers_triggered();
    void on_actionSave_env_triggered();
};
#endif // ENVDEV_H
