#include "envdev.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnvDev w;
    w.show();
    return a.exec();
}
