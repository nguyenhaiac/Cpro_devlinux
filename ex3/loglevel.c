#include "loglevel.h"
#include "stdarg.h"
#include "stdio.h"
#include "time.h"

static LogLevel current_log_level = LOG_INFO;
static FILE *log_file = NULL;

void init_log(char *filename) {
    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        perror("fopen error");
        return;
    }
}

void close_log() {
    if (log_file) {
        fclose(log_file);
    }
    log_file = NULL;
}

void set_log_level(LogLevel level) { current_log_level = level; }

void log_message(LogLevel level, char *fmt, ...) {

    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);
    char time_buff[TIME_LENGTH];
    strftime(time_buff, sizeof(time_buff), "%Y:%m:%d %H:%M:%S", local);

    if (level < current_log_level) {
        return;
    }

    char buf[BUFFER_LENGTH];
    char message_buffer[80];

    switch (level) {
    case LOG_EMERGENCY:
        snprintf(buf, sizeof(buf), "[%s] [EMERGENCY] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_ALERT:
        snprintf(buf, sizeof(buf), "[%s] [ALERT] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_CRITICAL:
        snprintf(buf, sizeof(buf), "[%s] [CRITICAL] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_ERROR:
        snprintf(buf, sizeof(buf), "[%s] [ERROR] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_WARNING:
        snprintf(buf, sizeof(buf), "[%s] [WARNING] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_NOTICE:
        snprintf(buf, sizeof(buf), "[%s] [NOTICE] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_INFO:
        snprintf(buf, sizeof(buf), "[%s] [INFO] ", time_buff);
        printf("%s", buf);
        break;
    case LOG_DEBUG:
        snprintf(buf, sizeof(buf), "[%s] [DEBUG] ", time_buff);
        printf("%s", buf);
        break;
    }
    va_list args;
    va_start(args, fmt);
    vsnprintf(message_buffer, sizeof(message_buffer), fmt, args);
    va_end(args);
    printf("%s \n", message_buffer);

    if (log_file) {
        fprintf(log_file, "%s %s\n", buf, message_buffer);
        fflush(log_file);
    }
}
