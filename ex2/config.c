#include "config.h"
#include "actuator.h"

Configuration_t SystemConfig;

void SystemInit() {
    SystemConfig.MaxHumidity = 60;
    SystemConfig.MinHumidity = 50;
    SystemConfig.ReadingInterval = 5;
    SystemConfig.WateringTime = 15;
    SystemConfig.mode = MODE_AUTO;
}
