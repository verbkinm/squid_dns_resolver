#include <iostream>
#include <QCoreApplication>

#include "filereader.h"
#include "filewriter.h"
#include "stringparser.h"
#include "dns_db.h"
#include "dns_resolver.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cerr << "few arguments" << std::endl;
		exit(0);
    }
    QCoreApplication a(argc, argv);

    DNS_DB dns_db;
    FileReader file_reader(argv[1]);
    FileWriter file_writer(argv[2]);

    while(!file_reader.eof())
    {
        StringParser parser(file_reader.next_string());
        std::array<std::string, 3> *parsed_string = parser.get_parsed_string();

        if(!parser.is_correct())
        {
            file_writer.write_string(file_reader.current_string());
            continue;
        }

        if(dns_db.is_present(parsed_string->at(1)))
            parsed_string->at(1) = dns_db.last_request();
        else
        {
            DNS_Resolver dns_resolver;
            QString ip = QString::fromUtf8(parsed_string->at(1).c_str());
            dns_db.add(ip.toLatin1().data(), dns_resolver.lookupServers(ip).toLatin1().data());
            parsed_string->at(1) = dns_db.last_request();
        }
        file_writer.write_string(parsed_string->at(0) + parsed_string->at(1) + parsed_string->at(2));
    }

    file_reader.close();
    file_writer.close();

    std::clog << "Done." << std::endl;

    return a.exec();
}
