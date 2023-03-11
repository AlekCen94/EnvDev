#ifndef ENVCONTAINERPROP_H
#define ENVCONTAINERPROP_H

#include <QDialog>

namespace Ui {
class EnvContainerProp;
}

class EnvContainerProp : public QDialog
{
    Q_OBJECT

public:
    explicit EnvContainerProp(QWidget *parent = nullptr);
    ~EnvContainerProp();

    ///@brief Method for initialize.
    ///
    void initialize();

private slots:
    void addPortClicked(); ///< Slot called when addport button clicked.
    void removePortClicked(); ///< Slot called when removeport button clicked.

private:
    Ui::EnvContainerProp *ui;
};

#endif // ENVCONTAINERPROP_H
