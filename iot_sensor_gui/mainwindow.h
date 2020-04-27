/**
  * This class is based on the example found here:
  * https://wiki.qt.io/How_to_Use_QPushButton
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QTimer>
#include "tempSensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void handleMessageButton();
private:
    QPushButton *m_message_button;
    QLabel *m_message_label;
    QTextEdit *m_message_name;
    QTextEdit *m_message_data;
    QLabel *m_message_response_label;
    QTimer *m_timer;
    TempSensor *m_tempSensor;
};

#endif // MAINWINDOW_H
