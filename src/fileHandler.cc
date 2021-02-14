#include "fileHandler.h"

FileHandler::FileHandler(std::string filePath, std::ios_base::openmode mode)
{
    m_file.open(filePath, mode);
    if (!m_file.is_open())
        throw std::fstream::failure("File Handler");
}

FileHandler::~FileHandler()
{
    m_file.close();
}

bool FileHandler::eof()
{
    return m_file.eof();
}

std::string FileHandler::read()
{
    std::string buffer;
    getline(m_file, buffer);
    return buffer;
}

void FileHandler::read(const char *format, ...)
{
    va_list v_list;
    va_start(v_list, format);
    vsscanf(read().c_str(), format, v_list);
    va_end(v_list);
}

void FileHandler::write(std::string str)
{
    m_file.write(str.c_str(), str.length());
}

void FileHandler::write(const char *format, ...)
{
    std::string str;
    va_list v_list;
    va_start(v_list, format);

    vsnprintf(buffer, BUFFER_SIZE, format, v_list);
    str = buffer;
    write(str);

    va_end(v_list);
}

void FileHandler::write(const char *format, va_list vl)
{
    std::string str;
    vsnprintf(buffer, BUFFER_SIZE, format, vl);
    str = buffer;
    write(str);
}