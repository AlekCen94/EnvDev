#ifndef ENVDEV_H
#define ENVDEV_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EnvDev; }
QT_END_NAMESPACE

class EnvDev : public QMainWindow
{
    Q_OBJECT

public:
    EnvDev(QWidget *parent = nullptr);
    ~EnvDev();

private:
    Ui::EnvDev *ui;
};
#endif // ENVDEV_H
