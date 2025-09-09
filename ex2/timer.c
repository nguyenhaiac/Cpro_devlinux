#include "timer.h"
#include <time.h>

void start_timer(Timer_t *timer, double interval) {
    timer->start_time = clock();
    timer->interval = interval;
}

int timer_elapsed(Timer_t *timer) {
    double elapsed = (double)(clock() - timer->start_time) / CLOCKS_PER_SEC;
    if (elapsed > timer->interval) {
        timer->start_time = clock();
        return 1;
    }
    return 0;
}
