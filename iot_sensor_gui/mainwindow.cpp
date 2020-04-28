/**
  * This class is based on the example found here:
  * https://wiki.qt.io/How_to_Use_QPushButton
  */

#include "mainwindow.h"
#include "tmp102.h"
#include "tempSensor.h"
#include <QCoreApplication>
#include "azure_driver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_tempSensor = new TempSensor(this);
    m_tempSensor->setGeometry(100, 100, 300, 30);

    // timer help from https://stackoverflow.com/questions/16786109/how-to-call-a-function-periodically-in-qt
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, m_tempSensor, &TempSensor::temperature_update);
    m_timer->start(3000);

    // Create the button, make "this" the parent
    m_message_button = new QPushButton("Send message", this);
    // set size and location of the button
    m_message_button->setGeometry(100, 160, 150, 30);

    // Connect button signal to appropriate slot
    connect(m_message_button, SIGNAL (released()), this, SLOT (handleMessageButton()));

    m_message_name = new QTextEdit("name", this);
    m_message_name->setGeometry(270, 160, 100, 30);

    m_message_data = new QTextEdit("data", this);
    m_message_data->setGeometry(390, 160, 80, 30);

    m_message_response_label = new QLabel(this);
    m_message_response_label->setGeometry(100, 200, 400, 30);
}

void MainWindow::handleMessageButton()
{
    bool result = azure_send_measurement(m_message_name->toPlainText().toLatin1().data(), (m_message_name->toPlainText()).toFloat());
    QString str;
    if (result)
    {
        str = "failed to send!";
    }
    else
    {
        str = "sent!";
    }
    
    m_message_response_label->setText("Message ("
                                      + m_message_name->toPlainText()
                                      + ": "
                                      + m_message_data->toPlainText()
                                      + ") "
                                      + str);
}
