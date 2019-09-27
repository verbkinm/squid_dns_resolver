#include "stringparser.h"
#include "iostream"

StringParser::StringParser(const std::string &str) : _parse_correct(false), _str(str), _first_part_end(0), _second_part_end(0)
{
    _parse_correct = parse_string();
}

bool StringParser::parse_string()
{
	if(!make_first_part())
        return false;
    if(!make_second_part())
        return false;
    _parsed_string[2] = _str.substr(_second_part_end);;

    return true;
}

std::array<std::string, 3> *StringParser::get_parsed_string()
{
    return &_parsed_string;
}

bool StringParser::is_correct()
{
    return _parse_correct;
}

bool StringParser::make_first_part()
{
    _first_part_end = _str.find("CONNECT ");
    if (_first_part_end == std::string::npos)
        return false;

    _first_part_end += 8; // 8 - длина слова CONNECT + пробел
    _parsed_string[0] = _str.substr(0, _first_part_end);
    return true;
}

bool StringParser::make_second_part()
{
    _second_part_end = _str.find(":443 ");
    if (_second_part_end == std::string::npos)
        return false;

    _parsed_string[1] = _str.substr(_first_part_end, _second_part_end - _first_part_end);
    _second_part_end += 4; // 4 - длина :443 без пробела в конце

    return true;
}
