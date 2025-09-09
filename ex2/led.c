#include "led.h"

LedStatus ledStatus;
int ledErrorFlag = 0;

void LedInit() { ledStatus = LED_NORMAL; }
