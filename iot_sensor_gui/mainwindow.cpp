/**
  * This class is based on the example found here:
  * https://wiki.qt.io/How_to_Use_QPushButton
  */

#include "mainwindow.h"

#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the button, make "this" the parent
    m_measurement_button = new QPushButton("Get temperature", this);
    // set size and location of the button
    m_measurement_button->setGeometry(100, 100, 150, 30);

    // Connect button signal to appropriate slot
    connect(m_measurement_button, SIGNAL (released()), this, SLOT (handleMeasurementButton()));

    m_measurement_label = new QLabel("0.0", this);
    m_measurement_label->setGeometry(270, 100, 80, 30);

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
    m_message_response_label->setGeometry(100, 200, 300, 30);
}

void MainWindow::handleMeasurementButton()
{
    m_measurement_label->setNum((float)rand() / (float)RAND_MAX * 20); // get a random float between 0 and 20
}

void MainWindow::handleMessageButton()
{
    m_message_response_label->setText("Message ("
                                      + m_message_name->toPlainText()
                                      + ": "
                                      + m_message_data->toPlainText()
                                      + ") sent!");
}
