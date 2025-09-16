#ifndef LOGLEVEL_H_
#define LOGLEVEL_H_

#define TIME_LENGTH 20
#define BUFFER_LENGTH 50

void init_log(char *filename);

void close_log();

typedef enum {
    LOG_EMERGENCY,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG,
} LogLevel;

void set_log_level(LogLevel level);

void log_message(LogLevel level, char *fmt, ...);
#endif // LOGLEVEL_H_
