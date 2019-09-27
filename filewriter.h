#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>

class FileWriter
{
public:
    FileWriter(std::string file_name);

    void write_string(const std::string &str);
    void close();

private:
//    std::string _file_name;
    std::ofstream _file;
};

#endif // FILEWRITER_H
