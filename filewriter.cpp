#include "filewriter.h"
#include "iostream"

FileWriter::FileWriter(std::string file_name)
{
    _file.open(file_name, std::ios::app);
    if(!_file)
    {
        std::cerr << "Can't open file \"" << file_name << "\"" << std::endl;
        exit(1);
    }
}

void FileWriter::write_string(const std::string &str)
{
	
    _file << str << "\n";
}

void FileWriter::close()
{
    _file.close();
}
