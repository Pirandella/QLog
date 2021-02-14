#ifndef _QLOG_H_
#define _QLOG_H_

#include <iostream>
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <map>
#include "fileHandler.h"

enum logType {
    D = 10,     // Debug
    I,          // Information
    W,          // Warning
    E,          // Error
    F           // Fatal
};

enum logLevel {
    NONE,
    ALL,
    DEBUG = D,
    INFO = I,
    WARNING = W,
    ERROR = E,
    FATAL = F,
};

class QLog {
private:
    const std::string TAG;
    const std::string LOG_FILE_NAME = "log.txt";

    logLevel  m_logLevel = ALL;
    bool m_termColor = true;
    static std::map<logType, std::string> m_logLevelsColorsMap;
    static std::map<logType, std::string> m_logTypeCharsMap;
    FileHandler *m_logFile = nullptr;

    std::string logMsgFormat(logType type, std::string logMsg, va_list var_list);

public:
    QLog(std::string tag);
    QLog(std::string tag, bool color);
    ~QLog();

    void setLogLevel(logLevel level);

    void log(logType type, std::string msg, ...);
    void log(const char *msg, ...);
};

#endif /* _QLOG_H_ */