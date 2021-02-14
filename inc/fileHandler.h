#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstdarg>

class FileHandler {
private:
    static const int BUFFER_SIZE = 512;
    std::fstream m_file;
    char buffer[BUFFER_SIZE];

public:

    FileHandler(std::string filePath, std::ios_base::openmode mode);
    ~FileHandler();

    /*
     * Function eof()
     * Input:
     *      void
     * Return:
     *      Boolean - true if end of file reached. Else false.
     * Description:
     *      Wrapper of eof() function from fstream.
     */
    bool eof();

    /* 
     * Function read()
     * Input:
     *      void
     * Return:
     *      string
     * Desctription:
     *      Reads line from a file.
     */
    std::string read();
    /* 
     * Function read(const char *format, ...)
     * Input:
     *      const char *format - foramted string
     *      var_args - variables
     * Return:
     *      void
     * Description:
     *      Read a line and fills variables acording to format string.
     */
    void read(const char *format, ...);
    /* 
     * Function write(std::string str)
     * Input:
     *      std::string
     * Return:
     *      void
     * Description:
     *      Writes string to a file.
     */
    void write(std::string str);
    /* 
     * Function write(const char *format, ...)
     * Input:
     *      const char *format - format string
     *      var_args - variables
     * Result:
     *      void
     * Description:
     *      Writes formated string to a file. 
     *      Maximum formated string length is 512 bytes.
     */
    void write(const char *format, ...);
    void write(const char *format, va_list vl);
};

#endif /* _FILE_HANDLER_H_ */