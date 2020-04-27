#include "tempSensor.h"
#include "tmp102.h"

TempSensor::TempSensor(QWidget *parent) : QWidget(parent)
{
    m_temperature_label = new QLabel("temperature:", this);
    m_temperature_label->setGeometry(0, 0, 100, 30);

    m_measurement_label = new QLabel("0.0", this);
    m_measurement_label->setGeometry(170, 0, 80, 30);
}

void TempSensor::temperature_update()
{
    float temperature = TMP102_Read();
    m_measurement_label->setNum(temperature);
}
