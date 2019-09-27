#include <iostream>
#include "dns_db.h"

DNS_DB::DNS_DB()
{

}

bool DNS_DB::is_present(const std::string &ip)
{
    auto it = _db.find(ip);
    if(it == _db.end())
        return false;

    _last_request = it->second;
    return true;
}

void DNS_DB::add(const std::string &ip, const std::string &name)
{
    try
    {
        _db[ip] = name;
        _last_request = name;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::string DNS_DB::last_request() const
{
    return _last_request;
}
