#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QString>
#include <QtNetwork/QTcpSocket>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent=0);
    ~Client();
    void start(QString add, quint16 port);
public slots:
    void startTransfer();
private:
    QTcpSocket client;
};

#endif // CLIENT_H
