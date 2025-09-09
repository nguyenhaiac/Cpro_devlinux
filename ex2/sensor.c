#include "sensor.h"
#include <stdlib.h>

static Sensors_t SensorData;

void setTemp(float temp) { SensorData.TempReading = temp; }

void setMoist(float moist) { SensorData.MoistureReading = moist; }

float getTemp() { return SensorData.TempReading; }
float getMoist() { return SensorData.MoistureReading; }
