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

    /* 
     * Function lonMsgFormat(logType type, std::string logMsg, va_list var_list)
     * Input:
     *      type - enum with the log priorities
     *      msg - format log string
     *      var_list - variables
     * Return:
     *      Formated string
     * Description:
     *      Performs log string fomat and returns it to be printed.
     */
    std::string logMsgFormat(logType type, std::string logMsg, va_list var_list);

public:
    QLog(std::string tag);
    QLog(std::string tag, bool color);
    ~QLog();

    /* 
     * Function setLogLevel(logLevel level)
     * Input:
     *      level - loggin level
     * Return:
     *      void
     * Description:
     *      Sets lowest level of logs that will be printed.
     */
    void setLogLevel(logLevel level);
    /* 
     * Function log(logType type, std::string msg, ...)
     * Input:
     *      type - log level type
     *      msg - log format
     *      ... - variables
     * Retrun:
     *      void
     * Description:
     *      Performs logging to console. ("[TAG]  INFO: <msg>")
     */
    void log(logType type, std::string msg, ...);
    /* 
     * Function log(const char *msg, ...)
     * Input:
     *      msg - log format
     *      ... - variables
     * Result:
     *      void
     * Description:
     *      Performs loggin to file.
     */
    void log(const char *msg, ...);
};

#endif /* _QLOG_H_ */