#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>

class FileReader
{
public:
    FileReader(std::string file_name);

    void close();
    bool eof();

    std::string &next_string();
    std::string &current_string();

private:
//    std::string _file_name;
    std::ifstream _file;
    std::string _current_string;
};

#endif // FILEREADER_H
