#ifndef ENVCONTAINERSEARCH_H
#define ENVCONTAINERSEARCH_H

#include <QDialog>
#include "dockercommand.h"

namespace Ui {
class EnvContainerSearch;
}



class EnvContainerSearch : public QDialog
{
    Q_OBJECT

public:
    explicit EnvContainerSearch(QWidget *parent = nullptr);
    ~EnvContainerSearch();

    const DockerCommand &dockerCommand() const;

protected:
    ///@brief Method for initialization.
    ///
    void Initialize();

    ///@brief Method for parsing search output and map search items.
    ///
    void parseAndMap();

private:
    Ui::EnvContainerSearch *ui;

private slots:
    void search(); ///< Slot for search button click.

    void add(); ///< Slot for adding containers.


protected:
    DockerCommand m_dockerCommand; ///< Dosker comand object.
};

#endif // ENVCONTAINERSEARCH_H
