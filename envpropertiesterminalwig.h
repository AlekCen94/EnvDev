#ifndef ENVPROPERTIESTERMINALWIG_H
#define ENVPROPERTIESTERMINALWIG_H

#include <QWidget>

namespace Ui {
class EnvPropertiesTerminalWig;
}

class EnvPropertiesTerminalWig : public QWidget
{
    Q_OBJECT

public:
    explicit EnvPropertiesTerminalWig(QWidget *parent = nullptr);
    ~EnvPropertiesTerminalWig();

private:
    Ui::EnvPropertiesTerminalWig *ui;
};

#endif // ENVPROPERTIESTERMINALWIG_H
