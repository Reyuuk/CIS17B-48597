#include "client.h"

Client::Client(QObject *parent) : QObject(parent){
    connect(&client, SIGNAL(connected()), this, SLOT(startTransfer()));
    //GET signal connected, SLOT it into a notification to mainwindow showing connected status
    //Get signal data SLOT it into the transfer
    //connect(&client, SIGNAL(disconnected()),
}

Client::~Client(){
    client.close();
}

void Client::start(QString add, quint16 port){
    QHostAddress addr(add);
    client.connectToHost(addr, port);
}

void Client::startTransfer(){//const QByteArray &data){
    client.write("Hello, World", 13);
    //client.write(data, sizeof(data+1));
}

