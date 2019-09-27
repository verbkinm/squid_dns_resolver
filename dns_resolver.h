#ifndef DNS_RESOLVER_H
#define DNS_RESOLVER_H

#include <QDnsLookup>

class DNS_Resolver : QObject
{
    Q_OBJECT
public:
    QString lookupServers(const QString &ip);

private:
    QString toArpa(const QString &ip);

    QDnsLookup dns;
    QString _ip, _name;

public slots:
    void handleServers();
};


#endif // DNS_RESOLVER_H
