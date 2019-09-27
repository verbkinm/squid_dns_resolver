#include "iostream"
#include "filereader.h"


FileReader::FileReader(std::string file_name)
{
    _file.open(file_name);
    if(!_file)
    {
        std::cerr << "Can't open file \"" << file_name << "\"" << std::endl;
        exit(1);
    }
}

void FileReader::close()
{
    _file.close();
}

bool FileReader::eof()
{
    return _file.eof();
}

std::string &FileReader::next_string()
{
    getline(_file, _current_string);
    return _current_string;
}

std::string &FileReader::current_string()
{
    return _current_string;
}
