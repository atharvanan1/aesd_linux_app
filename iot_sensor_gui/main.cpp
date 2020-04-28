/**
  * This application is based on the example found here:
  * https://wiki.qt.io/How_to_Use_QPushButton
  */

#include "mainwindow.h"
#include <QApplication>
#include "tmp102.h"
#include <iostream>
#include "azure_driver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.showNormal();
    mainWindow.setFixedSize(800, 500);
    if (TMP102_Init())
    {
      std::cout << "could not initialize tmp102!" << std::endl;
      return -1;
    }
    if (azure_init())
    {
      std::cout << "could not initialize azure driver!" << std::endl;
      return -1;
    }
    return app.exec();
}
