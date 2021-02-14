#include "QLog.h"
#include "ANSI_color_codes.h"

std::map<logType, std::string> QLog::m_logLevelsColorsMap = {
    {D, WHT},
    {I, YEL},
    {W, HYEL},
    {E, RED},
    {F, HRED}
};
std::map<logType, std::string> QLog::m_logTypeCharsMap = {
    {D, "DEBUG  "},
    {I, "INFO   "},
    {W, "WARNING"},
    {E, "ERROR  "},
    {F, "FATAL  "}
};

QLog::QLog(std::string tag) : TAG(tag) 
{
    m_logFile = new FileHandler(LOG_FILE_NAME, std::ios::out);
}

QLog::QLog(std::string tag, bool color) : QLog(tag)
{
    m_termColor = color;
}

QLog::~QLog()
{
    delete m_logFile;
}

void QLog::setLogLevel(logLevel level)
{
    m_logLevel = level;
}

void QLog::log(logType type, std::string msg, ...)
{
    if (type < static_cast<logType>(m_logLevel) || m_logLevel == NONE)
        return;

    std::string log;
    va_list v_list;
    va_start(v_list, msg);
    log = logMsgFormat(type, msg, v_list);
    va_end(v_list);

    if (m_termColor) {
        log.insert(0, m_logLevelsColorsMap[type]);
        log += RESET_COL;
    }

    std::cout << log;
}

void QLog::log(const char *msg, ...)
{
    va_list v_list;
    va_start(v_list, msg);

    m_logFile->write(msg, v_list);

    va_end(v_list);
}

std::string QLog::logMsgFormat(logType type, std::string logMsg, va_list varList)
{
    std::string log_msg;
    char formatMsg[512];

    log_msg += "[" + TAG + "]\t" + m_logTypeCharsMap[type] + ":  " + logMsg + "\n\0"; 

    vsprintf(formatMsg, log_msg.c_str(), varList);
    log_msg = formatMsg;

    return log_msg;
}