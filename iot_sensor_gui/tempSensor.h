#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <QWidget>
#include <QLabel>

class TempSensor: public QWidget
{
  Q_OBJECT
  public:
    TempSensor(QWidget *parent=0);

  public slots:
    void temperature_update();
  private:
    QLabel *m_temperature_label;
    QLabel *m_measurement_label;
};

#endif // TEMP_SENSOR_H
