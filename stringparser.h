#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <string>
#include <array>

class StringParser
{

public:
    StringParser(const std::string &str);

    std::array<std::string, 3> *get_parsed_string();
    bool is_correct();

private:
    bool parse_string();

    bool make_first_part();
    bool make_second_part();

    bool _parse_correct;
    std::string _str;
    std::array<std::string, 3> _parsed_string;

    std::string::size_type _first_part_end, _second_part_end;
};

#endif // STRINGPARSER_H
