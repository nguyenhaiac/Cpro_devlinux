#ifndef SENSOR_H_
#define SENSOR_H_

typedef struct {
    float TempReading;
    float MoistureReading;
} Sensors_t;

void setTemp(float temp);
void setMoist(float moist);
float getTemp();
float getMoist();
#endif // SENSOR_H_
