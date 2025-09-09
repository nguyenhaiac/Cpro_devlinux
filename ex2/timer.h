#ifndef TIMER_H_
#define TIMER_H_
#include "time.h"

typedef struct {
    clock_t start_time;
    double interval;
} Timer_t;

int timer_elapsed(Timer_t *timer);
void start_timer(Timer_t *timer, double interval);
#endif // TIMER_H_
