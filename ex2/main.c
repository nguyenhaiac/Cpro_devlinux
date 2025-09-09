#include "main.h"
#include "actuator.h"
#include "config.h"
#include "led.h"
#include "sensor.h"
#include "stdio.h"
#include "timer.h"
#include <stdlib.h>
#include <time.h>

extern Configuration_t SystemConfig;
extern PumpStatus pumpStatus;
extern LedStatus ledStatus;
extern ledErrorFlag;

Timer_t timer_reading;
Timer_t timer_watering;

PumpState_t pumpstate = PUMP_IDLE;

int main() {
    SystemInit();
    PumpInit();
    printf("Minimum Humidity is: %f\n", SystemConfig.MinHumidity);
    printf("Maximum Humidity is: %f\n", SystemConfig.MaxHumidity);
    printf("Watering time is: %f\n", SystemConfig.WateringTime);
    printf("Reading interval is: %f\n", SystemConfig.ReadingInterval);
    printf("Reading interval is: %i\n", SystemConfig.mode);
    printf("============================================\n");
    setTemp(20.5);
    setMoist(70.5);
    printf("Temperature is: %f\n", getTemp());
    printf("Humidity is : %f\n", getMoist());
    start_timer(&timer_reading, SystemConfig.ReadingInterval);

    while (1) {
        if (timer_elapsed(&timer_reading)) {
            setTemp(RandRange(30, 40));
            setMoist(RandRange(30, 70));
            printf("Temperature is: %f\n", getTemp());
            printf("Humidity is : %f\n", getMoist());
        }

        controlPump();
        controlLed();
    }
    return 0;
}

void controlPump() {
    switch (pumpstate) {
    case PUMP_IDLE:
        if (getMoist() <= SystemConfig.MinHumidity &&
            (pumpStatus == PUMP_OFF)) {
            start_timer(&timer_watering, SystemConfig.WateringTime);
            TurnOnPump();
            pumpstate = PUMP_WATERING;
        }
        break;
    case PUMP_WATERING:
        if ((pumpStatus == PUMP_ON && timer_elapsed(&timer_watering)) ||
            (getMoist() >= SystemConfig.MaxHumidity)) {
            TurnOffPump();
            pumpstate = PUMP_IDLE;
        }
        break;
    default:
        pumpstate = PUMP_IDLE;
        break;
    }
}

void controlLed() {
    switch (ledStatus) {
    case LED_NORMAL:
        if (getMoist() <= SystemConfig.MinHumidity && ledErrorFlag != 0) {
            ledStatus = LED_LOW_MOISTURE;
            printf("LED_LOW_MOISTURE\n");
        }
        if (ledErrorFlag == 0) {
            ledStatus = LED_ERROR;
            printf("LED_ERROR");
        }
        break;
    case LED_LOW_MOISTURE:
        if (pumpStatus == PUMP_ON && ledErrorFlag != 0) {
            printf("LED_WATERING\n");
            ledStatus = LED_WATERING;
        }
        if (ledErrorFlag == 0) {
            ledStatus = LED_ERROR;
            printf("LED_ERROR");
        }
        break;
    case LED_WATERING:
        if (pumpStatus == PUMP_OFF && ledErrorFlag != 0) {
            printf("LED_NORMAL\n");
            ledStatus = LED_NORMAL;
        }
        if (ledErrorFlag == 0) {
            ledStatus = LED_ERROR;
            printf("LED_ERROR");
        }
        break;
    default:
        ledStatus = LED_NORMAL;
        break;
    }
}

double RandRange(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
