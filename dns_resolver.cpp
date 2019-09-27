#include <QCoreApplication>
#include <QHostAddress>

#include "dns_resolver.h"

QString DNS_Resolver::lookupServers(const QString &ip)
{
    if(QHostAddress(ip).isNull())
        return ip;

    _ip = ip;

    disconnect(&dns, SIGNAL(finished()), this, SLOT(handleServers()));
    connect(&dns, SIGNAL(finished()), this, SLOT(handleServers()));

    QString arpa = toArpa(_ip);
    dns.setType(QDnsLookup::ANY);
    dns.setName(arpa);
    dns.lookup();

    while(!dns.isFinished())
        QCoreApplication::processEvents();

    return _name;
}

QString DNS_Resolver::toArpa(const QString &ip)
{
    QStringList list = ip.split('.');
    return list[3] + "." + list[2] + "." + list[1] + "." + list[0] + ".in-addr.arpa";
}

void DNS_Resolver::handleServers()
{
    if(dns.error() != QDnsLookup::NoError)
    {
        QString error = "DNS lookup failed for " + dns.name();
        qWarning("%s", error.toLatin1().data());
        dns.deleteLater();
        _name = _ip;
        return;
    }
	
    auto list = dns.pointerRecords();
    if(list.length())
        _name = dns.pointerRecords().at(0).value();
    else
        _name = _ip;
}
