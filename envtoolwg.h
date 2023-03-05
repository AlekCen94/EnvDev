#ifndef ENVTOOLWG_H
#define ENVTOOLWG_H

#include <QWidget>

namespace Ui {
class EnvToolWg;
}

class EnvToolWg : public QWidget
{
    Q_OBJECT

public:
    explicit EnvToolWg(QWidget *parent = nullptr);
    ~EnvToolWg();

public:
    ///@brief Method for initialization.
    ///
    void Initialize();

private:
    Ui::EnvToolWg *ui;

    static QSize m_size;

private slots:
    void selectClicked(bool state); ///> Select slot.

signals:
   void clickedSelect(bool); ///< Signal for select tool in menu.
};

#endif // ENVTOOLWG_H
