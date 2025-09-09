#ifndef CONFIG_H_
#define CONFIG_H_

#include "actuator.h"
typedef struct {
    float MinHumidity;
    float MaxHumidity;
    double WateringTime;
    double ReadingInterval;
    Mode mode;
} Configuration_t;

void SystemInit(void);

#endif // CONFIG_H_
