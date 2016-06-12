#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    subtitle_resync::mainwindow w;
    w.show();

    return a.exec();
}
