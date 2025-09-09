#include "actuator.h"
#include "stdio.h"

PumpStatus pumpStatus;

void PumpInit() { pumpStatus = PUMP_OFF; }

void TurnOnPump() {
    if (pumpStatus == PUMP_ON) {
        return;
    } else {
        pumpStatus = PUMP_ON;
        printf("Turned on pump\n");
        return;
    }
}
void TurnOffPump() {
    if (pumpStatus == PUMP_OFF) {
        return;
    } else {
        printf("Turned off pump\n");
        pumpStatus = PUMP_OFF;
        return;
    }
}
