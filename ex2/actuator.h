#ifndef ACTUATOR_H_
#define ACTUATOR_H_

typedef enum { MODE_AUTO = 0, MODE_MANUAL } Mode;

typedef enum { PUMP_OFF = 0, PUMP_ON } PumpStatus;

typedef enum { PUMP_IDLE, PUMP_WATERING } PumpState_t;

void TurnOffPump();
void TurnOnPump();
void PumpInit();
#endif // ACTUATOR_H_
