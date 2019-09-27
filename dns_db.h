#ifndef DNS_DB_H
#define DNS_DB_H

#include <map>

class DNS_DB
{
public:
    DNS_DB();

    bool is_present(const std::string &ip);
    void add(const std::string &ip, const std::string &name);
    std::string last_request() const;

private:
    //          ip,         name
    std::map<std::string, std::string> _db;
    std::string _last_request;
};

#endif // DNS_DB_H
