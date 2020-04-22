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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void handleMeasurementButton();
    void handleMessageButton();
private:
    QPushButton *m_measurement_button;
    QLabel *m_measurement_label;
    QPushButton *m_message_button;
    QLabel *m_message_label;
    QTextEdit *m_message_name;
    QTextEdit *m_message_data;
    QLabel *m_message_response_label;
};

#endif // MAINWINDOW_H
