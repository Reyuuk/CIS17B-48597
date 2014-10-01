#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();
public slots:
    void acceptConnection();
    void startRead();

private:
    QTcpServer server;
    QTcpSocket *client;

};

#endif // SERVER_H
