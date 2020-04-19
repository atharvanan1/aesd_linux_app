/**
  * This application is based on the example found here:
  * https://wiki.qt.io/How_to_Use_QPushButton
  */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.showNormal();
    mainWindow.setFixedSize(800, 500);
    srand((unsigned) time(0));
    return app.exec();
}
