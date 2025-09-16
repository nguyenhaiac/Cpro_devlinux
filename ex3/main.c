#include "main.h"
#include "loglevel.h"

int main() {
    set_log_level(LOG_ALERT);
    init_log("test.log");

    log_message(LOG_DEBUG, "This is a DEBUG message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_INFO, "This is a INFO message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_NOTICE, "This is a NOTICE message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_WARNING, "This is a WARNING message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_ERROR, "This is a ERROR message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_CRITICAL, "This is a CRITICAL message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_ALERT, "This is a ALERT message, in %s:%d", __FILE__,
                __LINE__);
    log_message(LOG_EMERGENCY, "This is a EMERGENCY message, in %s:%d",
                __FILE__, __LINE__);

    LOG(LOG_DEBUG, "This is the second debug with macro");
    LOG(LOG_INFO, "This is the second info with macro");
    LOG(LOG_NOTICE, "This is the second notice with macro");
    LOG(LOG_WARNING, "This is the second wanring with macro");
    LOG(LOG_ALERT, "This is the second alert with macro");
}
